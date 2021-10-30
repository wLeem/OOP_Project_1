#ifndef DATAFROMCITY_H
#define DATAFROMCITY_H

#include <QDialog>
#include <meteocenter.h>
#include <QString>
#include <string>
namespace Ui {
    class DataFromCity;
}

class DataFromCity : public QDialog {
    Q_OBJECT

    public slots:
        void rechData(MeteoCenter *ms);

    public:
        explicit DataFromCity(QWidget *parent = nullptr);
        ~DataFromCity();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::DataFromCity *ui;
        MeteoCenter *mpv;
};

#endif // DATAFROMCITY_H
