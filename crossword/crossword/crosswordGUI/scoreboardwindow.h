#ifndef SCOREBOARDWINDOW_H
#define SCOREBOARDWINDOW_H

#include <QWidget>

namespace Ui {
class scoreBoardWindow;
}

class scoreBoardWindow : public QWidget
{
    Q_OBJECT

public:
    explicit scoreBoardWindow(QWidget *parent = nullptr);
    ~scoreBoardWindow();

private slots:
    void on_backBtn_clicked();

private:
    Ui::scoreBoardWindow *ui;

signals:
    void backBtn_clicked();
};

#endif // SCOREBOARDWINDOW_H
