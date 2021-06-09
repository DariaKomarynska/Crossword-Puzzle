#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QFont>
#include <QString>
#include <QVBoxLayout>


gameWindow::gameWindow(Game &g, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWindow),
    game(g)
{
    ui->setupUi(this);
    // fill crossword name lable
    QString c_name = QString::fromStdString(game.crossword.getName());
    ui->crosswordNameLbl->setText(c_name);
    //fill player name lable
    QString p_name = QString::fromStdString(game.player.getName());
    ui->playerNameLbl->setText(p_name);

    // fill max score LCD
    ui->maxScoreLCD->display(game.crossword.maxPoints());

    //fill question list
    std::vector <std::string> questions = game.crossword.getQuestions();

    int q_index = 1;
    for(auto& question : questions) {
        std::stringstream s;
        s << q_index << ". " << question;
        QString questionQString = QString::fromStdString(s.str());
        ui->questionList->addItem(questionQString);
        q_index++;
    }

    //make crossword

    Board board = game.crossword.getBoard();
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
                field->setStyleSheet("color: rgb(255, 255, 255); background: rgb(3, 128, 125);  border: none;");
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
                connect (field, SIGNAL(field->editingFinished()), this, SLOT(content_changed(field)));
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
    std::vector <std::vector<int>> first_indexes = game.crossword.getAllFirstLetterCoords();
    int qindex = 1;
    for (auto& coords : first_indexes) {
        int row = coords.at(0);
        int col = coords.at(1);

        QTableWidget *box = fields.at(row).at(col);
        QLabel *label = box->findChild<QLabel *>("Index Label");
        label->setText(QString::number(qindex));
        qindex++;
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
    game.player.resetPoints();
    emit game_end();
    this->close();
}

void gameWindow::content_changed(QLineEdit *field) {
    QString content = field->text();
    if(content.size() > 1) {
        field->setText(content[0]);
    }
}


void gameWindow::on_questionList_itemSelectionChanged()
{
    no_select();
    if (ui->questionList->selectedItems().size() == 1) {
        int index = ui->questionList->currentRow();
        std::vector <std::vector<int>> ans_fields = game.crossword.getFieldsOfQuestion(index);

        for(auto& pair : ans_fields) {
            setColor(pair.at(0), pair.at(1), "rgb(5,208,201)");
        }
    }
}


void gameWindow::no_select(){
    for(unsigned y = 0; y < fields.size(); y++){
        for(unsigned x = 0; x < fields.at(0).size(); x++) {
            if(game.crossword.getBoard().getValue(y, x) != '#')
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
}

