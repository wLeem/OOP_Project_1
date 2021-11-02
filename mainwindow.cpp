#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    isEx = false;
    ms = new MeteoCenter(0);
    getNewData = new getDataWindow();
    connect(this, SIGNAL(sendData(MeteoCenter*)), getNewData, SLOT(recieveData(MeteoCenter*)));

    dataOneWindow = new DataFromCity();
    connect(this, SIGNAL(sendData(MeteoCenter*)),dataOneWindow,SLOT(rechData(MeteoCenter*)));

    showAllWindow = new ShowAll();
    connect(this, SIGNAL(sendData(MeteoCenter*)), showAllWindow, SLOT(recData(MeteoCenter*)));

    importWindow = new ImportFromFile();
    connect(this, SIGNAL(sendData(MeteoCenter*)), importWindow, SLOT(recData(MeteoCenter*)));

    exportWindow = new ExportToFile();
    connect(this,SIGNAL(sendData(MeteoCenter*)), exportWindow, SLOT(recData(MeteoCenter*)));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    isEx = true;
    emit sendData(this->ms);
    getNewData->setModal(true);
    getNewData->setWindowTitle("Генерация новых данных");
    getNewData->show();

}

void MainWindow::on_pushButton_2_clicked() {
    if (isEx){
        emit sendData(this->ms);
        showAllWindow->setModal(true);
        showAllWindow->setWindowTitle("Получение данных со всего королевства");
        showAllWindow->show();
    }
    else{
        QMessageBox::warning(this,"Ошибка","Нет данных чтобы обращаться к ним");
    }
}

void MainWindow::on_pushButton_3_clicked() {
    if (isEx){
        emit sendData(this->ms);
        dataOneWindow->setModal(true);
        dataOneWindow->setWindowTitle("Получение данных с города");
        dataOneWindow->show();
    }
    else{
        QMessageBox::warning(this, "Ошибка","Нет данных чтобы обращаться к ним");
    }
}

void MainWindow::on_pushButton_4_clicked() {
    isEx = true;
    emit sendData(this->ms);
    importWindow->setModal(true);
    importWindow->setWindowTitle("Импортирование");
    importWindow->show();
}

void MainWindow::on_pushButton_5_clicked() {
    if (isEx){
        emit sendData(this->ms);
        exportWindow->setModal(true);
        exportWindow->setWindowTitle("Импортирование");
        exportWindow->show();
    }
    else{
        QMessageBox::warning(this,"Ошибка","Нет данных чтобы обращаться к ним");
    }
}

void MainWindow::on_pushButton_6_clicked() {
    if (ms->getCountEl() == 0){
        QMessageBox::warning(this,"Ошибка","Нет данных чтобы обращаться к ним");
    }
    else{
        isEx = false;
        ms->deleteAll();
        ms = new MeteoCenter(0);
        QMessageBox::information(this,"","Удалены все старые данные");
    }
}

