#include "networkconnection.h"
#include "ui_networkconnection.h"

#include "loginwindow.h"
#include "user_tcpconnect_client.h"
#include "windowcontroller.h"

NetworkConnection::NetworkConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetworkConnection)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("YoungChat"));
    this->setWindowIcon(QIcon(":/new/prefix1/Background/IC.png"));
    ui->passwordEdit_IPaddress->setPlaceholderText(QStringLiteral("IP Address"));
    ui->passwordEdit_port->setPlaceholderText(QStringLiteral("Port"));
    ui->pButtonOk->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->pButtonCancel->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->passwordEdit_port->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
    ui->passwordEdit_IPaddress->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");
}

NetworkConnection::~NetworkConnection()
{
    delete ui;
}

bool NetworkConnection ::IsIPaddress(QString ip)

{
     QRegExp rx2("^(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])$");
     if(!rx2.exactMatch(ip))
     {
         return false;
     }
     return true;
}

bool NetworkConnection::isDigitStr(QString src)
{
    QRegExp portExp("^([0-9]|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])$");
    if(!portExp.exactMatch(src))
    {
        return false;
    }
    return true;
}


void NetworkConnection::on_pButtonOk_clicked()
{
    IPAddress = ui->passwordEdit_IPaddress->text();
    hostPort = ui->passwordEdit_port->text();
    if(IsIPaddress(IPAddress) && isDigitStr(hostPort))
    {
        qDebug()<<"if1";
        //向服务器发信
        qint16 pport = hostPort.toInt();
        User_TcpConnect_Client* tmpUser = User_TcpConnect_Client::getInstance();
        tmpUser->connectToServer(IPAddress,pport);
        //显示login界面

        if(tmpUser->isUserOnline())
        {
            WindowController::getInstance()->loginWindow->show();
                    this->close();
        }
        else
        {
            QMessageBox::warning(this, tr("错误"),QString(tr("IP地址或端口错误")),QMessageBox::Cancel );
            return;
        }
    }
    else if(IsIPaddress(IPAddress)){
        ui->label->setText("端口有误！");
        ui->label->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else if(isDigitStr(hostPort)){
        ui->label->setText("IP地址有误！");
        ui->label->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else{
        ui->label->setText("IP地址及端口有误！");
        ui->label->setStyleSheet("color: rgb(255, 78, 25);");
    }
//    Loginwindow* login = new Loginwindow;
//    login->show();
//    this->close();
}

void NetworkConnection::on_pButtonCancel_clicked()
{
    this->close();
}
