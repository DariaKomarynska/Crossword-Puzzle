#ifndef SELECTCROSSWORD_H
#define SELECTCROSSWORD_H

#include <QWidget>
#include "../Player.h"
#include "../Crossword.h"
#include "../Game.h"
#include "gamewindow.h"

namespace Ui {
class selectCrossword;
}

class selectCrossword : public QWidget
{
    Q_OBJECT

public:
    explicit selectCrossword(Player &pl, QWidget *parent = nullptr);
    ~selectCrossword();

private slots:
    void on_logoutBtn_clicked();

    void on_playBtn_clicked();

    void on_game_end();

private:
    Ui::selectCrossword *ui;
    gameWindow *game_win;
    Player &player;
    std::vector <Crossword> crosswords;
    Game *game;

signals:
    void logout();
};

#endif // SELECTCROSSWORD_H
