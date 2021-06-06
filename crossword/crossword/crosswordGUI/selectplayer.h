#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H

#include <QWidget>
#include "selectcrossword.h"

namespace Ui {
class selectPlayer;
}

class selectPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit selectPlayer(QWidget *parent = nullptr);
    ~selectPlayer();


private slots:
    void on_backBtn_clicked();

    void on_deletePlayerBtn_clicked();

    void on_playBtn_clicked();

    void on_logout();

private:
    Ui::selectPlayer *ui;
    selectCrossword *select_crossword_win;

signals:
    void selectPlayer_closed();
};

#endif // SELECTPLAYER_H
