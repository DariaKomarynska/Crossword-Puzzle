#include "addplayer.h"
#include "ui_addplayer.h"
#include <QMessageBox>
#include "../Game.h"
#include "../Player.h"
#include <vector>

AddPlayer::AddPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlayer)
{
    ui->setupUi(this);
}

AddPlayer::~AddPlayer()
{
    delete ui;
}

void AddPlayer::on_cancelBtn_clicked()
{
    this->close();
}


void AddPlayer::on_addBtn_clicked()
{
    QString newName = ui->newPlayerName->text();
    if(newName != "") {
        std::string newNamestr = newName.toLocal8Bit().constData();
        if (validName(newNamestr)) {
            addUser(newNamestr);
            this->close();
        }
        else {
            QMessageBox* warn = new QMessageBox();
            warn->setText("Player with this name already exists.");
            warn->setWindowTitle("Warning");
            warn->show();
        }
    }
    else {
        QMessageBox* warn = new QMessageBox();
        warn->setText("Name cannot be empty.");
        warn->setWindowTitle("Warning");
        warn->show();
    }
}

extern std::vector <Player> getPlayers();

bool used(std::string name) {
    std::vector <Player> players = getPlayers();
    for (auto& player : players) {
        if (player.getName() == name) {
            return true;
        }
    }
    return false;
}

bool validName(std::string name) {
    for (char& c : name) {
        if (c == ',') {
            return false;
        }
    }
    if (used(name)) return false;
    return true;
}

void addUser(std::string name) {
    std::ofstream log("userData.csv", std::ios_base::app | std::ios_base::out);
    log << name << '\n';
}

