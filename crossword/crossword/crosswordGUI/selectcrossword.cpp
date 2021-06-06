#include "selectcrossword.h"
#include "ui_selectcrossword.h"

selectCrossword::selectCrossword( Player * pl, QWidget *parent) :
    QWidget(parent), player(pl),
    ui(new Ui::selectCrossword)
{
    ui->setupUi(this);

    if(player) {
        QString name = QString::fromStdString(player->getName());
        ui->playerLbl->setText(name);
    }
}

selectCrossword::~selectCrossword()
{
    delete ui;
}

void selectCrossword::on_logoutBtn_clicked()
{
    emit logout();
    this->close();
}

