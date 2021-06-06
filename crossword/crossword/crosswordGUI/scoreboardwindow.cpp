#include "scoreboardwindow.h"
#include "ui_scoreboardwindow.h"
#include "../Game.h"
#include "../Player.h"
#include <vector>

scoreBoardWindow::scoreBoardWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scoreBoardWindow)
{
    ui->setupUi(this);

    std::vector <Player> players = getPlayers();

    int index = 1;
    for(auto& player : players) {
        QString name =  QString::fromStdString(player.getName());
        QString score =  QString::number(player.getScore());
        QString idx = QString::number(index);

        ui->indexList->addItem(idx);
        ui->playerList->addItem(name);
        ui->scoreList->addItem(score);

        index++;
    }
}


scoreBoardWindow::~scoreBoardWindow()
{
    delete ui;
}


void scoreBoardWindow::on_backBtn_clicked()
{
    emit backBtn_clicked();
    this->close();
}

