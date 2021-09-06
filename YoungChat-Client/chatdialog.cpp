#include "chatdialog.h"
#include "ui_chatdialog.h"
#include "windowcontroller.h"
#include "user_tcpconnect_client.h"
#include <QDebug>
#include <QListWidget>

ChatDialog::ChatDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatDialog)
{
    qDebug() << "ChatDialog this point" << this;
    ui->setupUi(this);
    this->setWindowTitle(QString("YoungChat"));
    this->setWindowIcon(QIcon(":/new/prefix1/Background/IC.png"));
    //ui->msgTxtEdit->setStyleSheet("background:transparent");
   // ui->msgBrowser->setStyleSheet("background:transparent");
    //ui->usrTblWidget->setStyleSheet("background:transparent");
    //ui->nameBrowser->setStyleSheet("background:transparent");
    ui->msgTxtEdit->setPlaceholderText(QStringLiteral("Please start the conversation here."));
    ui->exitBtn->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->sendBtn->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}");


}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::on_exitBtn_clicked()
{
    this->close();
}

void ChatDialog::on_sendBtn_clicked()
{
    QString msgText, receiveName;
    msgText = ui->msgTxtEdit->toPlainText();
    receiveName = ui->nameBrowser->toPlainText();
    User_TcpConnect_Client::getInstance()->cTocToMsgText(User_TcpConnect_Client::getInstance()->getUserName(),receiveName,msgText);
    QDateTime current_date_time =QDateTime::currentDateTime();
    qDebug() << current_date_time;
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    qDebug() << current_date;
    QString str;
    str.append(User_TcpConnect_Client::getInstance()->getUserName());
    str.append("  ");
    str.append(current_date);
    qDebug() << str;
    ui->msgBrowser->addItem(str);
    ui->msgBrowser->addItem(msgText);
    ui->msgTxtEdit->clear();
}

QTextBrowser* ChatDialog::getLabel()
{
    return ui->nameBrowser;
}
QListWidget* ChatDialog::getTextBrowser()
{
   return ui->msgBrowser;
}
QTextEdit* ChatDialog::getTextEdit()
{
    return ui->msgTxtEdit;
}
