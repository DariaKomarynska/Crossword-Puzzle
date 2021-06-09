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

    std::vector <std::pair<std::string, int>> scoreTable;

    for (auto& p : players) {
        std::pair<std::string, int> pair;
        pair.first = p.getName();
        pair.second = p.getSumOfPoints();
        scoreTable.push_back(pair);
    }

    std::sort(scoreTable.begin(), scoreTable.end(), cmpPairs);
    unsigned index = 1;

    for (auto& record : scoreTable) {
        QString name = QString::fromStdString(record.first);
        QString score = QString::number(record.second);
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

