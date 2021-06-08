#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QFont>
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

    for(auto& question : questions) {
        QString questionQString = QString::fromStdString(question);
        ui->questionList->addItem(questionQString);
    }

    //make crossword

    Board board = game.crossword.getBoard();
    int NCol = board.getNOColumns();
    int NRow = board.getNORows();

    ui->gameTable->setColumnCount(NCol);
    ui->gameTable->setRowCount(NRow);


    int size = ui->gameTable->columnWidth(0);

    for(int y = 0; y < NRow; y++) {
        std::vector <QGroupBox*> row;
        ui->gameTable->setRowHeight(y, size);

        for(int x = 0; x < NCol; x++) {
            // table field <- box = index + text edit
            QGroupBox *box = new QGroupBox;

            // index label
            QLabel *indexLbl = new QLabel;
            indexLbl->setFrameShape(QFrame::Shape::NoFrame);
            indexLbl->setLineWidth(0);
            indexLbl->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

            // text edit
            QLineEdit *field = new QLineEdit;
            field->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            if(board.getValue(y, x) == '#') {
                field->setStyleSheet("QLineEdit { background: rgb(255, 184, 151); border: none;}");
                field->setEnabled(false);
                indexLbl->setStyleSheet(" background: rgb(255, 184, 151); border: none;");

            }
            else {
                field->setStyleSheet("color: rgb(251, 110, 181); background: rgb(3, 128, 125); selection-background-color: rgb(0, 120, 215);  border: none;");
                indexLbl->setStyleSheet("color: rgb(255, 184, 151); background: rgb(3, 128, 125); selection-background-color: rgb(0, 120, 215);  border: none;");
                QFont font = field->font();
                font.setPointSize(20);
                field->setFont(font);
                connect (field, SIGNAL(contentsChanged()), this, SLOT(content_changed(field)));
                field->setAlignment(Qt::AlignCenter);
            }


            // make layout and put to box
            QVBoxLayout *boxLayout = new QVBoxLayout;
            boxLayout->addWidget(indexLbl);
            boxLayout->addWidget(field);
            box->setLayout(boxLayout);

            row.push_back(box);
            ui->gameTable->setCellWidget(y, x, box);
            ui->gameTable->setStyleSheet("background: rgb(255, 184, 151); gridline-color: rgb(255, 184, 151);");
        }
        fields.push_back(row);
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
