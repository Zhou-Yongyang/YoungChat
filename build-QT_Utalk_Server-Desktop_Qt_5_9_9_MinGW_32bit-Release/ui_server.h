/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *label_IPaddress;
    QListWidget *UserList;
    QComboBox *IPaddressChoosen;
    QPushButton *getIPAddressButton;
    QLabel *OnlineUser;
    QLabel *label;
    QPushButton *openServerButton;
    QPushButton *closeServerButton;
    QLabel *Designedby;
    QLineEdit *portEdit;
    QLabel *label_port;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(560, 500);
        label_IPaddress = new QLabel(Server);
        label_IPaddress->setObjectName(QStringLiteral("label_IPaddress"));
        label_IPaddress->setGeometry(QRect(20, 150, 121, 31));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        label_IPaddress->setFont(font);
        label_IPaddress->setAlignment(Qt::AlignCenter);
        UserList = new QListWidget(Server);
        UserList->setObjectName(QStringLiteral("UserList"));
        UserList->setGeometry(QRect(140, 250, 256, 192));
        IPaddressChoosen = new QComboBox(Server);
        IPaddressChoosen->setObjectName(QStringLiteral("IPaddressChoosen"));
        IPaddressChoosen->setGeometry(QRect(140, 150, 281, 31));
        getIPAddressButton = new QPushButton(Server);
        getIPAddressButton->setObjectName(QStringLiteral("getIPAddressButton"));
        getIPAddressButton->setGeometry(QRect(410, 340, 141, 20));
        getIPAddressButton->setFont(font);
        getIPAddressButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background:rgb(245,249,252);\n"
"    border-radius:2px;\n"
"    border: 1px solid rgb(173 , 173 , 173);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background:rgb(245,249,252);\n"
"    border-radius:2px;\n"
"	padding-left:2px;\n"
"	padding-top:2px;\n"
"    border: 1px solid rgb(173 , 173 , 173);\n"
"}"));
        OnlineUser = new QLabel(Server);
        OnlineUser->setObjectName(QStringLiteral("OnlineUser"));
        OnlineUser->setGeometry(QRect(20, 240, 111, 31));
        OnlineUser->setFont(font);
        label = new QLabel(Server);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 560, 500));
        label->setMinimumSize(QSize(560, 500));
        label->setMaximumSize(QSize(560, 500));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Pic/BKSM.png);"));
        openServerButton = new QPushButton(Server);
        openServerButton->setObjectName(QStringLiteral("openServerButton"));
        openServerButton->setGeometry(QRect(410, 380, 141, 20));
        openServerButton->setFont(font);
        openServerButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background:rgb(245,249,252);\n"
"    border-radius:2px;\n"
"    border: 1px solid rgb(173 , 173 , 173);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background:rgb(245,249,252);\n"
"    border-radius:2px;\n"
"	padding-left:2px;\n"
"	padding-top:2px;\n"
"    border: 1px solid rgb(173 , 173 , 173);\n"
"}"));
        closeServerButton = new QPushButton(Server);
        closeServerButton->setObjectName(QStringLiteral("closeServerButton"));
        closeServerButton->setGeometry(QRect(410, 420, 141, 20));
        closeServerButton->setFont(font);
        closeServerButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    background:rgb(245,249,252);\n"
"    border-radius:2px;\n"
"    border: 1px solid rgb(173 , 173 , 173);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background:rgb(245,249,252);\n"
"    border-radius:2px;\n"
"	padding-left:2px;\n"
"	padding-top:2px;\n"
"    border: 1px solid rgb(173 , 173 , 173);\n"
"}"));
        Designedby = new QLabel(Server);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setGeometry(QRect(160, 465, 271, 31));
        Designedby->setFont(font);
        portEdit = new QLineEdit(Server);
        portEdit->setObjectName(QStringLiteral("portEdit"));
        portEdit->setGeometry(QRect(140, 190, 190, 30));
        label_port = new QLabel(Server);
        label_port->setObjectName(QStringLiteral("label_port"));
        label_port->setGeometry(QRect(80, 190, 51, 31));
        label_port->setFont(font);
        label->raise();
        label_IPaddress->raise();
        UserList->raise();
        IPaddressChoosen->raise();
        getIPAddressButton->raise();
        OnlineUser->raise();
        openServerButton->raise();
        closeServerButton->raise();
        Designedby->raise();
        portEdit->raise();
        label_port->raise();

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Form", Q_NULLPTR));
        label_IPaddress->setText(QApplication::translate("Server", "IP Address\357\274\232", Q_NULLPTR));
        getIPAddressButton->setText(QApplication::translate("Server", "Get IPAddress", Q_NULLPTR));
        OnlineUser->setText(QApplication::translate("Server", "Online User\357\274\232", Q_NULLPTR));
        label->setText(QString());
        openServerButton->setText(QApplication::translate("Server", "Start", Q_NULLPTR));
        closeServerButton->setText(QApplication::translate("Server", "Close", Q_NULLPTR));
        Designedby->setText(QApplication::translate("Server", "Designed by Young Inc \302\251 2021 ", Q_NULLPTR));
        label_port->setText(QApplication::translate("Server", "Port\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
