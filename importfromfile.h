#ifndef IMPORTFROMFILE_H
#define IMPORTFROMFILE_H

#include <QDialog>
#include <meteocenter.h>

namespace Ui {
    class ImportFromFile;
}

class ImportFromFile : public QDialog {
    Q_OBJECT

    public slots:
        void recData(MeteoCenter *mc);


    public:
        explicit ImportFromFile(QWidget *parent = nullptr);
        ~ImportFromFile();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::ImportFromFile *ui;
        MeteoCenter *ps;
        MeteoCenter *mps;
};


#endif // IMPORTFROMFILE_H
