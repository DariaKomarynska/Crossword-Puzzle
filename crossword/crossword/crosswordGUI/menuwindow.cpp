#include "menuwindow.h"
#include "ui_menuwindow.h"


menuWindow::menuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
}


menuWindow::~menuWindow()
{
    delete ui;
}


void menuWindow::on_newPlayerBtn_clicked()
{
    addplayer_window = new AddPlayer;
    addplayer_window->show();
}


void menuWindow::on_continueBtn_clicked()
{
    select_player_win = new selectPlayer;
    select_player_win->setWindowState(Qt::WindowMaximized);
    connect (select_player_win, SIGNAL(selectPlayer_closed()), this, SLOT(on_backFromSelectPlayer()));
    select_player_win->show();
    this->hide();
}


void menuWindow::on_backFromSelectPlayer() {
    this->show();
}


void menuWindow::on_scoreBoardBtn_clicked()
{
    score_board_win = new scoreBoardWindow;
    score_board_win->setWindowState(Qt::WindowMaximized);
    connect (score_board_win, SIGNAL(backBtn_clicked()), this, SLOT(on_backFromScoreBoard()));
    score_board_win->show();
    this->hide();
}


void menuWindow::on_backFromScoreBoard() {
    this->show();
}

