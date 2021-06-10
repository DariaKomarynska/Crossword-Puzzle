#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QFont>
#include <QString>
#include <QVBoxLayout>


std::vector<int> getQuestions(Crossword& c, std::vector<std::string>* questionList) {
    int q_index = 0;
    int same_index = 0;
    int temp = -1;
    std::vector<int> output_index;
    std::vector <std::string> questions = c.getQuestions();
    std::vector<std::string> horizontal;
    std::vector<std::string> vertical;
    std::vector<std::string>* osptr;
    std::vector<std::vector<int>> same_coords = c.getDoubleCoords();
    horizontal.push_back("Horizontal:");
    vertical.push_back("Vertical:");

    for (auto& question : questions) {
        std::stringstream s;
        int index = same_index / 2;
        if (c.getOrientation(q_index) == "horizontally") {
            osptr = &horizontal;
        }
        else {
            osptr = &vertical;
        }
        if (std::find(same_coords.begin(), same_coords.end(), c.getAllFirstLetterCoords()[q_index - index]) != same_coords.end()) {
            if (temp != -1) {
                output_index.push_back(temp);
                s << temp << ". " << question;
                temp = -1;
            }
            else {
                output_index.push_back(q_index - index + 1);
                s << q_index - index + 1 << ". " << question;
                temp = q_index - index + 1;
            }
            same_index++;
        }
        else {
            output_index.push_back(q_index - index + 1);
            s << q_index - index + 1 << ". " << question;
        }
        std::vector<std::string> ob = *osptr;
        ob.push_back(s.str());
        *osptr = ob;
        q_index++;
    }
    horizontal.insert(horizontal.end(), vertical.begin(), vertical.end());
    *questionList = horizontal;
    return output_index;
}


gameWindow::gameWindow(Game *g, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWindow),
    game(g)
{
    ui->setupUi(this);
    // fill crossword name lable
    QString c_name = QString::fromStdString(game->crossword.getName());
    ui->crosswordNameLbl->setText(c_name);
    // fill player name lable
    QString p_name = QString::fromStdString(game->player.getName());
    ui->playerNameLbl->setText(p_name);

    // fill max score LCD
    ui->maxScoreLCD->display(game->crossword.maxPoints());

    //fill question list
    //std::vector <std::string> questions = game.crossword.getQuestions();

    std::vector<std::string> questions;
    std::vector<int> que_index = getQuestions(game->crossword, &questions);
    for (auto& s : questions) {
        QString questionQString = QString::fromStdString(s);
        ui->questionList->addItem(questionQString);
    }

    //make crossword

    Board board = game->crossword.getBoard();
    int NCol = board.getNOColumns();
    int NRow = board.getNORows();

    ui->gameTable->setColumnCount(NCol);
    ui->gameTable->setRowCount(NRow);
    ui->gameTable->setFrameStyle(0);

    int size = ui->gameTable->columnWidth(0);

    for(int y = 0; y < NRow; y++) {
        std::vector <QTableWidget*> row;
        ui->gameTable->setRowHeight(y, size);

        for(int x = 0; x < NCol; x++) {
            // table field = another table = index + text edit
            QTableWidget *box = new QTableWidget;
            box->setColumnCount(1);
            box->setRowCount(2);
            box->setShowGrid(false);
            box->setFrameStyle(0);
            box->horizontalHeader()->hide();
            box->verticalHeader()->hide();
            box->horizontalHeader()->setStretchLastSection(true);
            box->verticalHeader()->setStretchLastSection(true);


            // index label
            QLabel *indexLbl = new QLabel;
            indexLbl->setObjectName("Index Label");
            indexLbl->setFrameShape(QFrame::Shape::NoFrame);
            indexLbl->setLineWidth(0);
            indexLbl->setAlignment(Qt::AlignBottom);
            indexLbl->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

            // text edit
            QLineEdit *field = new QLineEdit;
            field->setObjectName("Field");
            field->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            field->setFrame(false);
            field->setAlignment(Qt::AlignTop);
            if(board.getValue(y, x) == '#') {
                field->setStyleSheet("QLineEdit { background: rgb(255, 241, 207); border: none;}");
                field->setEnabled(false);
                indexLbl->setStyleSheet(" background: rgb(255, 241, 207); border: none;");

                box->setStyleSheet("background: rgb(255, 241, 207);");

            }
            else {
                field->setStyleSheet(":enabled {color: rgb(255, 255, 255); background: rgb(3, 128, 125);  border: none }");
                field->setStyleSheet(":disabled { color: rgb(251, 110, 181) }");
                indexLbl->setStyleSheet("color: rgb(255, 241, 207); background: rgb(3, 128, 125);  border: none;");

                // set index parameters
                QFont indexfont = indexLbl->font();
                indexfont.setPointSize(12);
                indexLbl->setFont(indexfont);
                //connect (this, SIGNAL(no_select()), field, SLOT(indexLbl->setStyleSheet("background: rgb(115, 150, 40);")));

                // set field parameters
                QFont font = field->font();
                font.setPointSize(20);
                field->setFont(font);
                field->setAlignment(Qt::AlignCenter);

                box->setStyleSheet("background: rgb(3, 128, 125);");
            }
            box->setCellWidget(0, 0, indexLbl);
            box->setCellWidget(1, 0, field);
            row.push_back(box);
            ui->gameTable->setCellWidget(y, x, box);
            ui->gameTable->setStyleSheet("background: rgb(255, 241, 207); gridline-color: rgb(255, 241, 207);");
        }
        fields.push_back(row);
    }

    // put question indexes
    std::vector <std::vector<int>> first_indexes = game->crossword.getAllFirstLetterCoords();
    int i = 0;
    for (auto& coords : first_indexes) {
        int qindex = que_index[i];
        int row = coords.at(0);
        int col = coords.at(1);

        QTableWidget* box = fields.at(row).at(col);
        QLabel* label = box->findChild<QLabel*>("Index Label");
        label->setText(QString::number(qindex));
        i++;
    }


        /*
    for(auto row : board) {
        for(auto field : row) {         // board iterator would be nice
        }
        ...2
    }
    */
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_finishBtn_clicked()
{   
    game->player.newGame();
    emit game_end();
    this->close();
}


void gameWindow::on_questionList_itemSelectionChanged()
{
    no_select();
    if (ui->questionList->selectedItems().size() == 1) {
        QString text = ui->questionList->selectedItems().at(0)->text();
        if(text != "Horizontal:" && text != "Vertical:") {
            int index = getIndexBeforeDot(text.toLocal8Bit().constData()) - 1;
            std::vector <std::vector<int>> ans_fields = game->crossword.getFieldsOfQuestion(index);

            for(auto& pair : ans_fields) {
                setColor(pair.at(0), pair.at(1), "rgb(5,208,201)");
            }
        }
    }
}

int getIndexBeforeDot(std::string text) {
    std::string num_str;
    for(auto &character : text) {
        if(character == '.') break;

        num_str += (character);
    }
    return number(num_str);
}


void gameWindow::no_select(){
    for(unsigned y = 0; y < fields.size(); y++){
        for(unsigned x = 0; x < fields.at(0).size(); x++) {
            if(game->crossword.getBoard().getValue(y, x) != '#')
                setColor(y, x, "rgb(3, 128, 125)");
        }
    }
}


void gameWindow::setColor(int row, int col, std::string color) {
    QTableWidget *box = fields.at(row).at(col);
    QLineEdit *field = box->findChild<QLineEdit *>("Field");
    QLabel *label = box->findChild<QLabel *>("Index Label");

    QString col_qstring = QString::fromStdString(color);

    box->setStyleSheet("background: " + col_qstring + ";");
    field->setStyleSheet("background: " + col_qstring + ";");
    label->setStyleSheet("background: " + col_qstring + ";");
    field->setStyleSheet(":disabled { color: rgb(251, 110, 181) }");
}


void gameWindow::on_checkBtn_clicked()
{
    // fill copy GUI board to game class board
    for(unsigned row = 0; row < fields.size(); row++){
        for(unsigned col = 0; col < fields.at(0).size(); col++) {
            if(game->crossword.getBoard().isSettedUp(row, col)) {
                QTableWidget *box = fields.at(row).at(col);
                QLineEdit *field = box->findChild<QLineEdit *>("Field");

                QString answ = field->text();
                    if (answ.size() > 0) {
                    field->setText(answ.at(0));
                    char answer_char = answ.toStdString().at(0);
                    game->crossword.fillField(row, col, answer_char);
                }
            }

        }
    }
    game->countPoints();
    blockCorrectFields();
    ui->scoreLCD->display(game->player.getPoints());
}


void gameWindow::blockCorrectFields() {
    for (int i = 0; i < game->crossword.getNOQuestions(); i++) {
        if ( game->crossword.isCorrectAnswer(i)) {
            std::vector <std::vector<int>> coords = game->crossword.getFieldsOfQuestion(i);

            for(auto& pair : coords) {
                blockField(pair.at(0), pair.at(1));
            }
        }
    }
}


void gameWindow::blockField(int row, int col) {
     fields.at(row).at(col)->setEnabled(false);
}
