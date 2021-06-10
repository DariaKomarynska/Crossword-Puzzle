#include "selectplayer.h"
#include "ui_selectplayer.h"
#include "../Game.h"
#include <sstream>
#include <fstream>

selectPlayer::selectPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectPlayer)
{
    ui->setupUi(this);

    this->players = getPlayers();

    for(auto& player : players) {
        QString name =  QString::fromStdString(player.getName());
        ui->playerList->addItem(name);
    }
}

selectPlayer::~selectPlayer()
{
    players.clear();
    delete ui;
}

void selectPlayer::on_backBtn_clicked()
{
    emit selectPlayer_closed();
    this->close();
}

void selectPlayer::on_deletePlayerBtn_clicked()
{
    QString nameToDelete = ui->playerList->currentItem()->text();

    std::stringstream s;
    ui->playerList->clear();

    int index = 0;
    for(auto& player : players) {
        QString name =  QString::fromStdString(player.getName());

        if(name != nameToDelete){
            s << player << '\n';
            ui->playerList->addItem(name);
        }
        else {
            players.erase(players.begin() + index);
        }
        index++;
    }
    std::fstream data_file("userData.csv", ios::out);
    data_file << s.str();
    data_file.close();
}

void selectPlayer::on_playBtn_clicked()
{
    if(ui->playerList->selectedItems().size() == 1) {
        QString playerName = ui->playerList->currentItem()->text();
        std::string nameStr = playerName.toLocal8Bit().constData();

        for(auto& player : players) {
            if(player.getName() == nameStr) {
                select_crossword_win = new selectCrossword(player);
                connect (select_crossword_win, SIGNAL(logout()), this, SLOT(on_logout()));
                select_crossword_win->setWindowState(Qt::WindowMaximized);
                select_crossword_win->show();
                this->hide();
                break;
            }
        }
    }
}

void selectPlayer::on_logout() {
    saveUserData(players);
    emit selectPlayer_closed();
    this->close();
}
