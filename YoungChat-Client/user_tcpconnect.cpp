#include "user_tcpconnect.h"
#include <QtDebug>
#include <QString>

User_TcpConnect* User_TcpConnect::instance = nullptr;

QString User_TcpConnect::EmptyName = "$%EmptyName$%";

User_TcpConnect::User_TcpConnect(QString userName, QObject *parent) : User_Base(userName, parent)
{
    tcpSocket = new QTcpSocket;
    qDebug() << "build User_TcpConnect finish";
}

bool User_TcpConnect::connectToServer(QString ipAddress, qint16 hostPort)
{
    //本次测试成功
    tcpSocket->connectToHost(ipAddress, hostPort);

    if(tcpSocket->waitForConnected(3000))   //三秒内连接上就算成功
    {
        qDebug() << "connect successfully";
        //保存连接信息。
        this->hostIP = ipAddress;
        this->hostPort = hostPort;
        //创建连接
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slot_recevierMessage()));
        return true;
    }
    else
    {
        qDebug() << "connect failed";
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
        tcpSocket->write(msg.msgToString().toUtf8());  //写入信息的内容，调用一个message的方法
        deal_successToSendMessage(msg); //一个小坑，所有继承了QObject类的子类不能直接传参，防止隐性构造
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
    qDebug() << "recevier";
    QByteArray orgData = tcpSocket->readAll();
    QString formatText = QString::fromStdString(orgData.toStdString());
    Message* tmpMessage = new Message(formatText);
    msg = tmpMessage;

    qDebug() << "msgToString: " << msg->msgToString();
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
    qDebug() << "failed to Send Message";
}
void User_TcpConnect::deal_successToSendMessage(Message& msg)      //成功发送信息时的应对措施
{
    qDebug() << "success to Send Message";
}

