#include "datafromcity.h"
#include "ui_datafromcity.h"
#include <QMessageBox>

DataFromCity::DataFromCity(QWidget *parent): QDialog(parent), ui(new Ui::DataFromCity) {
    ui->setupUi(this);
}

DataFromCity::~DataFromCity() {
    delete ui;
}

void DataFromCity::rechData(MeteoCenter *ms){
    mpv = ms;
}

void DataFromCity::on_pushButton_clicked() {
    int row = ui->spinBox->value();
    int column = ui->spinBox_2->value();
    ui->label_3->clear();
    if (row < mpv->getSideLength() && column <mpv->getSideLength()){
        std::string *strArr = mpv->getWeatherInPoint(row,column);
         ui->label_3->setText(ui->label_3->text() + "Тип: " + QString::fromStdString(strArr[0]) + "\n");
         ui->label_3->setText(ui->label_3->text() + "Направление: " + QString::fromStdString(strArr[1]) + "\n");
         ui->label_3->setText(ui->label_3->text() + "Скорость: " + QString::fromStdString(strArr[2]) + "\n");
         if (strArr[0] == "2"){
             ui->label_3->setText(ui->label_3->text() + "Давление: " + QString::fromStdString(strArr[3]) + "\n");
             ui->label_3->setText(ui->label_3->text() + "Температура: " + QString::fromStdString(strArr[4]) + "\n\n");
         }
    }
    else{
        QMessageBox::warning(this,"Ошибка","Нет таких координат!");
    }
}

