#ifndef GETDATAWINDOW_H
#define GETDATAWINDOW_H
#include "meteocenter.h"
#include <QDialog>
//#include <QWidget>

namespace Ui {
    class getDataWindow;
}

class getDataWindow : public QDialog {
    Q_OBJECT

    public slots:
        void recieveData(MeteoCenter *mc);

    public:
        explicit getDataWindow(QWidget *parent = nullptr);
        ~getDataWindow();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::getDataWindow *ui;
        MeteoCenter *ps;
        MeteoCenter *mps;
};

#endif // GETDATAWINDOW_H
