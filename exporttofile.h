#ifndef EXPORTTOFILE_H
#define EXPORTTOFILE_H

#include <QDialog>
#include <QFileDialog>
#include <meteocenter.h>

namespace Ui {
    class ExportToFile;
}

class ExportToFile : public QDialog {
    Q_OBJECT

    public slots:
        void recData(MeteoCenter *ms);
    public:
        explicit ExportToFile(QWidget *parent = nullptr);
        ~ExportToFile();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::ExportToFile *ui;
        MeteoCenter *ps;
};

#endif // EXPORTTOFILE_H
