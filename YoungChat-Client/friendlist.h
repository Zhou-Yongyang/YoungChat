#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QWidget>
#include <QToolButton>

namespace Ui {
class FriendList;
}

class FriendList : public QWidget
{
    Q_OBJECT

public:
    explicit FriendList(QWidget *parent = nullptr);
    ~FriendList();
    void addFriendFunc(QStringList online, QStringList offline);
    QVector<QToolButton *> vector;
    QVector<QToolButton *> vector2;

private slots:
    void on_pushButton_clicked();

    void on_sendFriendApply_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::FriendList *ui;
};

#endif // FRIENDLIST_H
