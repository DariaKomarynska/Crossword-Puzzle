#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "../Game.h"
#include <QLineEdit>
#include <vector>
#include <QGroupBox>

namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(Game &g, QWidget *parent = nullptr);
    ~gameWindow();

private:
    Ui::gameWindow *ui;
    Game &game;
    std::vector <std::vector <QGroupBox*>> fields;

signals:
    void game_end();

private slots:
    void content_changed(QLineEdit* field);
    void on_finishBtn_clicked();
};

#endif // GAMEWINDOW_H
