#include "importfromfile.h"
#include "ui_importfromfile.h"
#include <QString>
#include <string>
#include <QMessageBox>
#include <QFileDialog>

ImportFromFile::ImportFromFile(QWidget *parent): QDialog(parent), ui(new Ui::ImportFromFile) {
    ui->setupUi(this);
}

ImportFromFile::~ImportFromFile() {
    delete ui;
}

void ImportFromFile::on_pushButton_clicked() {
    ps = new MeteoCenter(0);
    QString str;
    str = QFileDialog::getOpenFileName();
    std::string pathStr = str.toStdString();
    ps->importFromFile(pathStr);
    *mps = *ps;
    QMessageBox::information(this,"","Данные были импортированы");
}

void ImportFromFile::recData(MeteoCenter *ms){
     mps = ms;
}
