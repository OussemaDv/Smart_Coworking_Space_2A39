#ifndef DIALOG_H
#define DIALOG_H
#include "Fournisseur.h"
#include <QMainWindow>

namespace Ui {
class dialog;
}

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private slots:


    void sendMail();
    void mailSent(QString);




    void on_comboBoxEMAIL_activated(const QString &arg1);

private:
    Ui::dialog *ui;
Fournisseur s;


    };
#endif // DIALOG_H
