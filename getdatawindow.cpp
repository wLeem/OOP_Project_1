#include "getdatawindow.h"
#include "ui_getdatawindow.h"
#include <QMessageBox>
#include <iostream>
//using namespace std;

getDataWindow::getDataWindow(QWidget *parent): QDialog(parent), ui(new Ui::getDataWindow) {
        ui->setupUi(this);
}

getDataWindow::~getDataWindow() {
    delete ui;
}

void getDataWindow::on_pushButton_clicked() {
   if (ui->spinBox->value() > 0){
       ps = new MeteoCenter(ui->spinBox->value());
       *mps = *ps;
       QMessageBox::information(this,"","Новые данные получены");
   }
   else
       QMessageBox::warning(this,"Ошибка","Матрица не может быть с размером 0x0");
}

void getDataWindow::recieveData(MeteoCenter *mc){
    mps = mc;
}
