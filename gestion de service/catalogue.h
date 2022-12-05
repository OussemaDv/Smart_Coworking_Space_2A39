#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <QDialog>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "materiels.h"

namespace Ui {
class catalogue;
}

class catalogue : public QDialog
{
    Q_OBJECT

public:
    explicit catalogue(QWidget *parent = nullptr);
    ~catalogue();

private slots:
    QSqlQueryModel *  afficherCB();
  //  void on_bcatalogue2_currentTextChanged(const QString &arg1);

private:
    Ui::catalogue *ui;
    Materiels M;

};

#endif // CATALOGUE_H
