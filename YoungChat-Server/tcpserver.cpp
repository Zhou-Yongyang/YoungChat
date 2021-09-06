#include "tcpserver.h"
#include "message.h"
#include "user_tcpconnectserver.h"
#include "QString"
#include "QHash"
#include "handler.h"
#include <QCoreApplication>

TcpServer* TcpServer::tcpserverhand = nullptr;
int TcpServer:: socketID= 0;


TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{
    qDebug()<<"This PC named :" <<hostinfo.localHostName();
    hostinfo.setHostName(hostinfo.localHostName());
    connect(&tcp_server, SIGNAL(newConnection()), this, SLOT(slot_initNewConnection()));
}




void TcpServer::getaddress()
{
    qDebug() << "getAddress";
    hostinfo.lookupHost(hostinfo.localHostName(), this, SLOT(slot_getAddress(QHostInfo)));
}

//以上为服务端自身操作，以下为互动操作


bool TcpServer::openTcpServer(QString ip, QString port){
    QHostAddress listenAddress(ip);
    if(tcp_server.listen(listenAddress, port.toInt()))
    {
        qDebug() << "IP: " << ip << " Port: " << port;
        return true;
    }
    else
        return false;
}

bool TcpServer::closeTcpServer()
{
    tcp_server.close();
    if(!tcp_server.isListening())
    {
        qDebug() << "Has Closed Server";
        return true;
    }
    else
    {
        qDebug() << "Closed Failed";
        return false;
    }
}


void TcpServer::slot_initNewConnection()
{
   User_TcpconnectServer* user_LoadIn = new User_TcpconnectServer(User_TcpConnect::EmptyName);
   user_LoadIn->tcpSocket = tcp_server.nextPendingConnection();

   user_LoadIn->setSocketID(socketID++);
   connect(user_LoadIn->tcpSocket, SIGNAL(readyRead()), user_LoadIn, SLOT(slot_recevierMessage()));
   connect(user_LoadIn->tcpSocket, SIGNAL(disconnected()), user_LoadIn, SLOT(slot_hasDisconnected()));
   UserListExample.append(user_LoadIn);

}

void TcpServer::slot_getAddress(QHostInfo info)
{
    QList<QHostAddress> addlist = info.addresses();
    IPlist.clear();
    if(addlist.size()>0){
        for(int i =0 ; i < addlist.size() ; i++)
            IPlist.append(addlist.at(i).toString());
    }
    qDebug() << IPlist;
    emit sig_addIpListToUI();
}

void TcpServer::removeOnlineUser(QString userName)
{
    qDebug() << "RemoveUser: " << userName;
    for(int i = 0; i < UserListExample.count(); i++)
    {
        if(UserListExample.at(i)->getUserName() == userName)
        {
            UserListExample.removeAt(i);
        }
    }
    emit sig_addUserToOnlineList(userName);
}

QHash<Message::MessageType, QHash<QString, QString>> TcpServer::dealWithUserRequest(User_TcpconnectServer& user)
{
    Message* msg = user.msg;
    Message::MessageType type = msg->getMessageType();

    QHash<Message::MessageType, QHash<QString, QString>> requestMap;
    if(type == Message::MessageType::LOGIN_REQUEST)
    {
        setUserNameBySocketID(user.getSocketID(), msg->getSenderName());

        //处理请求，返回相应的字符串列表
        requestMap = TcpServer::LOGIN_REQUEST_spiltMessage(user.msg);
    }
   if(type == Message::MessageType::SIGNUP_REQUEST)
   {
       setUserNameBySocketID(user.getSocketID(), msg->getSenderName());
       requestMap = TcpServer::SIGNUP_REQUEST_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::MAKE_FRIEND_REQUEST)
   {
        requestMap = TcpServer::MAKE_FRIEND_REQUEST_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::MAKE_FRIEND_ANSWER)
   {
       requestMap = TcpServer::MAKE_FRIEND_ANSWER_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::FRIENDS_LIST_REQUEST)
   {
        requestMap = TcpServer::FRIENDS_LIST_REQUEST_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::FIND_PASSWORD_REQUEST)
   {
       setUserNameBySocketID(user.getSocketID(), msg->getSenderName());
        requestMap = TcpServer::FIND_PASSWORD_REQUEST_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::RESET_PASSWORD_REQUEST)
   {
        requestMap = TcpServer::RESET_PASSWORD_REQUEST_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::CLIENT_TO_CLIENT_REQUEST)
   {
        requestMap = TcpServer::CLIENT_TO_CLIENT_REQUEST_spiltMessage(user.msg);
   }
   if(type == Message::MessageType::CLIENT_TO_SERVER_REQUEST)
   {
        requestMap = TcpServer::CLIENT_TO_SERVER_REQUEST_spiltMessage(user.msg);
   }
    return requestMap;
}






void TcpServer::setUserNameBySocketID(int id, QString userName)
{
    for(int i = 0; i < UserListExample.count(); i++)
    {
        User_TcpconnectServer* tmp = UserListExample.at(i);
        if(tmp->getSocketID() == id)
        {
            tmp->setUserName(userName);
        }
    }
}

void TcpServer::controlFunction(User_TcpconnectServer &user)
{
    QHash<Message::MessageType, QHash<QString, QString>> midHash;
    midHash = dealWithUserRequest(user);

    processHash(midHash, user);
}

void TcpServer::processHash(QHash<Message::MessageType, QHash<QString, QString>> hashList, User_TcpconnectServer& user)
{
    Message::MessageType msgType = getHashType(hashList);
    QHash<QString, QString> keyValueHash = hashList.value(msgType);

    AnswerMessage* amsg;


    if(msgType == Message::MessageType::LOGIN_REQUEST)
    {
       amsg = constructionAnswerMessage(hashList);
    }
    else if(msgType == Message::Message::FIND_PASSWORD_REQUEST)
    {
        amsg = constructionAnswerMessage(hashList);
    }
    else if(msgType == Message::MessageType::SIGNUP_REQUEST)
    {
        amsg = constructionAnswerMessage(hashList);
    }
    else if(msgType == Message::MessageType::MAKE_FRIEND_REQUEST)
    {
        if(keyValueHash.value("State") == "TRUE")   //用户在线
        {
            amsg = (AnswerMessage*) user.msg;
        }
        else
        {
            amsg = constructionAnswerMessage(hashList);
        }
    }
    else if(msgType == Message::MessageType::MAKE_FRIEND_ANSWER)
    {
            amsg = constructionAnswerMessage(hashList);
    }
    //请求好友列表
    else if(msgType == Message::MessageType::FRIENDS_LIST_REQUEST)
    {
        amsg = constructionAnswerMessage(hashList);
    }
    else if(msgType == Message::MessageType::RESET_PASSWORD_REQUEST)
    {
        amsg = constructionAnswerMessage(hashList);
    }
    else if(msgType == Message::MessageType::CLIENT_TO_CLIENT_REQUEST)
    {
        if(user.msg->getRecevierName() == Message::ServerName)  //群聊消息
        {

            Handler* hand=Handler::gethand();
            Usersql* user_hand=hand->getuser();
            QStringList allUserName;
            allUserName=user_hand->getall();
            //从数据库获得Administor的好友列表，即所有用户的名单
            for(int i = 0; i < allUserName.count(); i++)
            {
                QString tmpName = allUserName.at(i);
                if(tmpName != user.msg->getSenderName() && tmpName != Message::ServerName)
                {
                    qDebug() << "************************************************";
                    qDebug() << "tmpName is: " << tmpName;
                    qDebug() << "user.msg.sender is: " << user.msg->getSenderName();
                                        qDebug() << "************************************************";
                    if(judgeUserOnline(tmpName) == "TRUE")

                    {
                        Message* groupMsg = new Message(user.msg->getSenderName(), tmpName, user.msg->getText(), Message::MessageType::GROUP_TO_CLIENT_ANSWER);
                        transmitMessage(groupMsg);
                    }
                    else
                    {
                        QHash<Message::MessageType, QHash<QString, QString>> tempHash;
                        QHash<QString, QString> qTemp;
                        qTemp.insert("Sender",user.msg->getSenderName());
                        qTemp.insert("Recevier", tmpName);
                        qTemp.insert("Time",user.msg->getTimeString());
                        qTemp.insert("Text", user.msg->getText());
                        tempHash.insert(Message::MessageType::GROUP_TO_CLIENT_ANSWER, qTemp);
                        amsg = constructionAnswerMessage(tempHash);
                    }
                }
            }

        }
        else
        {
            if(keyValueHash.value("State") == "TRUE")
            {
                amsg = (AnswerMessage*) user.msg;
                amsg->type = Message::CLIENT_TO_CLIENT_ANSWER;
            }
            else
            {
                amsg = constructionAnswerMessage(hashList);
            }
        }
    }
    else if(msgType == Message::MessageType::CLIENT_TO_SERVER_REQUEST)
    {
        QString recevierName = user.getUserName();
        QList<AnswerMessage*> msgList = Handler::gethand()->serverToClientMessageList(recevierName);
        for(AnswerMessage* tmpMessage : msgList)
        {
            user.sendMessage(*tmpMessage);
        }
        return;
    }
    transmitMessage(amsg);
}


void TcpServer::transmitMessage(Message* msg)
{
    User_TcpconnectServer* tmpUser;
    for(int i = 0; i < UserListExample.count(); i++)
    {
        tmpUser = UserListExample.at(i);
        if(tmpUser->getUserName() == msg->getRecevierName())
        {
            tmpUser->sendMessage(*msg);
        }
    }
}


AnswerMessage* TcpServer::constructionAnswerMessage(QHash<Message::MessageType, QHash<QString, QString>> tmpHash)
{
    QHash<Message::MessageType, QHash<QString, QString>> hash = Handler::gethand()->Meshandle(tmpHash);
    AnswerMessage* answer  = dealWithUserAnswer(hash);
    return  answer;
}


Message::MessageType TcpServer::getHashType(QHash<Message::MessageType, QHash<QString, QString>> hash)
{
    return hash.keys().at(0);
}


//登陆请求返回（给数据库）
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::LOGIN_REQUEST_spiltMessage(Message* msg)
{
    //三项
    //Sender:XXXX
    //UserName:XXXX
    //Password:XXXX
    return filed_QM_QH_Hash(Message::MessageType::LOGIN_REQUEST,msg);
}

//注册请求
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::SIGNUP_REQUEST_spiltMessage(Message* msg)
{
    //
    //Sender:XXX
    //UserName:XXX
    //Password:XXX
    //Question1:XXXX
    //Question2:XXXX
    return filed_QM_QH_Hash(Message::MessageType::SIGNUP_REQUEST,msg);
}

//交友请求
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::MAKE_FRIEND_REQUEST_spiltMessage(Message* msg)
{
    //Recevier:XXXXXX
    //State:XXXXX
    //Sender:XXXX
    QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Time", msg->getTimeString());
    keyValueHash.insert("Sender", msg->getSenderName());
    keyValueHash.insert("Recevier", msg->getRecevierName());
    keyValueHash.insert("State", judgeUserOnline(msg->getRecevierName()));
    tempHash.insert(Message::MessageType::MAKE_FRIEND_REQUEST, keyValueHash);

    return tempHash;
}

//交友回应
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::MAKE_FRIEND_ANSWER_spiltMessage(Message* msg)
{
    //Sender:XXXX
    //Recevier:XXX
    //Time:XXX
    //AnswerType:XXX
    QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Time", msg->getTimeString());
    keyValueHash.insert("Sender", msg->getSenderName());
    keyValueHash.insert("Recevier",msg->getRecevierName());
    keyValueHash.insert("AnswerType", QString::number(msg->getAnswerType()));
    keyValueHash.insert("State", judgeUserOnline(msg->getRecevierName()));
    tempHash.insert(Message::MessageType::MAKE_FRIEND_ANSWER, keyValueHash);
    return tempHash;
}

//找回密码请求
QHash<Message::MessageType, QHash<QString, QString>>  TcpServer::FIND_PASSWORD_REQUEST_spiltMessage(Message* msg)
{
    //Sender:XXXX
    //UserName:XXXX
    QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Time", msg->getTimeString());
    keyValueHash.insert("Sender", msg->getSenderName());
    keyValueHash.insert("UserName", msg->getSenderName());
    tempHash.insert(Message::MessageType::FIND_PASSWORD_REQUEST, keyValueHash);
    return tempHash;
}

//推送好友名单
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::FRIENDS_LIST_REQUEST_spiltMessage(Message* msg)
{
    //Sender:XXXXX
    //UserName:XXXX
    QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Time", msg->getTimeString());
    keyValueHash.insert("Sender", msg->getSenderName());
    keyValueHash.insert("UserName", msg->getSenderName());
    tempHash.insert(Message::MessageType::FRIENDS_LIST_REQUEST, keyValueHash);
    return tempHash;
}

//重设密码请求
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::RESET_PASSWORD_REQUEST_spiltMessage(Message* msg)
{
    //Sender:XXXX
    //UserName:XXXX
    //QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    //QHash<QString, QString> keyValueHash;
    //keyValueHash.insert("Time", msg->getTimeString());
    //keyValueHash.insert("Sender",msg->getSenderName());
    //keyValueHash.insert("UserName", msg->getSenderName());

    //keyValueHash.insert("Password", msg->getText());
    //tempHash.insert(Message::MessageType::RESET_PASSWORD_REQUEST, keyValueHash);

    return filed_QM_QH_Hash(Message::MessageType::RESET_PASSWORD_REQUEST , msg);
}
//客户端沟通消息
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::CLIENT_TO_CLIENT_REQUEST_spiltMessage(Message* msg)
{
    //Sender:XXXX
    //Recevier:XXXX
    //State:XXXX
    //Text:XXXX
    QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Time", msg->getTimeString());
    keyValueHash.insert("Sender",msg->getSenderName());
    keyValueHash.insert("Recevier",msg->getRecevierName());
    if(msg->getRecevierName() == Message::ServerName)//群发消息
    {
        keyValueHash.insert("orgSender", msg->getSenderName());
    }
    keyValueHash.insert("State", judgeUserOnline(msg->getRecevierName()));
    keyValueHash.insert("Text",msg->getText());
    tempHash.insert(Message::MessageType::CLIENT_TO_CLIENT_REQUEST, keyValueHash);
    return tempHash;
}

//服务端都对客户端的请求
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::CLIENT_TO_SERVER_REQUEST_spiltMessage(Message* msg)
{
    //Sender:XXXX
    //UserName:XXXX
    QHash<Message::MessageType, QHash<QString,QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Time", msg->getTimeString());
    keyValueHash.insert("Sender",msg->getSenderName());
    keyValueHash.insert("UserName", msg->getSenderName());
    tempHash.insert(Message::MessageType::CLIENT_TO_SERVER_REQUEST, keyValueHash);
    return tempHash;
}

//填充主哈希表
QHash<Message::MessageType, QHash<QString, QString>> TcpServer::filed_QM_QH_Hash(Message::MessageType type, Message* msg)
{
    QHash<Message::MessageType, QHash<QString, QString>> tempHash;
    QHash<QString, QString> keyValueHash;
    keyValueHash.insert("Sender", msg->getSenderName());
    keyValueHash.insert("Time", msg->getTimeString());
    QStringList wordsList = msg->getText().split(Message::ThirdDivideStr);
    keyValueHash = filled_QS_QS_Hash(wordsList);
    tempHash.insert(type, keyValueHash);
    return tempHash;
}


//填充子哈希表
QHash<QString, QString> TcpServer::filled_QS_QS_Hash(QStringList list)
{
    QHash<QString, QString> hash;
    for(int i = 0; i < list.count(); i += 2)
    {
        hash.insert(list[i],list[i+1]);
    }
    return hash;
}


//回应
// send receive type(msg) anstype
// 对登录请求的回答 1
AnswerMessage* TcpServer::deal_LOGIN_ANSWER(QHash<QString,QString> &temp){//默认：名字+是否同意
    QString name = temp["UserName"];
    AnswerMessage::AnswerType ansType = AnswerMessage::AnswerType(temp["Output"].toInt());
    AnswerMessage* ans;
    ans = new AnswerMessage(Message::ServerName, name, Message::MessageType::LOGIN_ANSWER,ansType );

    if(ans->getAnswerType() == Message::AnswerType::TRUE)
    {
        emit sig_addUserToOnlineList(name);
    }
    return ans;
}
// 对注册请求的回答 1
AnswerMessage* TcpServer:: deal_SIGNUP_ANSWER(QHash<QString,QString> &temp){
    QString name = temp["UserName"];
    AnswerMessage::AnswerType ansType = AnswerMessage::AnswerType(temp["Output"].toInt());
    AnswerMessage* ans;
    ans = new AnswerMessage(Message::ServerName, name, Message::MessageType::SIGNUP_ANSWER,ansType );
    return ans;
}
// 对加好友的回答（server给A）
AnswerMessage* TcpServer::deal_MAKE_FRIEND_ANSWER(QHash<QString,QString> &temp){
    QString name = temp["UserName"];
    AnswerMessage::AnswerType ansType = AnswerMessage::AnswerType(temp["Output"].toInt());
    AnswerMessage* ans;
    ans = new AnswerMessage(Message::ServerName, name, Message::MessageType::LOGIN_ANSWER,ansType );
    return ans;
}
// 对推送好友名单的回答
AnswerMessage* TcpServer::deal_FRIEND_LIST_ANSWER(QHash<QString,QString> &temp){//存放
    QList<QString> s = temp.keys();
    QHash<QString,QString> STateofFriends;
    QString name;
    for(QString string : s)// 1. 校长 2.xiao 3 xi
    {
        if(string == "UserName")
            name = temp["UserName"];
        else {
            STateofFriends[temp[string]] = TcpServer::judgeUserOnline(temp[string]);
        }
    }// 用户在线情况：STateofFriends
    QString text = "";
    QList<QString> FRiend_NAme = STateofFriends.keys();
    for(QString string : FRiend_NAme)
    {
        text.append(string + Message::ForthDivideStr + STateofFriends[string] + Message::ThirdDivideStr );
    }
    Message* msg ;
    msg = new Message(Message::ServerName,name,text,Message::MessageType::FRIEND_LIST_ANSWER);
    return (AnswerMessage*)msg;
}////////////////////////////////////////////用户名不能叫user_name
// 重置密码的回答
AnswerMessage* TcpServer::deal_RESET_PASSWORD_ANSWER(QHash<QString,QString> &temp){
    QString name = temp["UserName"];
    AnswerMessage::AnswerType type = AnswerMessage::AnswerType(temp["Output"].toInt());
    AnswerMessage*ans;
    ans = new AnswerMessage(Message::ServerName,name,Message::MessageType::RESET_PASSWORD_ANSWER,type);
    return ans;
}
// 找回密码的回答
AnswerMessage* TcpServer::deal_FIND_PASSWORD_ANSWER(QHash<QString,QString> &temp){
    QString question1 = temp["Question1"];
    QString question2 = temp["Question2"];
    QString answer1 = temp["Answer1"];
    QString answer2 = temp["Answer2"];
    QString text = "";
    text = question1 + Message::ForthDivideStr + answer1 + Message::ThirdDivideStr + question2 +Message::ForthDivideStr + answer2;
    Message* msg;
    msg = new Message(Message::ServerName,temp["UserName"],text,Message::MessageType::FIND_PASSWORD_ANSWER);
    return (AnswerMessage*)msg;
}

//冗余消息的回答
AnswerMessage* TcpServer::deal_CLIENT_TO_SERVER_ANSWER(QHash<QString, QString> &temp)
{
    QList<AnswerMessage*> msgList = Handler::gethand()->serverToClientMessageList(temp["UserName"]);
    for(int i = 0; i < msgList.count(); i++)
    {
        transmitMessage(msgList.at(i));
    }
}

AnswerMessage* TcpServer::dealWithUserAnswer(QHash<Message::MessageType, QHash<QString, QString>> &hash)
{
    QList<Message::MessageType> typelist = hash.keys();
    Message::MessageType type = typelist.at(0);
    QHash<QString,QString> temp = hash[type];
    // 不同的type对应不同的给 QHash类型，不同的类型 返回的《QString，QString》不同；
    if(type == Message::MessageType::LOGIN_ANSWER){
        return deal_LOGIN_ANSWER(temp);
    }
    else if(type == Message::MessageType::SIGNUP_ANSWER){
        return deal_SIGNUP_ANSWER(temp);
    }
    else if(type == Message::MessageType::MAKE_FRIEND_ANSWER){
        return deal_MAKE_FRIEND_ANSWER(temp);
    }
    else if(type == Message::MessageType::FRIEND_LIST_ANSWER){
        return deal_FRIEND_LIST_ANSWER(temp);
    }
    else if(type == Message::MessageType::RESET_PASSWORD_ANSWER){
        return deal_RESET_PASSWORD_ANSWER(temp);
    }
    else if(type == Message::MessageType::FIND_PASSWORD_ANSWER){
        return deal_FIND_PASSWORD_ANSWER(temp);
    }
    else if(type == Message::MessageType::CLIENT_TO_SERVER_ANSWER){
        return  deal_CLIENT_TO_SERVER_ANSWER(temp);
    }
    else if(type == Message::MessageType::NONE)
    {
        return  new AnswerMessage("","",Message::MessageType::NONE, Message::AnswerType::EMPTY);
    }
    else if(type == Message::MessageType::NOUSER)
    {
        return  new AnswerMessage("", "", Message::MessageType::NOUSER, Message::AnswerType::FALSE);
    }
    return nullptr;
}


QString TcpServer::judgeUserOnline(QString UserName)
{
    if(UserName == Message::ServerName)
        return "TRUE";
    for(int i = 0; i < UserListExample.count(); i++)
    {
        if(UserName == UserListExample.at(i)->getUserName() )
        {
            return "TRUE";
        }
    }


    return "FALSE";
}


