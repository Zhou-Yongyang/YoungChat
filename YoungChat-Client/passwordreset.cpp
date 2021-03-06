#include "ui_passwordreset.h"

#include "loginwindow.h"
#include "networkconnection.h"
#include "register.h"
#include "passwordreset.h"
#include "findpasswordapply.h"
#include "chatdialog.h"
#include "friendlist.h"

#include "windowcontroller.h"
#include "user_tcpconnect_client.h"

PasswordReset::PasswordReset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordReset)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("YoungChat"));
    this->setWindowIcon(QIcon(":/new/prefix1/Background/IC.png"));
    ui->pButtonOk->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->pButtonCancel->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->PasswordEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->PasswordConfirmEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");

}

PasswordReset::~PasswordReset()
{
    delete ui;
}

bool PasswordReset::CheckPwd()
{
    QRegExp rx;
    bool flag = true;
    rx.setPatternSyntax(QRegExp::RegExp);
    //?????????????????????????????????????????????
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //??????????????????????????????????????????????????????????????????????????????
    rx.setPattern(QString("^[A-Za-z0-9]+$"));
    if(Res_password1.isEmpty())  //????????????????????????????????????
    {
        ui->warningLable->setText("??????????????????!");
        ui->warningLable->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    else if(!rx.exactMatch(Res_password1))
    {
        ui->warningLable->setText("?????????????????????????????????");
        ui->warningLable->setStyleSheet("color: rgb(255, 78, 25);");
        return false;

    }
    else if(Res_password1.size()<6 || Res_password1.size()>18)
    {
        ui->warningLable->setText("???????????????????????????[6,18]???");
        ui->warningLable->setStyleSheet("color: rgb(255, 78, 25);");
        return false;

    }
    if(Res_password2.isEmpty())  //????????????????????????????????????
    {
        ui->warningLable->setText("??????????????????!");
        ui->warningLable->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(0 != Res_password1.compare(Res_password2) )
    {
        ui->warningLable->setText("?????????????????????");
        ui->warningLable->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    return flag;
}

void PasswordReset::on_pButtonOk_clicked()
{
    Res_password1 = ui->PasswordEdit->text();
    Res_password2 = ui->PasswordConfirmEdit->text();
    if(CheckPwd())
    {
        //??????
        User_TcpConnect_Client::getInstance()->resetPswToMsgText(User_TcpConnect_Client::getInstance()->getUserName(),Res_password1);
    }
//    Loginwindow* login = new Loginwindow;
//    login->show();
//    this->close();
}

void PasswordReset::on_pButtonCancel_clicked()
{
    this->close();
}
