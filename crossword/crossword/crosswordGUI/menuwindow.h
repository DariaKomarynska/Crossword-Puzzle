#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include "addplayer.h"
#include "selectplayer.h"
#include "scoreboardwindow.h"


namespace Ui {
class menuWindow;
}

class menuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

private slots:
    void on_newPlayerBtn_clicked();

    void on_continueBtn_clicked();

    void on_scoreBoardBtn_clicked();

    void on_backFromScoreBoard();

    void on_backFromSelectPlayer();

private:
    Ui::menuWindow *ui;
    AddPlayer *addplayer_window;
    selectPlayer *select_player_win;
    scoreBoardWindow *score_board_win;

};

#endif // MENUWINDOW_H
