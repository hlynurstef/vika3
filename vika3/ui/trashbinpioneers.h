#ifndef TRASHBINPIONEERS_H
#define TRASHBINPIONEERS_H

#include <QDialog>

namespace Ui {
class TrashBinPioneers;
}

class TrashBinPioneers : public QDialog
{
    Q_OBJECT

public:
    explicit TrashBinPioneers(QWidget *parent = 0);
    ~TrashBinPioneers();

private:
    Ui::TrashBinPioneers *ui;
};

#endif // TRASHBINPIONEERS_H
