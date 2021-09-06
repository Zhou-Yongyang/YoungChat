#include "eachchatbox.h"
#include <QDebug>

EachChatBox::EachChatBox(QString name, QObject *parent) : QObject(parent)
{
    qDebug() << "EachChatBox";
    friButton = new QToolButton();
    chatWindow = new ChatDialog();
    contacterName = name;
    connect(friButton, &QToolButton::clicked, this, &EachChatBox::slot_buttonClick);
}

void EachChatBox::slot_buttonClick()
{
    qDebug() << "打开好友聊天框";
    //是否要判断 窗口是否已开？
    friButton->setStyleSheet("QToolButton{background-color: rgb(225, 225, 225, 80);}");
    chatWindow->getLabel()->setText(contacterName);
    chatWindow->show();
}


