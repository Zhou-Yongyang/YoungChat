#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDebug>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <user_tcpconnectserver.h>
#include "message.h"
#include "answermessage.h"


class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    QStringList IPlist;
    //用户列表
    QList <User_TcpconnectServer*> UserListExample;

    //单例模式获取
    static TcpServer*gethand(){
        if(tcpserverhand == nullptr)
            tcpserverhand = new TcpServer();
        return tcpserverhand;
    }


    //服务器开启
    bool openTcpServer(QString,QString);
    void getaddress();
    bool closeTcpServer();
    void removeOnlineUser(QString userName);
    QHostInfo getHostInfo()
    {
        return hostinfo;
    }

    void controlFunction(User_TcpconnectServer& user);
    QHash<Message::MessageType, QHash<QString, QString>> dealWithUserRequest(User_TcpconnectServer& user);
private:
    explicit TcpServer(QObject *parent = nullptr);
    //连接器
    static TcpServer* tcpserverhand;
    static int socketID;

    QTcpServer tcp_server;
    QHostInfo hostinfo;
private:
    void setUserNameBySocketID(int id, QString userName);
    QString judgeUserOnline(QString UserName);

    QHash<QString, QString> filled_QS_QS_Hash(QStringList list);
    QHash<Message::MessageType, QHash<QString, QString>> filed_QM_QH_Hash(Message::MessageType type, Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> LOGIN_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> SIGNUP_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> MAKE_FRIEND_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> FRIENDS_LIST_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> FIND_PASSWORD_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> RESET_PASSWORD_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> CLIENT_TO_CLIENT_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> CLIENT_TO_SERVER_REQUEST_spiltMessage(Message* msg);
    QHash<Message::MessageType, QHash<QString, QString>> MAKE_FRIEND_ANSWER_spiltMessage(Message* msg);


    AnswerMessage* dealWithUserAnswer(QHash<Message::MessageType, QHash<QString, QString>> &hash);
    AnswerMessage* constructionAnswerMessage(QHash<Message::MessageType, QHash<QString, QString>> tmpHash);

    AnswerMessage* deal_LOGIN_ANSWER(QHash<QString,QString> &temp);
    AnswerMessage* deal_SIGNUP_ANSWER(QHash<QString,QString> &temp);
    AnswerMessage* deal_MAKE_FRIEND_ANSWER(QHash<QString,QString> &temp);
    AnswerMessage* deal_FRIEND_LIST_ANSWER(QHash<QString,QString> &temp);
    AnswerMessage* deal_RESET_PASSWORD_ANSWER(QHash<QString,QString> &temp);
    AnswerMessage* deal_FIND_PASSWORD_ANSWER(QHash<QString,QString> &temp);
    AnswerMessage* deal_CLIENT_TO_SERVER_ANSWER(QHash<QString, QString> &temp);


    void processHash(QHash<Message::MessageType, QHash<QString, QString>> hashList, User_TcpconnectServer& user);
    void transmitMessage(Message* msg);
    Message::MessageType getHashType(QHash<Message::MessageType, QHash<QString, QString>> hash);
private slots:
    void slot_getAddress(QHostInfo info);
    void slot_initNewConnection();
signals:
    void sig_addIpListToUI();
    void sig_addUserToOnlineList(QString userName);
};

#endif // TCPSERVER_H
