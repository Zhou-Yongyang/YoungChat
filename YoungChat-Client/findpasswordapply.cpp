#include "findpasswordapply.h"
#include "ui_findpasswordapply.h"
#include "passwordreset.h"
#include "loginwindow.h"
#include "message.h"
#include "user_tcpconnect_client.h"
#include "windowcontroller.h"

FindPasswordApply::FindPasswordApply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindPasswordApply)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("YoungChat"));
    this->setWindowIcon(QIcon(":/new/prefix1/Background/IC.png"));
    ui->Answer1content->setPlaceholderText(QStringLiteral("Answer of Security Question1"));
    ui->Answer2content->setPlaceholderText(QStringLiteral("Answer of Security Question2"));
    ui->pButtonOk->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->sendName->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->pButtonCancel->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Acount->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Answer1content->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->Answer2content->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
}

FindPasswordApply::~FindPasswordApply()
{
    delete ui;
}

void FindPasswordApply::on_pButtonOk_clicked()
{
    qDebug() << ui->Answer1content->text();
    qDebug() << answer1;
    qDebug() << ui->Answer2content->text();
    qDebug() << answer2;

    if(ui->Answer1content->text() == answer1 && ui->Answer2content->text() == answer2)
    {
        PasswordReset* resetPS = WindowController::getInstance()->pwdresetWindow;
        if(resetPS == nullptr)
        {
            resetPS = new PasswordReset();
        }
        resetPS->show();
        this->close();
    }
    else{
        QMessageBox::warning(this, tr("错误"),QString(tr("密保答案有误")),QMessageBox::Cancel );
    }
}

void FindPasswordApply::on_pButtonCancel_clicked()
{
    this->close();
}

void FindPasswordApply::receiverFindPasswordQandA(QString q1, QString a1, QString q2, QString a2)
{
    question1 = q1;
    question2 = q2;
    answer1 = a1;
    answer2 = a2;

    //设置UI
    QString ques1,ques2;
    ques1.append("密保问题1：");
    ques1.append(q1);
    ques2.append("密保问题2：");
    ques2.append(q2);
    ui->Question1->setText(ques1);
    ui->Question2->setText(ques2);
}

void FindPasswordApply::on_sendName_clicked()
{
    userName = ui->Acount->text();
    User_TcpConnect_Client* tmpUser = User_TcpConnect_Client::getInstance();
    tmpUser->setUserName(userName);
    tmpUser->findPswToMsgText(userName);
}
