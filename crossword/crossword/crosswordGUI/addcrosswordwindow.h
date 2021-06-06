#ifndef ADDCROSSWORDWINDOW_H
#define ADDCROSSWORDWINDOW_H

#include <QWidget>

namespace Ui {
class addCrosswordWindow;
}

class addCrosswordWindow : public QWidget
{
    Q_OBJECT

public:
    explicit addCrosswordWindow(QWidget *parent = nullptr);
    ~addCrosswordWindow();

private:
    Ui::addCrosswordWindow *ui;
};

#endif // ADDCROSSWORDWINDOW_H
