#ifndef USER_TCPCONNECTSERVER_H
#define USER_TCPCONNECTSERVER_H

#include <QObject>
#include<user_tcpconnect.h>
class User_TcpconnectServer : public User_TcpConnect
{
    Q_OBJECT
public:
    explicit User_TcpconnectServer(QString userName, QObject *parent = nullptr);
public:
    virtual void slot_recevierMessage() override;
    virtual void slot_hasDisconnected() override;

signals:

};

#endif // USER_TCPCONNECTSERVER_H
