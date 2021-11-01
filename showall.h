#ifndef SHOWALL_H
#define SHOWALL_H

#include <QDialog>
#include "meteocenter.h"
#include <string>
#include <QString>

namespace Ui {
    class ShowAll;
}

class ShowAll : public QDialog {
    Q_OBJECT

    public slots:
        void recData(MeteoCenter *mc);

    public:
        explicit ShowAll(QWidget *parent = nullptr);
        ~ShowAll();

    private:
        Ui::ShowAll *ui;
};

#endif // SHOWALL_H
