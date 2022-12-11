#ifndef Detecteur_H
#define Detecteur_H
#include <QDialog>
#include <QByteArray>
#include "arduino.h"
namespace Ui {
class Detecteur;
}

class Detecteur : public QDialog
{
    Q_OBJECT

public:
    explicit Detecteur(QWidget *parent = nullptr);
    ~Detecteur();

    Detecteur(int,int);

    //getters
    int getId();
   int getdetecteur();
    //setters
    void setId(int);
    void setDetecteur(int);

    //fonctionnalites de Base relatives a l'entite Detecteur



private slots:
    void on_pushButton_clicked();

    void on_supprimer_clicked();

 void ChercherFromArduino();
private:
    Ui::Detecteur *ui;
    int id,detecteur;
    arduino A;
    QByteArray d;

};

#endif // Detecteur_H
