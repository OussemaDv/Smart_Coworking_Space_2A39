#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include "smtp.h"
#include "Fournisseur.h"
#include<QSqlQuery>
#include <QSqlDatabase>
dialog::dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    ui->comboBoxEMAIL->setModel(s.afficherCB());
    //
    connect(ui->send, SIGNAL(clicked()),this, SLOT(sendMail()));
    ui->le_password->setEchoMode(QLineEdit::Password);
}

dialog::~dialog()
{
    delete ui;
}







void dialog::sendMail()
{
    QString to = ui->le_to->text();
    QString from = ui->le_email2->text();
    QString subject = ui->le_subject->text();
    QString password =ui->le_password->text();
    QString email_text = ui->le_text->toPlainText();
   Smtp* smtp = new Smtp(from, password, "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


       smtp->sendMail(from, to, subject, email_text);
       QMessageBox::information(nullptr, QObject::tr("mail sent"),
                   QObject::tr(""
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
  /*  ui->le_to->clear();
    ui->le_email2->clear();
    ui->le_subject->clear();
    ui->le_text->clear();
    ui->le_password->clear();*/
}




void dialog::on_comboBoxEMAIL_activated(const QString &arg1)
{
    int ID_PASS=ui->comboBoxEMAIL->currentText().toInt();
       QString id_string=QString::number(ID_PASS);
       QSqlQuery query;
       query.prepare("SELECT * FROM FOURNISSEUR WHERE ID='"+id_string+"'");
       if (query.exec())

           while(query.next())
           { ui->le_to->setText(query.value(2).toString());}
               else

           QMessageBox::critical(nullptr, QObject::tr("not OK"),
                       QObject::tr("failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}
