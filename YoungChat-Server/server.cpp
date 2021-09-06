#include "server.h"
#include "ui_server.h"
#include "tcpserver.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    this->setWindowTitle("YoungChat-Server");
    tcpServer = TcpServer::gethand();
    connect(tcpServer, SIGNAL(sig_addIpListToUI()), this, SLOT(slot_addIPlistToUI()));
    connect(tcpServer, SIGNAL(sig_addUserToOnlineList(QString)), this, SLOT(slot_addUserToList(QString)));
}

Server::~Server()
{
    delete ui;
}


void Server::on_getIPAddressButton_clicked()
{
    qDebug()<< "try to getIPAddressList";
    tcpServer->getaddress();
}

void Server::slot_addIPlistToUI()
{
    qDebug() << "Slot_addIPlistToUI has been actived";
    for(int i = 0; i < tcpServer->IPlist.count(); i++)
    {
        ui->IPaddressChoosen->addItem(tcpServer->IPlist.at(i));
    }
}


void Server::slot_addUserToList(QString userName)
{
    /*
    QString str;
    str.append("UserName: ");
    str.append(userName);
    str.append(" SocketID: ");
    int id = 0;
    for(int i = 0; i < tcpServer->UserListExample.count();i++)
    {
        if(userName == tcpServer->UserListExample.at(i)->getUserName())
        {
            id = tcpServer->UserListExample.at(i)->getSocketID();
        }
    }*/
    ui->UserList->clear();
    for(int i = 0; i < tcpServer->UserListExample.count();i++)
    {
        ui->UserList->addItem("UserName: " + tcpServer->UserListExample.at(i)->getUserName() + " SocketID: " + QString::number(tcpServer->UserListExample.at(i)->getSocketID()));
    }


}


void Server::on_openServerButton_clicked()
{
   if(tcpServer->openTcpServer(ui->IPaddressChoosen->currentText(), ui->portEdit->text()) || tcpServer->isListening())
       ui->openServerButton->setText("Runing");
   else if(!tcpServer->isListening())
       qDebug("服务错误");
}

void Server::on_closeServerButton_clicked()
{
    tcpServer->closeTcpServer();
    if(!tcpServer->listen())
    {
        ui->openServerButton->setText("Start");
    }
}
