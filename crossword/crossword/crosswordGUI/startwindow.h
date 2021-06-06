#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include "menuwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_playBtn_clicked();

private:
    Ui::StartWindow *ui;
    menuWindow *menu;
};

#endif // STARTWINDOW_H
