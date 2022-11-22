#ifndef TACHE_A_FAIRE_H
#define TACHE_A_FAIRE_H
#include <QMainWindow>
#include <QListView>
#include <QStringListModel>


namespace Ui {
class tache_a_faire;
}

class tache_a_faire : public QMainWindow
{
    Q_OBJECT
public:
    tache_a_faire();


protected slots:
    void onAdd();
    void onRemove();

private:
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;
};

#endif // TACHE_A_FAIRE_H
