#include "addcrosswordwindow.h"
#include "ui_addcrosswordwindow.h"

addCrosswordWindow::addCrosswordWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addCrosswordWindow)
{
    ui->setupUi(this);
}

addCrosswordWindow::~addCrosswordWindow()
{
    delete ui;
}
