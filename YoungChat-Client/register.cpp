#include "register.h"
#include "ui_register.h"
#include "loginwindow.h"
#include "windowcontroller.h"
#include "user_tcpconnect_client.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
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
    ui->Question2Content->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->PasswordEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Question1Content->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Answer1content->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Answer2content->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->PasswordConfirmEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Acount->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
}

Register::~Register()
{
    delete ui;
}

bool Register::CheckPwd()
{
    userName = ui->Acount->text();//?????????
    firstPassWrd = ui->PasswordEdit->text();//????????????
    secondPassWrd = ui->PasswordConfirmEdit->text();//????????????
    QRegExp rx;
    QMessageBox msgBox;
    bool flag = true;
    if(0 == userName.size())
    {

        ui->Username->setText("?????????????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(userName.size() > 21)
    {
        //            warnStr += "?????????????????????21???;";
        ui->Username->setText("??????????????????");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    rx.setPatternSyntax(QRegExp::RegExp);
    //?????????????????????????????????????????????
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //??????????????????????????????????????????????????????????????????????????????
    rx.setPattern(QString("^[A-Za-z0-9]+$"));
    if(firstPassWrd.isEmpty())  //????????????????????????????????????
    {
        ui->Username->setText("??????????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    else if(!rx.exactMatch(firstPassWrd))
    {
        ui->Username->setText("?????????????????????????????????");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;

    }
    else if(firstPassWrd.size()<6 || firstPassWrd.size()>18)
    {
        ui->Username->setText("???????????????????????????[6,18]???");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;

    }
    if(secondPassWrd.isEmpty())  //????????????????????????????????????
    {
        ui->Username->setText("????????????????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(0 != firstPassWrd.compare(secondPassWrd) )
    {
        ui->Username->setText("?????????????????????");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    secQues1 = ui->Question1Content->text();//????????????1
    secQues2 = ui->Question2Content->text();//????????????2
    secAns1 = ui->Answer1content->text();//????????????1
    secAns2 = ui->Answer2content->text();//????????????1
    if(secQues1.isEmpty())  //??????????????????1???????????????
    {
        ui->Username->setText("????????????1????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(secAns1.isEmpty())  //??????????????????1???????????????
    {
        ui->Username->setText("????????????1????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }if(secQues2.isEmpty())  //??????????????????2???????????????
    {
        ui->Username->setText("????????????2????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }if(secAns2.isEmpty())  //??????????????????2???????????????
    {
        ui->Username->setText("????????????2????????????!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    return flag;
}

void Register::on_pButtonOk_clicked()
{
    if(CheckPwd()){
        User_TcpConnect_Client::getInstance()->signupToMsgText(userName,firstPassWrd,secQues1,secAns1,secQues2,secAns2);
        Loginwindow* login = WindowController::getInstance()->loginWindow;
        if(login != nullptr)
        {
             login->show();
        }
        else   //??????????????????login->new,??????createLoginWindow
            login = new Loginwindow();
        this->close();
    }
}

void Register::on_pButtonCancel_clicked()
{
//    Loginwindow* login = WindowController::getInstance()->loginWindow;
//    login->show();
    this->close();
}
