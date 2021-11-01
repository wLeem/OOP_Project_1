#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QFileDialog>
#include <showall.h>
#include <datafromcity.h>
#include <meteocenter.h>
#include <getdatawindow.h>
#include <importfromfile.h>
#include <exporttofile.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    protected:
        MeteoCenter *ms;
        bool isEx;

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    signals:
        void sendData(MeteoCenter *mc);

    private slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

    private:
        Ui::MainWindow *ui;
        ShowAll *showAllWindow;
        DataFromCity *dataOneWindow;
        getDataWindow *getNewData;
        ImportFromFile *importWindow;
        ExportToFile *exportWindow;
};
#endif // MAINWINDOW_H
