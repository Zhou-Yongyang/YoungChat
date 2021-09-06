//2021/8/26
//用于通信的User派生类，包括连接、发信、收信等操作的封装

#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include "user_base.h"


class Message : public QObject
{
    Q_OBJECT
public:
     static QString ServerName;
     static QString ZeroDivideStr;
     static QString FirstDivideStr;
     static QString SecondDivideStr;
     static QString ThirdDivideStr;
     static QString ForthDivideStr;

public:
    //枚举类，用来确定消息类型
    enum MessageType{
        LOGIN_REQUEST = 0,  //登陆    UserName:XXXXXX:Password:XXXXXXX
        SIGNUP_REQUEST = 1, //注册    UserName:XXXXXX:Password:XXXXXX:Q1:XXXXXX:Q2:XXXXXX
        FIND_PASSWORD_REQUEST = 2,  //找回密码  UserName:XXXXXX
        RESET_PASSWORD_REQUEST = 3, //重设密码  UserName:Password:XXXXXX
        FRIENDS_LIST_REQUEST = 4,   //推送好友名单   ....
        CLIENT_TO_CLIENT_REQUEST = 5,   //客户端沟通消息
        MAKE_FRIEND_REQUEST = 6,    //交友申请  ....
        CLIENT_TO_SERVER_REQUEST = 7,    //客户端向服务端的申请

        NONE = 8,
        NOUSER = 9,

        LOGIN_ANSWER = 10,   //登陆回应  直接查StandAnswer
        SIGNUP_ANSWER = 11,  //注册回应  直接查StandAnswer
        FIND_PASSWORD_ANSWER = 12,   //密保问题推送 Question1:XXXXXX:Question2:XXXXXX
        RESET_PASSWORD_ANSWER = 13, //重设密码推送  直接查StandAnswer
        FRIEND_LIST_ANSWER = 14, //好友列表推送回应  UserName1 : XXXXXX /  STATE1 : 0 @@@ UserName:XXXXXX/STATE //0不在线，1在线
        MAKE_FRIEND_ANSWER = 15,  //好友申请回应    直接查StandAnswer
        CLIENT_TO_CLIENT_ANSWER = 16,
        CLIENT_TO_SERVER_ANSWER = 17,
        GROUP_TO_CLIENT_ANSWER = 18
    };
    enum AnswerType{
        TRUE = 1,
        FALSE = 0,
        EMPTY = 2
    };


public:
    explicit Message(QString senderName, QString recevierName, QString text,  MessageType type ,QObject *parent = nullptr);
    explicit Message(QString formatText);   //根据标准字符串转换为消息对象
    virtual QString msgToString(); //用来将消息转换为需要的格式标准格式,需要根据Type来把内容转换为需要的东西if(type== Message.xxx),即特定的格式
    virtual void stringToMessage(QString formatText);
    //get 方法集合
    QString getSenderName();
    QString getRecevierName();
    QString getText();
    QString getTimeString();
    void setStrToTime(QString str);
    MessageType getMessageType();
    virtual AnswerType getAnswerType();


public:
    MessageType type;
    User_Base sender;
    User_Base recevier;
    QDateTime time;

protected:
    QString text;
protected:
    MessageType strTypeTointType(QString str);


signals:

};

#endif // MESSAGE_H
