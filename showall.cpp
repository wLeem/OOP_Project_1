#include "showall.h"
#include "ui_showall.h"
#include <iostream>
#include <string>

ShowAll::ShowAll(QWidget *parent): QDialog(parent), ui(new Ui::ShowAll) {
    ui->setupUi(this);
}

ShowAll::~ShowAll() {
    delete ui;
}

void ShowAll::recData(MeteoCenter *mc){
   int sideLength = mc->getSideLength();
   ui->label->setText("Все станции:\n\n\n");
   for (int i = 0; i < sideLength; i++){
       for(int j = 0; j< sideLength; j++){
            std::string *strArr = mc->getWeatherInPoint(i, j);
            ui->label->setText(ui->label->text() + "Тип: " + QString::fromStdString(strArr[0]) + "\n");
            ui->label->setText(ui->label->text() + "Направление: " + QString::fromStdString(strArr[1]) + "\n");
            ui->label->setText(ui->label->text() + "Скорость: " + QString::fromStdString(strArr[2]) + "\n");
            if (strArr[0] == "2"){
                ui->label->setText(ui->label->text() + "Давление: " + QString::fromStdString(strArr[3]) + "\n");
                ui->label->setText(ui->label->text() + "Температура: " + QString::fromStdString(strArr[4]) + "\n");
            }
            ui->label->setText(ui->label->text()+"\n\n");
       }
   }
}
