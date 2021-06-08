#include "selectcrossword.h"
#include "ui_selectcrossword.h"
#include "../Crossword.h"
#include "../Game.h"


selectCrossword::selectCrossword(Player &pl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectCrossword), player(pl)
{
    ui->setupUi(this);

    // if(player) {
        QString name = QString::fromStdString(player.getName());
        ui->playerLbl->setText(name);
    // }

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
