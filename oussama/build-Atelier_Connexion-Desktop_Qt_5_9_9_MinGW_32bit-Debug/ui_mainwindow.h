/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QToolBox *toolBox;
    QWidget *page;
    QLineEdit *le_id;
    QLineEdit *le_nb;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pb_ajouter;
    QLineEdit *le_bloc;
    QWidget *page_2;
    QLineEdit *le_id_modifier;
    QLabel *label_4;
    QPushButton *pb_modifier;
    QLineEdit *le_nb_modifier;
    QLineEdit *le_bloc_modifier;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *page_3;
    QTableView *tableView;
    QWidget *page_4;
    QPushButton *pb_supprimer;
    QLineEdit *le_supprimer;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 423);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 210, 75, 23));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(60, 30, 571, 331));
        toolBox->setCursor(QCursor(Qt::ArrowCursor));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 571, 219));
        le_id = new QLineEdit(page);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(230, 10, 113, 20));
        le_nb = new QLineEdit(page);
        le_nb->setObjectName(QStringLiteral("le_nb"));
        le_nb->setGeometry(QRect(230, 70, 113, 20));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 47, 14));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 70, 101, 16));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 140, 47, 14));
        pb_ajouter = new QPushButton(page);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(410, 90, 75, 23));
        pb_ajouter->setCursor(QCursor(Qt::PointingHandCursor));
        le_bloc = new QLineEdit(page);
        le_bloc->setObjectName(QStringLiteral("le_bloc"));
        le_bloc->setGeometry(QRect(230, 140, 113, 20));
        toolBox->addItem(page, QStringLiteral("Ajouter un espace"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 571, 219));
        le_id_modifier = new QLineEdit(page_2);
        le_id_modifier->setObjectName(QStringLiteral("le_id_modifier"));
        le_id_modifier->setGeometry(QRect(240, 30, 113, 20));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 30, 47, 14));
        pb_modifier = new QPushButton(page_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(430, 100, 75, 23));
        pb_modifier->setCursor(QCursor(Qt::PointingHandCursor));
        le_nb_modifier = new QLineEdit(page_2);
        le_nb_modifier->setObjectName(QStringLiteral("le_nb_modifier"));
        le_nb_modifier->setGeometry(QRect(240, 80, 113, 20));
        le_bloc_modifier = new QLineEdit(page_2);
        le_bloc_modifier->setObjectName(QStringLiteral("le_bloc_modifier"));
        le_bloc_modifier->setGeometry(QRect(240, 130, 113, 20));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 80, 151, 20));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 130, 81, 16));
        toolBox->addItem(page_2, QStringLiteral("Modifier un espace"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 571, 219));
        tableView = new QTableView(page_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 0, 551, 211));
        toolBox->addItem(page_3, QStringLiteral("Afficher l'ensemble des espaces"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 571, 219));
        pb_supprimer = new QPushButton(page_4);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(400, 80, 75, 23));
        pb_supprimer->setCursor(QCursor(Qt::PointingHandCursor));
        le_supprimer = new QLineEdit(page_4);
        le_supprimer->setObjectName(QStringLiteral("le_supprimer"));
        le_supprimer->setGeometry(QRect(220, 30, 113, 20));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 30, 47, 14));
        toolBox->addItem(page_4, QStringLiteral("Supprimer un espace"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nombre de place", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Bloc", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Ajouter un espace", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Nouveau nombre de places", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Nouveau bloc", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Modifier un espace", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MainWindow", "Afficher l'ensemble des espaces", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("MainWindow", "Supprimer un espace", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
