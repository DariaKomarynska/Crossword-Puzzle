#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "../Game.h"
#include <QLineEdit>
#include <vector>
#include <QGroupBox>
#include <QTableWidget>

namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(Game *g, QWidget *parent = nullptr);
    ~gameWindow();

private:
    Ui::gameWindow *ui;
    Game *game;
    std::vector <std::vector <QTableWidget*>> fields;
    void setColor(int row, int col, std::string color);
    void no_select();
    void blockCorrectFields();
    void blockField(int row, int col);

signals:
    void game_end();


private slots:
    void on_finishBtn_clicked();
    void on_questionList_itemSelectionChanged();
    void on_checkBtn_clicked();
};
std::vector<int> getQuestions(Crossword& c, std::vector<std::string>* questionList);
extern int getIndexBeforeDot(std::string text);

#endif // GAMEWINDOW_H
