#ifndef EACHCHATBOX_H
#define EACHCHATBOX_H

#include <QObject>
#include <QToolButton>

#include "chatdialog.h"

class EachChatBox : public QObject
{
    Q_OBJECT
public:
    explicit EachChatBox(QString name, QObject *parent = nullptr);
public slots:
    void slot_buttonClick();

signals:

public:
    QToolButton* friButton;
    ChatDialog* chatWindow;
    QString contacterName;


};

#endif // EACHCHATBOX_H
