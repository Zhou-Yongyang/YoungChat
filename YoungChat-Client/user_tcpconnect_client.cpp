#include "user_tcpconnect_client.h"
#include "message.h"
#include "answermessage.h"
#include "windowcontroller.h"
User_TcpConnect_Client* User_TcpConnect_Client::instance = nullptr;

User_TcpConnect_Client::User_TcpConnect_Client(QString userName, QObject *parent) : User_TcpConnect(userName,parent)
{
    if(tcpSocket == nullptr)
        tcpSocket = new QTcpSocket;
}
//收信处理器
void User_TcpConnect_Client::slot_recevierMessage()
{
    qDebug() << "recevier";
    QByteArray orgData = tcpSocket->readAll();
    QString formatText = QString::fromStdString(orgData.toStdString());
    qDebug() << "formatText: " << formatText;
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
            AnswerMessage* tmpMessage = new AnswerMessage(tmp);
            msg = tmpMessage;
            qDebug() << "msgToString: " << msg->msgToString();
            qDebug() << "AnswerType: " << msg->getAnswerType();
            receiveMessagePros();
        }
    }


}

void User_TcpConnect_Client::receiveMessagePros()
{
    if(msg->getMessageType() == Message::MessageType::LOGIN_ANSWER){
        bool flag;
        if(Message::AnswerType::TRUE == msg->getAnswerType()){
            flag = 1;
        }
        else{
            flag = 0;
        }
        WindowController::getInstance()->loginInfoDeal(flag);
    }

    else if(msg->getMessageType() == Message::MessageType::SIGNUP_ANSWER){
        bool flag;
        if(Message::AnswerType::TRUE == msg->getAnswerType()){
            flag = 1;
        }
        else{
            flag = 0;
        }
        WindowController::getInstance()->signupInfoDeal(flag);
    }

    else if(msg->getMessageType() == Message::MessageType::FIND_PASSWORD_ANSWER){
        qDebug() << "FIND_PASSWORD_ANSWER_TYPE";
        QString str = msg->getText();
        QStringList wordlist = str.split(Message::ThirdDivideStr);
        //返回的wordlist中wordlist.at(0)、wordlist.at(2)是问题，1、3是答案
        QStringList qaList_1 = wordlist.at(0).split(Message::ForthDivideStr);
        QStringList qaList_2 = wordlist.at(1).split(Message::ForthDivideStr);
        WindowController::getInstance()->findPswInfoDeal(qaList_1.at(0),qaList_1.at(1),qaList_2.at(0),qaList_2.at(1));
    }

    else if(msg->getMessageType() == Message::MessageType::RESET_PASSWORD_ANSWER){
        bool flag;
        if(Message::AnswerType::TRUE == msg->getAnswerType()){
            flag = 1;
        }
        else{
            flag = 0;
        }
        WindowController::getInstance()->pswResetInfoDeal(flag);
    }
    else if(msg->getMessageType() == Message::MessageType::FRIEND_LIST_ANSWER){
        QString str = msg->getText();

        QStringList wordlist0;
        if(str != "")
        {
           wordlist0 =str.split(Message::ThirdDivideStr);  //分割为每个用户
        }
        //QMap <QString, int> tmpmap;
        QStringList onlineFriendList;
        QStringList offlineFriendList;
        for(int i=0; i<wordlist0.count(); i++){
            if(wordlist0.at(i) == "")
                break;
            QStringList tmp = wordlist0.at(i).split(Message::ForthDivideStr);
            QString friend_name = tmp.at(0);
            QString friend_state = tmp.at(1);
            if(0 == friend_state.compare("TRUE"))
            {
                onlineFriendList.append(friend_name);
            }
            else{
                offlineFriendList.append(friend_name);
            }
        }
        WindowController::getInstance()->friendListInfoDeal(onlineFriendList,offlineFriendList);
    }
    else if(msg->getMessageType() == Message::MessageType::CLIENT_TO_CLIENT_ANSWER || msg->getMessageType() == Message::MessageType::GROUP_TO_CLIENT_ANSWER){
        qDebug() << "shou dao rong yu xiao xi";
        QString msgText = msg->getText();
        //返回的str是消息内容
        QString senderName = msg->getSenderName();
        QString TTTTime = msg->getTimeString();
        QStringList TimeList = TTTTime.split("##");
        QString msgTime;
        for(int i = 0; i<TimeList.count(); i++)
         {
            msgTime.append(TimeList.at(i));
            msgTime.append(".");
         }
        if(msg->getMessageType() == Message::MessageType::CLIENT_TO_CLIENT_ANSWER)
            WindowController::getInstance()->cTocInfoDeal(msgText,senderName,msgTime);
        else
        {
            WindowController::getInstance()->cTocInfoDeal_groupMessage(msgText, senderName, msgTime);
        }
    }
    else if(msg->getMessageType() == Message::MessageType::MAKE_FRIEND_ANSWER){
        bool flag;
        if(Message::AnswerType::TRUE == msg->getAnswerType()){
            flag = 1;
        }
        else{
            flag = 0;
        }
        QString senderName = msg->getSenderName();
        WindowController::getInstance()->friendApplyAns(flag,senderName);
    }
    else if(msg->getMessageType() == Message::MessageType::MAKE_FRIEND_REQUEST)
    {
        QString senderName = msg->getSenderName();
        WindowController::getInstance()->reqToMakeFriend(senderName);
    }
    else if(msg->getMessageType() == Message::MessageType::CLIENT_TO_SERVER_ANSWER)  //冗余消息反馈
    {
        QString msgText = msg->getText();
        //返回的str是消息内容
        QString senderName = msg->getSenderName();
        QString msgTime;
        QString TTTTime = msg->getTimeString();
        QStringList TimeList = TTTTime.split("##");
        for(int i = 0; i<TimeList.count(); i++)
         {
            msgTime.append(TimeList.at(i));
            msgTime.append(".");
         }
        WindowController::getInstance()->cTocInfoDeal(msgText,senderName,msgTime);
    }
}

//全部发信函数
void User_TcpConnect_Client::loginToMsgText(QString userName, QString Passwd)
{
    QString str;
    str.append("UserName");
    str.append(Message::ThirdDivideStr);
    str.append(userName);
    str.append(Message::ThirdDivideStr);
    str.append("Password");
    str.append(Message::ThirdDivideStr);
    str.append(Passwd);
    Message* msg = new Message(userName,"Administrator",str, Message::MessageType::LOGIN_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::signupToMsgText(QString userName, QString Passwd, QString q1, QString a1, QString q2, QString a2)
{
    QString str;
    str.append("UserName");
    str.append(Message::ThirdDivideStr);
    str.append(userName);
    str.append(Message::ThirdDivideStr);
    str.append("Password");
    str.append(Message::ThirdDivideStr);
    str.append(Passwd);
    str.append(Message::ThirdDivideStr);
    str.append("Question1");
    str.append(Message::ThirdDivideStr);
    str.append(q1);
    str.append(Message::ThirdDivideStr);
    str.append("Answer1");
    str.append(Message::ThirdDivideStr);
    str.append(a1);
    str.append(Message::ThirdDivideStr);
    str.append("Question2");
    str.append(Message::ThirdDivideStr);
    str.append(q2);
    str.append(Message::ThirdDivideStr);
    str.append("Answer2");
    str.append(Message::ThirdDivideStr);
    str.append(a2);
    Message* msg = new Message(userName,"Administrator",str, Message::MessageType::SIGNUP_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::findPswToMsgText(QString userName)
{
    QString str;
    str.append("UserName");
    str.append(Message::ThirdDivideStr);
    str.append(userName);
    Message* msg = new Message(userName,"Administrator",str, Message::MessageType::FIND_PASSWORD_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::resetPswToMsgText(QString userName, QString Passwd)
{
    QString str;
    str.append("UserName");
    str.append(Message::ThirdDivideStr);
    str.append(userName);
    str.append(Message::ThirdDivideStr);
    str.append("Password");
    str.append(Message::ThirdDivideStr);
    str.append(Passwd);
    Message* msg = new Message(userName,"Administrator",str, Message::MessageType::RESET_PASSWORD_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::friendListToMsgText(QString userName)
{
    Message* msg = new Message(userName,"Administrator", "" , Message::MessageType::FRIENDS_LIST_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::cTocToMsgText(QString userName, QString receiveName, QString Msg)
{
    QString str;
    str.append(Msg);
    Message* msg = new Message(userName,receiveName,str, Message::MessageType::CLIENT_TO_CLIENT_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::makeFriReqText(QString userName, QString receiveName)
{
    Message* msg = new Message(userName,receiveName,"", Message::MessageType::MAKE_FRIEND_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::cTosToMsgText(QString userName)
{
    QString str;
    str.append("UserName");
    str.append(Message::ThirdDivideStr);
    str.append(userName);
    Message* msg = new Message(userName,"Administrator",str, Message::MessageType::CLIENT_TO_SERVER_REQUEST);
    sendMessage(*msg);
}

void User_TcpConnect_Client::ansToFriendRequest(QString userName, QString receiverName, Message::AnswerType flag)
{
    AnswerMessage* msg = new AnswerMessage(userName,receiverName,Message::MessageType::MAKE_FRIEND_ANSWER,flag);
    qDebug() << msg->getAnswerType();
    sendMessage(*msg);
}
