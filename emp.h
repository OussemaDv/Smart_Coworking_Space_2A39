#ifndef EMP_H
#define EMP_H

#include <QMainWindow>

namespace Ui {
class emp;
}

class emp : public QMainWindow
{
    Q_OBJECT

public:
    explicit emp(QWidget *parent = nullptr);
    ~emp();

private:
    Ui::emp *ui;
};

#endif // EMP_H
