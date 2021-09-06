/********************************************************************************
** Form generated from reading UI file 'networkconnection.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKCONNECTION_H
#define UI_NETWORKCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkConnection
{
public:
    QLineEdit *passwordEdit_port;
    QLineEdit *passwordEdit_IPaddress;
    QLabel *Designedby;
    QPushButton *pButtonOk;
    QPushButton *pButtonCancel;
    QLabel *BK;
    QLabel *label;

    void setupUi(QWidget *NetworkConnection)
    {
        if (NetworkConnection->objectName().isEmpty())
            NetworkConnection->setObjectName(QStringLiteral("NetworkConnection"));
        NetworkConnection->resize(560, 500);
        passwordEdit_port = new QLineEdit(NetworkConnection);
        passwordEdit_port->setObjectName(QStringLiteral("passwordEdit_port"));
        passwordEdit_port->setGeometry(QRect(180, 340, 190, 30));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        passwordEdit_port->setFont(font);
        passwordEdit_port->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        passwordEdit_IPaddress = new QLineEdit(NetworkConnection);
        passwordEdit_IPaddress->setObjectName(QStringLiteral("passwordEdit_IPaddress"));
        passwordEdit_IPaddress->setGeometry(QRect(180, 270, 190, 30));
        passwordEdit_IPaddress->setFont(font);
        passwordEdit_IPaddress->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Designedby = new QLabel(NetworkConnection);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setGeometry(QRect(140, 470, 271, 31));
        Designedby->setFont(font);
        pButtonOk = new QPushButton(NetworkConnection);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setGeometry(QRect(120, 410, 91, 20));
        pButtonOk->setFont(font);
        pButtonOk->setStyleSheet(QLatin1String("QPushButton\n"
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
        pButtonCancel = new QPushButton(NetworkConnection);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(320, 410, 91, 20));
        pButtonCancel->setFont(font);
        pButtonCancel->setStyleSheet(QLatin1String("QPushButton\n"
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
        BK = new QLabel(NetworkConnection);
        BK->setObjectName(QStringLiteral("BK"));
        BK->setGeometry(QRect(0, 0, 560, 500));
        BK->setMinimumSize(QSize(560, 500));
        BK->setMaximumSize(QSize(560, 500));
        BK->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Background/BK1.png);"));
        label = new QLabel(NetworkConnection);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 310, 301, 20));
        BK->raise();
        passwordEdit_port->raise();
        passwordEdit_IPaddress->raise();
        Designedby->raise();
        pButtonOk->raise();
        pButtonCancel->raise();
        label->raise();

        retranslateUi(NetworkConnection);

        QMetaObject::connectSlotsByName(NetworkConnection);
    } // setupUi

    void retranslateUi(QWidget *NetworkConnection)
    {
        NetworkConnection->setWindowTitle(QApplication::translate("NetworkConnection", "Form", Q_NULLPTR));
        Designedby->setText(QApplication::translate("NetworkConnection", "Designed by Young Inc \302\251 2021 ", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("NetworkConnection", "Confirm", Q_NULLPTR));
        pButtonCancel->setText(QApplication::translate("NetworkConnection", "Cancle", Q_NULLPTR));
        BK->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NetworkConnection: public Ui_NetworkConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKCONNECTION_H
