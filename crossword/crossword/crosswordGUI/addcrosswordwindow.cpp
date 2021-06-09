#include "addcrosswordwindow.h"
#include "ui_addcrosswordwindow.h"
#include "../Crossword.h"
#include "QMessageBox"

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

void addCrosswordWindow::on_cancelBtn_clicked()
{
    this->close();
}


void addCrosswordWindow::on_addBtn_clicked()
{
    QString new_name = ui->newCrosswordName->text();
    QString file_name = ui->newCrosswordFile->text();
    if(new_name != "" && file_name != "") {
        std::string new_name_str = new_name.toLocal8Bit().constData();
        std::string file_name_str = file_name.toLocal8Bit().constData();
        if (ui->generateFromListChckB->isChecked() && validListOfWordsFile(file_name_str)) {
            addCrossword(file_name_str, new_name_str, true);
            emit closed();
            this->close();

        }
        else if (validCrosswordName(new_name_str) && validCrosswordFile(file_name_str)) {
            addCrossword(file_name_str, new_name_str);
            emit closed();
            this->close();
        }
        else {
            QMessageBox *warn = new QMessageBox();
            warn->setText("Invalid data.");
            warn->setWindowTitle("Warning");
            warn->show();
        }
    }
    else {
        QMessageBox* warn = new QMessageBox();
        warn->setText("Fill all fields.");
        warn->setWindowTitle("Warning");
        warn->show();
    }
}


bool crosswordNameUsed(std::string name) {
    std::vector <Crossword> cross_vec = getCrosswords();
    for (auto& crossw : cross_vec) {
        if (crossw.getName() == name) {
            return true;
        }
    }
    return false;
}


bool validCrosswordName(std::string name) {
    for (char& c : name) {
        if (c == ',') {
            return false;
        }
    }
    if (crosswordNameUsed(name)) return false;
    return true;
}


bool validFileName(std::string file_name) {
    for(auto &character : file_name) {
        if(character == '*' || character == '?' || character == '*' || character == '>' || character == '<' || character == '|' || character == 34) {
            return false;
        }
    }
    return true;
}


bool validListOfWordsFile(std::string file_name) {
    if (!validFileName(file_name)) return false;
    try {
        Crossword c = Crossword(file_name, "some name", true);
    }
    catch (...) {
        return false;
    }
    return true;
}


bool validCrosswordFile(std::string file_name) {
    if (!validFileName(file_name)) return false;
    try {
        Crossword c = Crossword(file_name);
    }
    catch (...) {
        return false;
    }
    return true;

}


void addCrossword(std::string file_name, std::string name, bool is_list_of_words) {
    if(is_list_of_words) {
        std::ofstream log("crosswordNamesData.txt", std::ios_base::app | std::ios_base::out);
        Crossword c = Crossword(file_name, name, true);
        c.makeCSVFile();
        log << name << ".csv," << name << '\n';
    }
    else {
        std::ofstream log("crosswordNamesData.txt", std::ios_base::app | std::ios_base::out);
        log << file_name << "," << name << '\n';
    }
}
