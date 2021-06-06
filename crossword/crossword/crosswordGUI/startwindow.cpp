#include "startwindow.h"
#include "ui_startwindow.h"

#include "menuwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
}


StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_playBtn_clicked()
{
    menu = new menuWindow;
    menu->setWindowState(Qt::WindowMaximized);
    menu->show();
    hide();
}

