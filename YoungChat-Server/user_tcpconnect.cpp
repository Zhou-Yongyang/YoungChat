#include "user_tcpconnect.h"
#include <QtDebug>
#include <QString>
#include <QCoreApplication>

User_TcpConnect* User_TcpConnect::instance = nullptr;

QString User_TcpConnect::EmptyName = "$%EmptyName$%";

User_TcpConnect::User_TcpConnect(QString userName, QObject *parent) : User_Base(userName, parent)
{
    tcpSocket = new QTcpSocket;
}

bool User_TcpConnect::connectToServer(QString ipAddress, qint16 hostPort)
{
    //本次测试成功
    tcpSocket->connectToHost(ipAddress, hostPort);

    if(tcpSocket->waitForConnected(3000))   //三秒内连接上就算成功
    {
        //保存连接信息。
        this->hostIP = ipAddress;
        this->hostPort = hostPort;
        //创建连接
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slot_recevierMessage()));
        return true;
    }
    else
    {
        return false;
    }
}


//在线检测
bool User_TcpConnect::isUserOnline()
{
    //主动检测的方法就是再尝试连接一边，后端做的时候，需要定义一个槽来周期性的捕捉error()信号以及disconnect()信号(或者周期性调用这个函数也行？)

    return tcpSocket->waitForConnected();
}

//发信
bool User_TcpConnect::sendMessage(Message& msg)
{
    //用户在线才发送消息，不在线需要后续处理
    if(isUserOnline())
    {
        qDebug() << "Server Send a message ************************************************";
        qDebug() << "Type: " << msg.type;
        qDebug() << "Sender: " << msg.getSenderName();
        qDebug() << "Recevier: " << msg.getRecevierName();
        qDebug() << "Text: " << msg.getText();
        qDebug() << "Time: " << msg.getTimeString();
        qDebug() << "Over******************************************************************";

        tcpSocket->write(msg.msgToString().toUtf8());  //写入信息的内容，调用一个message的方法
        tcpSocket->waitForBytesWritten(200);
        return true;

    }
    else
    {
        deal_failedToSendMessage();
        return false;
    }
}

//收信
void User_TcpConnect::slot_recevierMessage()
{
    QByteArray orgData = tcpSocket->readAll();
    QString formatText = QString::fromStdString(orgData.toStdString());
    Message* tmpMessage = new Message(formatText);
    msg = tmpMessage;
}

void User_TcpConnect::slot_hasDisconnected()
{
    tcpSocket->deleteLater();
}

bool User_TcpConnect::disconnectToServer()
{
    tcpSocket->disconnectFromHost();
}

void User_TcpConnect::deal_failedToSendMessage()    //发送信息失败时的应对措施，服务端和客户端不同，需要根据具体情况重写
{
}
void User_TcpConnect::deal_successToSendMessage(Message& msg)      //成功发送信息时的应对措施
{
}

