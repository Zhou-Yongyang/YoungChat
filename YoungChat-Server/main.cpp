#include "serverwindow.h"
#include <QApplication>
#include "user_tcpconnect.h"
#include "message.h"
#include "answermessage.h"
#include "server.h"
#include "handler.h"
#include "testtcpserver.h"

QString buildSignUpMessage(QString name, QString password, QString q1, QString q2, QString a1, QString a2)
{
    QString str = "UserName" + Message::ThirdDivideStr + name + Message::ThirdDivideStr + "Password" + Message::ThirdDivideStr + password
            + Message::ThirdDivideStr + "Question1" +Message::ThirdDivideStr+ q1
            + Message::ThirdDivideStr + "Answer1" + Message::ThirdDivideStr + a1
            + Message::ThirdDivideStr + "Question2" + Message::ThirdDivideStr + q2
            + Message::ThirdDivideStr + "Answer2" + Message::ThirdDivideStr + a2;
    return  str;
}

QString buildLoginMessage(QString name, QString password)
{
    QString str = "UserName" + Message::ThirdDivideStr + name + Message::ThirdDivideStr + "Password" + Message::ThirdDivideStr + password;
    return str;
}

QString buildFindPassword(QString name)
{
    QString str = "UserName" + Message::ThirdDivideStr + name;
    return str;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server serverWindow;
    serverWindow.show();
    /*
    User_TcpconnectServer user1("xiaozhang"); // user1： xiaozhang
    User_TcpconnectServer user2("xiaowang"); //user2：xiaowang
    TcpServer * tcpl = TcpServer::gethand();
    QString str1 = buildLoginMessage("xiaozhang" , "123");
    QString str2 = buildLoginMessage("xiaowang" , "123456");
    QString str3 = buildFindPassword("xiaozhang");
    tcpl->UserListExample.append(&user1);
    tcpl->UserListExample.append(&user2);
    user2.msg = new Message(user2.getUserName(),Message::ServerName,"",Message::MessageType::CLIENT_TO_SERVER_REQUEST);
//    user2 .msg = new Message(user2.getUserName(),user1.getUserName(),"",Message::MessageType::MAKE_FRIEND_REQUEST);
//    user1 .msg = new Message(user1.getUserName(),user2.getUserName(),"WDNMD",Message::MessageType::CLIENT_TO_CLIENT_REQUEST);
//    user1.msg = new Message(user1.getUserName() ,Message::ServerName, str1, Message::MessageType::MAKE_FRIEND_REQUEST );

    tcpl->controlFunction(user2);
    */

    return a.exec();
}
