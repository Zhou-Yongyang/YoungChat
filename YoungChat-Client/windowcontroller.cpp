#include "windowcontroller.h"
#include "user_tcpconnect_client.h"
WindowController* WindowController::instance = nullptr;

WindowController::WindowController(QObject *parent) : QObject(parent)
{
    createLoginWindow();
    createFriendList();
    createSignupWindow();
    createPwdResetWindow();
    createFindPswWindow();
}

void WindowController::createConnectToServerWindow()
{
    networkWindow = new NetworkConnection();
    networkWindow->show();
}


void WindowController::createLoginWindow()
{
    loginWindow = new Loginwindow();
    //loginWindow->show();
}

void WindowController::createSignupWindow()  //on_registerButton_clicked
{
    signupWindow = new Register();
    //signupWindow->show();
}

void WindowController::createFindPswWindow()  //on_FindPassword_clicked
{
    findpswWindow = new FindPasswordApply();
    //findpswWindow->show();
}

void WindowController::createPwdResetWindow()  //on_pButtonOk_clicked
{
    pwdresetWindow = new PasswordReset();
    //pwdresetWindow->show();
}

void WindowController::createFriendList()
{
    friendListWindow = new FriendList();
    //friendListWindow->show();
}

void WindowController::createChatBox(QString contacterName)
{
}


void WindowController::loginInfoDeal(bool flag)
{
    if(flag){  //登陆成功
        QString userName = loginWindow->userName;
        User_TcpConnect_Client* _client = User_TcpConnect_Client::getInstance();
        _client->setUserName(userName);
        //_client->cTosToMsgText(userName);  //请求冗余消息 发送一条
        _client->friendListToMsgText(userName);//申请好友列表


        //跳转到好友列表界面
        FriendList* friList = friendListWindow;
        if(friList == nullptr){
            createFriendList();
            friList = friendListWindow;
            friList->show();
        }
        else{
            friList->show();
        }
        loginWindow->close();
    }
    else{  //登陆失败
        QMessageBox::warning(loginWindow, tr("错误"),QString(tr("账户名或密码错误 || 账户名不存在")),QMessageBox::Cancel );
    }
}

void WindowController::signupInfoDeal(bool flag)
{
    if(flag){  //注册成功
        QMessageBox::information(signupWindow, tr("success"),QString(tr("注册成功！请登录")),QMessageBox::Ok );
    }
    else{  //注册失败
        QMessageBox::warning(loginWindow, tr("error"),QString(tr("注册失败")),QMessageBox::Cancel );
    }
}

void WindowController::findPswInfoDeal(QString q1,QString a1,QString q2,QString a2)
{
    findpswWindow->receiverFindPasswordQandA(q1, a1, q2, a2);
}

void WindowController::pswResetInfoDeal(bool flag)
{
    if(flag)  //密码修改成功
    {
        QMessageBox::information(signupWindow, tr("success"),QString(tr("密码修改成功！请登录")),QMessageBox::Ok );
    }
    else
    {
        QMessageBox::information(signupWindow, tr("failed"),QString(tr("密码修改失败，请重试")),QMessageBox::Ok );
    }
}

void WindowController::friendListInfoDeal(QStringList onlineFriList, QStringList offlineFroList)
{
    friendListWindow->addFriendFunc(onlineFriList,offlineFroList);
}

void WindowController::cTocInfoDeal(QString msgText, QString senderName, QString msgTime)
{
    for(int i=0; i<chatBoxList.count(); i++)
    {
        if(!senderName.compare(chatBoxList.at(i)->contacterName))  //匹配上了
        {
            chatBoxList.at(i)->friButton->setStyleSheet("QToolButton{background-color: rgb(225, 126, 126, 80);}");
            QString str;
            str.append(senderName);
            str.append("  ");
            str.append(msgTime);
            chatBoxList.at(i)->chatWindow->getTextBrowser()->addItem(str);
            chatBoxList.at(i)->chatWindow->getTextBrowser()->addItem(msgText);
            //滚轮
            chatBoxList.at(i)->chatWindow->getTextBrowser()->scrollToBottom();
        }
    }
}

void WindowController::cTocInfoDeal_groupMessage(QString msgText, QString senderName, QString msgTime)
{
    for(int i=0; i<chatBoxList.count(); i++)
    {
        if(!Message::ServerName.compare(chatBoxList.at(i)->contacterName))  //匹配上了
        {
            QString str;
            str.append(senderName);
            str.append("  ");
            str.append(msgTime);
            chatBoxList.at(i)->chatWindow->getTextBrowser()->addItem(str);
            chatBoxList.at(i)->chatWindow->getTextBrowser()->addItem(msgText);
        }
    }
}

void WindowController::friendApplyAns(bool flag, QString senderName)  //发出去的好友申请收到了回应 弹出提示框即可
{
    if(flag)  //对方同意 弹出框 重新申请好友列表
    {
        QMessageBox::information(friendListWindow, tr("success"),QString(tr("%1同意了你的好友申请，你们可以开始对话啦！").arg(senderName)),QMessageBox::Ok );
        //重新申请好友列表
//        friendListWindow->vector.clear();
//        friendListWindow->vector2.clear();
        friendListWindow->close();
        friendListWindow->destroyed();
        friendListWindow = new FriendList();
        friendListWindow->show();
        User_TcpConnect_Client::getInstance()->friendListToMsgText(User_TcpConnect_Client::getInstance()->getUserName());
    }
    //拒绝了可以不提示？
    else{
        QMessageBox::information(friendListWindow, tr("failed"),QString(tr("%1不太想和你成为朋友").arg(senderName)),QMessageBox::Ok );
    }
}

void WindowController::reqToMakeFriend(QString senderName)
{
    int choose;
    choose= QMessageBox::information(friendListWindow, tr("好友申请"),QString(tr("%1申请添加你为好友，是否同意？").arg(senderName)),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(choose == QMessageBox::Yes)
    {
        //同意后重新申请好友列表
        User_TcpConnect_Client::getInstance()->ansToFriendRequest(User_TcpConnect_Client::getInstance()->getUserName(),senderName,Message::AnswerType::TRUE);

    }
    else
    {
        //不同意
        User_TcpConnect_Client::getInstance()->ansToFriendRequest(User_TcpConnect_Client::getInstance()->getUserName(),senderName,Message::AnswerType::FALSE);
    }
}

void WindowController::friendListUpdate()
{
//    friendListWindow->vector.clear();
//    friendListWindow->vector2.clear();
    friendListWindow->close();
    friendListWindow->destroyed();
    friendListWindow = new FriendList();
    friendListWindow->show();
    User_TcpConnect_Client::getInstance()->friendListToMsgText(User_TcpConnect_Client::getInstance()->getUserName());
}


