#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include "webaxwidget.h"
namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

private:
    Ui::Map *ui;
};

#endif // MAP_H
