#include "mainwindow.h"
#include <iostream>
#include <assert.h>
#include "test.h"
#include "meteocenter.h"
#include <typeinfo>
#include <QtGui>
#include <QtCore>
#include <QApplication>

int main(int argc, char *argv[]) {
    //weatherStationConstructorTest();
    //weatherStationSetGetTest();
    //meteoCenterConstructorTest();
    weatherVaneConstructorTest();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
