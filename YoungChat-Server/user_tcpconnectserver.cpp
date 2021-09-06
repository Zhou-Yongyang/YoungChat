#include "user_tcpconnectserver.h"
#include "tcpserver.h"



User_TcpconnectServer::User_TcpconnectServer(QString userName, QObject *parent) : User_TcpConnect(userName,nullptr)
{

}

void User_TcpconnectServer::slot_recevierMessage()
{
    QByteArray orgData = tcpSocket->readAll();
    QString formatText = QString::fromStdString(orgData.toStdString());
    Message* tmpMessage = new AnswerMessage(formatText);
    QStringList msgTextList;
    msgTextList = formatText.split(Message::ZeroDivideStr);
    for(int i = 0; i < msgTextList.count(); i++)
    {
        QString tmp = msgTextList.at(i);
        if(tmp == "")
            continue;
        else
        {
            qDebug() << "tmpText: " << tmp;
            Message* tmpMessage = new AnswerMessage(tmp);
            msg = tmpMessage;
            qDebug() << "Server recevier a message-------------------------------------------------";
            qDebug() << "Type: " << tmpMessage->type;
            qDebug() << "Sender: " << tmpMessage->getSenderName();
            qDebug() << "Recevier: " << tmpMessage->getRecevierName();
            qDebug() << "Text: " << tmpMessage->getText();
            qDebug() << "Time: " << tmpMessage->getTimeString();
            qDebug() << "Over----------------------------------------------------------------------";
            TcpServer::gethand()->controlFunction(*this);
        }
    }
}

void User_TcpconnectServer::slot_hasDisconnected()
{
    TcpServer::gethand()->removeOnlineUser(getUserName());
}
