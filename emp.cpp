#include "emp.h"
#include "ui_emp.h"

emp::emp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::emp)
{
    ui->setupUi(this);
}

emp::~emp()
{
    delete ui;
}
