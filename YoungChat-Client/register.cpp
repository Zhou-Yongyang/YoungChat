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
    userName = ui->Acount->text();//用户名
    firstPassWrd = ui->PasswordEdit->text();//用户密码
    secondPassWrd = ui->PasswordConfirmEdit->text();//确认密码
    QRegExp rx;
    QMessageBox msgBox;
    bool flag = true;
    if(0 == userName.size())
    {

        ui->Username->setText("用户名不能为空!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(userName.size() > 21)
    {
        //            warnStr += "用户名长度超过21位;";
        ui->Username->setText("用户名过长！");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    rx.setPatternSyntax(QRegExp::RegExp);
    //对大小写字母敏感，即区分大小写
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //匹配格式为所有大小写字母和数字组成的字符串，位数不限
    rx.setPattern(QString("^[A-Za-z0-9]+$"));
    if(firstPassWrd.isEmpty())  //检测密码输入框是不是为空
    {
        ui->Username->setText("密码不能为空!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    else if(!rx.exactMatch(firstPassWrd))
    {
        ui->Username->setText("密码只能是数字或字母！");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;

    }
    else if(firstPassWrd.size()<6 || firstPassWrd.size()>18)
    {
        ui->Username->setText("密码长度范围必须是[6,18]！");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;

    }
    if(secondPassWrd.isEmpty())  //检测密码输入框是不是为空
    {
        ui->Username->setText("确认密码不能为空!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(0 != firstPassWrd.compare(secondPassWrd) )
    {
        ui->Username->setText("两次密码不一致");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    secQues1 = ui->Question1Content->text();//密保问题1
    secQues2 = ui->Question2Content->text();//密保问题2
    secAns1 = ui->Answer1content->text();//密保答案1
    secAns2 = ui->Answer2content->text();//密保答案1
    if(secQues1.isEmpty())  //检测密保问题1是不是为空
    {
        ui->Username->setText("密保问题1不能为空!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }
    if(secAns1.isEmpty())  //检测密保答案1是不是为空
    {
        ui->Username->setText("密保答案1不能为空!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }if(secQues2.isEmpty())  //检测密保问题2是不是为空
    {
        ui->Username->setText("密保问题2不能为空!");
        ui->Username->setStyleSheet("color: rgb(255, 78, 25);");
        return false;
    }if(secAns2.isEmpty())  //检测密保答案2是不是为空
    {
        ui->Username->setText("密保答案2不能为空!");
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
        else   //这里不应该是login->new,应该createLoginWindow
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
