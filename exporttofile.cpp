#include "exporttofile.h"
#include "ui_exporttofile.h"
#include <string>
#include <QMessageBox>

ExportToFile::ExportToFile(QWidget *parent): QDialog(parent), ui(new Ui::ExportToFile) {
    ui->setupUi(this);
}

ExportToFile::~ExportToFile() {
    delete ui;
}

void ExportToFile::on_pushButton_clicked() {
//    QString path = ui->lineEdit->text();
//    std::string pathStr = path.toStdString();
//    ps->exportToFile(pathStr);
    QString str;
    str = QFileDialog::getOpenFileName();
    std::string pathStr = str.toStdString();
    ps->exportToFile(pathStr);
    QMessageBox::information(this,"","Данные были экспортированы!");
}

void ExportToFile::recData(MeteoCenter *ms){
    ps = ms;
}
