#ifndef SELECTCROSSWORD_H
#define SELECTCROSSWORD_H

#include <QWidget>
#include "../Player.h"
#include "../Crossword.h"
#include "../Game.h"
#include "gamewindow.h"
#include "addcrosswordwindow.h"


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

    void on_deletaCrosswordBtn_clicked();

    void on_addCrosswordBtn_clicked();

    void reset_list();

    void on_deleteCrosswordBtn_clicked();

    void on_deleteBtn_clicked();

private:
    Ui::selectCrossword *ui;
    gameWindow *game_win;
    addCrosswordWindow *addCrossword_win;
    Player &player;
    std::vector <Crossword> crosswords;
    Game *game;

signals:
    void logout();
};

#endif // SELECTCROSSWORD_H
