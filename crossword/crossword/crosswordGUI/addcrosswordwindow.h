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

signals:
    void closed();

private slots:
    void on_cancelBtn_clicked();

    void on_addBtn_clicked();

private:
    Ui::addCrosswordWindow *ui;
};

extern bool crosswordNameUsed(std::string name);
extern bool validCrosswordName(std::string name);
extern bool validListOfWordsFile(std::string file_name);
extern bool validCrosswordFile(std::string file_name);
extern bool validFileName(std::string file_name);
extern void addCrossword(std::string file_name, std::string name, bool is_list_of_words=false);

#endif // ADDCROSSWORDWINDOW_H
