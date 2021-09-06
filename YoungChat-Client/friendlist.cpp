
#include "ui_friendlist.h"
#include "friendlist.h"
#include "loginwindow.h"
#include "chatdialog.h"

#include "windowcontroller.h"
#include "user_tcpconnect_client.h"

#include "eachchatbox.h"


void setSearchEdit(QLineEdit* searchEdit, QPushButton* searchButton);

FriendList::FriendList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendList)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("YoungChat"));
    this->setWindowIcon(QIcon(":/new/prefix1/Background/IC.png"));
    setSearchEdit(ui->searchEdit, ui->sendFriendApply);
    ui->searchEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225, 80);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                               "QLineEdit:hover{background-color:rgb(229, 241, 251, 80); color: black;}"
                                               "QLineEdit:pressed{background-color:rgb(204, 228, 247, 80);border-style: inset;}");

}

void setSearchEdit(QLineEdit* searchEdit, QPushButton* sendFriendApply)
{
    QLineEdit* m_pSearchLineEdit = searchEdit;
    QPushButton *pSearchButton = sendFriendApply;

    pSearchButton->setCursor(Qt::PointingHandCursor);
    pSearchButton->setFixedSize(51, 51);
    pSearchButton->setToolTip(QStringLiteral("搜索"));
     pSearchButton->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/Pic/ar1); background:transparent;} \
                                         QPushButton:hover{border-image:url(:/new/prefix1/Pic/ar0)} \
                                         QPushButton:pressed{border-image:url(:/new/prefix1/Pic/ar0)}");

    //防止文本框输入内容位于按钮之下
    QMargins margins = m_pSearchLineEdit->textMargins();
    m_pSearchLineEdit->setTextMargins(margins.left(), margins.top(), pSearchButton->width(), margins.bottom());
    m_pSearchLineEdit->setPlaceholderText(QStringLiteral("Please enter your search content"));

    QHBoxLayout *pSearchLayout = new QHBoxLayout();
    pSearchLayout->addStretch();
    pSearchLayout->addWidget(pSearchButton);
    pSearchLayout->setSpacing(0);
    pSearchLayout->setContentsMargins(0, 0, 0, 0);
    m_pSearchLineEdit->setLayout(pSearchLayout);
}

FriendList::~FriendList()
{
    delete ui;
}

void FriendList::on_pushButton_clicked()
{
    ChatDialog* chat = new ChatDialog;
    chat->show();
}

void FriendList::addFriendFunc(QStringList online, QStringList offline)
{
    if(WindowController::getInstance()->FirstLoginFlag == true)
        User_TcpConnect_Client::getInstance()->cTosToMsgText(User_TcpConnect_Client::getInstance()->getUserName());
        WindowController::getInstance()->FirstLoginFlag = false;  //请求冗余消息 发送一条

    vector.clear();
    vector2.clear();
    //online
    for(int i=0; i<online.count(); i++)
    {
        EachChatBox* chatBox = new EachChatBox(online.at(i));

        QToolButton *btn = chatBox->friButton;
        //btn->setToolButtonStyle();
        vector.push_back(btn);

        btn->setIcon(QPixmap(QString(":/new/prefix1/Background/%1").arg(QString::number(i%10))));
        //btn->setIconSize(QPixmap(QString(":/new/prefix1/Background/%1").arg(QString::number(i%10))).size());
        btn->setIconSize(QSize (65,65));
        btn->setStyleSheet("QToolButton{background-color: rgb(225, 225, 225, 80);}");
        btn->setAutoRaise(true);
        btn->setText(QString("%1").arg(online[i]));
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->OnlineList->addWidget(btn);
        chatBox->friButton = btn;

        WindowController::getInstance()->chatBoxList.append(chatBox);

    }
    //offline

    for(int i=0; i<offline.count(); i++)
    {
        EachChatBox* chatBox = new EachChatBox(offline.at(i));
        QToolButton *btn = chatBox->friButton;
        btn->setIcon(QPixmap(QString(":/new/prefix1/Background/%1").arg(QString::number((i+5)%10))));
        btn->setIconSize(QSize (65,65));
        btn->setStyleSheet("QToolButton{background-color: rgb(225, 225, 225, 80);}");
        btn->setAutoRaise(true);
        btn->setText(QString("%1").arg(offline[i]));
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->OfflineList->addWidget(btn);
        //btn->setToolButtonStyle();
        vector2.push_back(btn);
        chatBox->friButton = btn;

        WindowController::getInstance()->chatBoxList.append(chatBox);
    }
    //弹簧
    ui->OnlineList->addStretch();
    ui->OfflineList->addStretch();
}

void FriendList::on_sendFriendApply_clicked()
{
    QString receiveName = ui->searchEdit->text();
    User_TcpConnect_Client::getInstance()->makeFriReqText(User_TcpConnect_Client::getInstance()->getUserName(),receiveName);
    QMessageBox::information(this, tr("success"),QString(tr("申请成功")),QMessageBox::Ok );
}

void FriendList::on_pushButton_7_clicked()
{
    WindowController::getInstance()->friendListUpdate();
}
