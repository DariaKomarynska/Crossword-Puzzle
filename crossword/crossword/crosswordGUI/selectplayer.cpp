#include "selectplayer.h"
#include "ui_selectplayer.h"
#include "../Player.h"
#include "../Game.h"
#include <sstream>
#include <fstream>

selectPlayer::selectPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectPlayer)
{
    ui->setupUi(this);

    std::vector <Player> players = getPlayers();

    for(auto& player : players) {

        QString name =  QString::fromStdString(player.getName());
        ui->playerList->addItem(name);
    }

}

selectPlayer::~selectPlayer()
{
    delete ui;
}

void selectPlayer::on_backBtn_clicked()
{
    emit selectPlayer_closed();
    this->close();
}

void selectPlayer::on_deletePlayerBtn_clicked()
{
    std::vector <Player> players = getPlayers();
    std::vector <Player> new_players;

    QString nameToDelete = ui->playerList->currentItem()->text();

    std::stringstream s;
    ui->playerList->clear();

    for(auto& player : players) {
        QString name =  QString::fromStdString(player.getName());

        if(name != nameToDelete){
            s << player << '\n';
            ui->playerList->addItem(name);
        }
    }
    std::fstream data_file("userData.csv", ios::out);
    data_file << s.str();
    data_file.close();
}

void selectPlayer::on_playBtn_clicked()
{
    if(ui->playerList->selectedItems().size() == 1) {
        QString playerName = ui->playerList->currentItem()->text();
        std::string newNamestr = playerName.toLocal8Bit().constData();

        Player* player = new Player(newNamestr);
        select_crossword_win = new selectCrossword(player);
        connect (select_crossword_win, SIGNAL(logout()), this, SLOT(on_logout()));
        select_crossword_win->setWindowState(Qt::WindowMaximized);
        select_crossword_win->show();
        this->hide();
    }
}

void selectPlayer::on_logout() {
    emit selectPlayer_closed();
    this->close();
}
