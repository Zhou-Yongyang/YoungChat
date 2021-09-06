#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <QToolButton>
#include <QTimer>
#include <QDebug>

//下方文件名需改
#include "networkconnection.h"
#include "loginwindow.h"
#include "register.h"
#include "findpasswordapply.h"
#include "passwordreset.h"
#include "friendlist.h"
#include "answermessage.h"
#include"eachchatbox.h"

class WindowController : public QObject
{
    Q_OBJECT
public:
    explicit WindowController(QObject *parent = nullptr);
    static WindowController* getInstance()
    {
        if(instance == nullptr)
            instance = new WindowController();
        return instance;
    }
private:
    static WindowController* instance;
    //每个窗口建立指针
public:
    QList<EachChatBox*> chatBoxList;

    NetworkConnection* networkWindow;
    Loginwindow* loginWindow;
    Register* signupWindow;
    FindPasswordApply* findpswWindow;
    PasswordReset* pwdresetWindow;
    FriendList* friendListWindow;

    //窗口显示控制
    void createConnectToServerWindow();

    void createLoginWindow();

    void createSignupWindow();

    void createFindPswWindow();

    void createPwdResetWindow();

    void createFriendList();

    void createChatBox(QString contacterName);

    //一些反馈信息的后续操作
    void loginInfoDeal(bool flag);
    void signupInfoDeal(bool flag);
    void findPswInfoDeal(QString q1,QString a1,QString q2,QString a2);
    void pswResetInfoDeal(bool flag);
    void friendListInfoDeal(QStringList onlineFriList, QStringList offlineFroList);
    void cTocInfoDeal(QString msgText, QString senderName, QString msgTime);
    void cTocInfoDeal_groupMessage(QString msgText, QString senderName, QString msgTime);
    void friendApplyAns(bool flag, QString senderName);
    void reqToMakeFriend(QString senderName);

    bool FirstLoginFlag = true;
    //周期更新好友列表
    void friendListUpdate();


signals:

};

#endif // WINDOWCONTROLLER_H
