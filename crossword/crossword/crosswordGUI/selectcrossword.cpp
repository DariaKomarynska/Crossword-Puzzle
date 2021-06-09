#include "selectcrossword.h"
#include "ui_selectcrossword.h"
#include "../Crossword.h"
#include "../Game.h"

selectCrossword::selectCrossword(Player &pl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectCrossword), player(pl)
{
    ui->setupUi(this);

    QString name = QString::fromStdString(player.getName());
    ui->playerLbl->setText(name);

    crosswords = getCrosswords();

    for(Crossword& cross : crosswords) {

        QString name =  QString::fromStdString(cross.getName());
        ui->crosswordList->addItem(name);
    }
}

selectCrossword::~selectCrossword()
{
    delete ui;
}

void selectCrossword::on_logoutBtn_clicked()
{
    emit logout();
    this->close();
}


void selectCrossword::on_playBtn_clicked()
{
    if(ui->crosswordList->selectedItems().size() == 1) {
        QString crosswordName = ui->crosswordList->currentItem()->text();
        std::string newNamestr = crosswordName.toLocal8Bit().constData();

        for(auto& c : crosswords) {
            if (c.getName() == newNamestr) {
                game = new Game(player, c); /// player is not ref type in game
                game_win = new gameWindow(*game);
                connect (game_win, SIGNAL(game_end()), this, SLOT(on_game_end()));
                game_win->setWindowState(Qt::WindowMaximized);
                game_win->show();
                this->hide();
                break;
            }
        }
    }
}



void selectCrossword::on_game_end() {
    this->show();
}




void selectCrossword::on_addCrosswordBtn_clicked()
{
    addCrossword_win = new addCrosswordWindow;
    connect (addCrossword_win, SIGNAL(closed()), this, SLOT(reset_list()));
    addCrossword_win->show();
}


void selectCrossword::reset_list() {

    crosswords = getCrosswords();
    ui->crosswordList->clear();

    for(Crossword& cross : crosswords) {

        QString name =  QString::fromStdString(cross.getName());
        ui->crosswordList->addItem(name);
    }

}


void selectCrossword::on_deleteCrosswordBtn_clicked()
{
    QString nameToDelete = ui->crosswordList->currentItem()->text();

    std::stringstream s;
    ui->crosswordList->clear();

    for(auto& crosswordN : crosswords) {
        QString name =  QString::fromStdString(crosswordN.getName());

        if(name != nameToDelete){
            s << crosswordN.getName() << '\n';
            ui->crosswordList->addItem(name);
        }
    }
    std::fstream data_file("crosswordNamesData.txt", ios::out);
    data_file << s.str();
    data_file.close();
}

