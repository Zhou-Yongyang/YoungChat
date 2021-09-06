
#include "ui_loginwindow.h"
#include "loginwindow.h"
#include "networkconnection.h"
#include "register.h"
#include "passwordreset.h"
#include "findpasswordapply.h"
#include "chatdialog.h"
#include "friendlist.h"


#include "windowcontroller.h"
#include "user_tcpconnect_client.h"

Loginwindow::Loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loginwindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("YoungChat"));
    this->setWindowIcon(QIcon(":/new/prefix1/Background/IC.png"));
    ui->Account->setPlaceholderText(QStringLiteral("Username"));
    ui->PasswordEdit->setPlaceholderText(QStringLiteral("Code"));
    ui->ButtonRegistAccount->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->FogetPassword->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->LoginButton->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Account->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->PasswordEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");

}

Loginwindow::~Loginwindow()
{
    delete ui;
}

void Loginwindow::on_ButtonRegistAccount_clicked()
{
    Register* registe = WindowController::getInstance()->signupWindow;
    if(registe == nullptr)
    {
        registe = new Register();
    }
    registe->show();
    //this->close();
}

void Loginwindow::on_FogetPassword_clicked()
{
    FindPasswordApply* findPSA = WindowController::getInstance()->findpswWindow;
        if(findPSA == nullptr)
        {
            findPSA = new FindPasswordApply();
        }
        findPSA->show();
        //this->close();
}

void Loginwindow::on_LoginButton_clicked()
{
//    FriendList* friendl = new FriendList;
//    friendl->show();
//    this->close();
    userName = ui->Account->text();
    userPassword = ui->PasswordEdit->text();
    if(0 == userName.size() || 0 == userPassword.size()){
        QMessageBox::warning(this, tr("错误"),QString(tr("账户名或密码不为空")),QMessageBox::Cancel );
    }
    else{
        //向服务端发登录请求
        User_TcpConnect_Client::getInstance()->loginToMsgText(userName,userPassword);
    }
}

void Loginwindow::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);          //背景图片透明度
    myPainter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/new/prefix1/C:/Users/Likie Sun/Desktop/QQ截图20210829171943.png)"));;

}



