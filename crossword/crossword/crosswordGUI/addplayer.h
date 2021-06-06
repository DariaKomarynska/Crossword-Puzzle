#ifndef ADDPLAYER_H
#define ADDPLAYER_H

#include <QDialog>

namespace Ui {
class AddPlayer;
}

class AddPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayer(QWidget *parent = nullptr);
    ~AddPlayer();

private slots:
    void on_cancelBtn_clicked();

    void on_addBtn_clicked();

private:
    Ui::AddPlayer *ui;
};


extern bool used(std::string name);
extern bool validName(std::string name);
extern void addUser(std::string name);

#endif // ADDPLAYER_H
