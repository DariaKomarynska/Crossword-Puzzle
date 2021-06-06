#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow();

private:
    Ui::gameWindow *ui;
};

#endif // GAMEWINDOW_H
