#ifndef USER_TCPCONNECT_CLIENT_H
#define USER_TCPCONNECT_CLIENT_H

#include <QObject>
#include "user_tcpconnect.h"
class User_TcpConnect_Client : public User_TcpConnect
{
    Q_OBJECT
public:
    explicit User_TcpConnect_Client(QString userName, QObject *parent = nullptr);
    static User_TcpConnect_Client* getInstance()
    {
        if(instance == nullptr)
            instance = new User_TcpConnect_Client(User_TcpConnect::EmptyName);
        return instance;
    }

private:
    static User_TcpConnect_Client* instance;


public:


    void receiveMessagePros();

//    LOGIN_REQUEST,  //登陆    UserName:XXXXXX:Password:XXXXXXX
//    SIGNUP_REQUEST, //注册    UserName:XXXXXX:Password:XXXXXX:Q1:XXXXXX:Q2:XXXXXX
//    FIND_PASSWORD_REQUEST,  //找回密码  UserName:XXXXXX
//    RESET_PASSWORD_REQUEST, //重设密码  UserName:Password:XXXXXX
//    FRIENDS_LIST_REQUEST,   //推送好友名单   ....
//    CLIENT_TO_CLIENT_REQUEST,   //客户端沟通消息
//    MAKE_FRIEND_REQUEST,    //交友申请  ....
    void loginToMsgText(QString userName, QString Passwd);
    void signupToMsgText(QString userName, QString Passwd, QString q1, QString aq, QString q2, QString a2);
    void findPswToMsgText(QString userName);
    void resetPswToMsgText(QString userName, QString Passwd);
    void friendListToMsgText(QString userName);
    void cTocToMsgText(QString userName, QString receiveName, QString Msg);
    void makeFriReqText(QString userName, QString receiveName);
    void cTosToMsgText(QString userName);
    void ansToFriendRequest(QString userName, QString receiverName, Message::AnswerType);
    //以上为发信


protected slots:
    virtual void slot_recevierMessage()override;

signals:
    void sig_login(bool flag);
    void sig_loginSuccess();
    void sig_loginFailed();
    void sig_signupSuccess();
    void sig_signupFailed();
//    void sig_findPswSuccess();
//    void sig_findPswFailed();
    void sig_resetPswSuccess();
    void sig_resetPswFailed();
//    void sig_friendreqSuccess();
//    void sig_friendreqFailed();
//    void sig_cTocMsgSuccess();
//    void sig_cTocMsgFailed();
    void sig_makeFriReqSuccess();
    void sig_makeFriReqFailed();


};

#endif // USER_TCPCONNECT_CLIENT_H
