//2021/8/26
//用于通信的User派生类，包括连接、发信、收信等操作的封装
//这个User_TcpConnect类是服务端与客户端都需要的操作，一些不同地方的函数请在二次继承后重写，记得虚继承前面的父类

#ifndef USER_TCPCONNECT_H
#define USER_TCPCONNECT_H

#include <QObject>
#include "user_base.h"
#include "message.h"
#include <QTcpSocket>

class User_TcpConnect : public User_Base
{
    //这里我不太清楚Q_OBJECT需不需要删除，User_TcpConnect相当于间接继承了User_Base
    Q_OBJECT
public:
    explicit User_TcpConnect(QString userName, QObject *parent = nullptr);
    bool connectToServer(QString ipAddress, qint16 hostPort); //用来连接服务器的函数，返回true代表连接成功，false代表连接失败
    bool disconnectToServer();//断开网络连接
    bool sendMessage(Message& msg); //发送信息，这里会用一个Message类来包装信息，参数就是一个Message



private:
    static User_TcpConnect* instance;
public:
     static User_TcpConnect* getInstance()
    {
        if(instance == nullptr)
            instance = new User_TcpConnect("-NULL-");
        return instance;
    }

     static QString EmptyName;
     int getSocketID()
     {
         return socketID;
     }
     void setSocketID(int id)
     {
         socketID = id;
     }

public slots:
    virtual void slot_recevierMessage();   //根据返回Message的情况显示
protected slots:
     virtual void slot_hasDisconnected();
protected:
    virtual void deal_failedToSendMessage();
    virtual void deal_successToSendMessage(Message& msg);   //成功发出信息，需要记录信息，例如客户端需要记录并在窗口显示，服务端需要根据具体情况转发

public:
    //周期检查连接是否成功,在发信之前也可以使用
    bool isUserOnline();
    Message* msg;

public:
    QTcpSocket* tcpSocket;
private:
    int socketID;

protected:
    //储存的host信息，用来二次链接以及检查网络情况
    QString hostIP;
    qint16 hostPort;



signals:

};

#endif // USER_TCPCONNECT_H
