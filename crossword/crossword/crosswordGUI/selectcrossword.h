#ifndef SELECTCROSSWORD_H
#define SELECTCROSSWORD_H

#include <QWidget>
#include "../Player.h"

namespace Ui {
class selectCrossword;
}

class selectCrossword : public QWidget
{
    Q_OBJECT

public:
    explicit selectCrossword(Player* pl, QWidget *parent = nullptr);
    ~selectCrossword();
    Player* player;

private slots:
    void on_logoutBtn_clicked();

private:
    Ui::selectCrossword *ui;

signals:
    void logout();
};

#endif // SELECTCROSSWORD_H
