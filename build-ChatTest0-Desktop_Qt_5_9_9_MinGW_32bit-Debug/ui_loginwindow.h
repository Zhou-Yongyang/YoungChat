/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loginwindow
{
public:
    QLabel *Designedby;
    QLineEdit *PasswordEdit;
    QLineEdit *Account;
    QPushButton *FogetPassword;
    QPushButton *ButtonRegistAccount;
    QLabel *label;
    QCheckBox *RememberPsd;
    QCheckBox *AutoLogin;
    QPushButton *LoginButton;

    void setupUi(QWidget *Loginwindow)
    {
        if (Loginwindow->objectName().isEmpty())
            Loginwindow->setObjectName(QStringLiteral("Loginwindow"));
        Loginwindow->resize(560, 500);
        Loginwindow->setStyleSheet(QStringLiteral(""));
        Designedby = new QLabel(Loginwindow);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setGeometry(QRect(160, 470, 262, 26));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        Designedby->setFont(font);
        PasswordEdit = new QLineEdit(Loginwindow);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(170, 340, 193, 31));
        PasswordEdit->setFont(font);
        PasswordEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Account = new QLineEdit(Loginwindow);
        Account->setObjectName(QStringLiteral("Account"));
        Account->setEnabled(true);
        Account->setGeometry(QRect(170, 290, 193, 33));
        Account->setFont(font);
        Account->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Account->setClearButtonEnabled(false);
        FogetPassword = new QPushButton(Loginwindow);
        FogetPassword->setObjectName(QStringLiteral("FogetPassword"));
        FogetPassword->setGeometry(QRect(390, 340, 91, 31));
        FogetPassword->setFont(font);
        FogetPassword->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        ButtonRegistAccount = new QPushButton(Loginwindow);
        ButtonRegistAccount->setObjectName(QStringLiteral("ButtonRegistAccount"));
        ButtonRegistAccount->setGeometry(QRect(390, 290, 91, 31));
        ButtonRegistAccount->setFont(font);
        ButtonRegistAccount->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        label = new QLabel(Loginwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 560, 500));
        label->setMinimumSize(QSize(560, 500));
        label->setMaximumSize(QSize(560, 500));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Background/BK1.png);"));
        RememberPsd = new QCheckBox(Loginwindow);
        RememberPsd->setObjectName(QStringLiteral("RememberPsd"));
        RememberPsd->setGeometry(QRect(150, 380, 124, 32));
        RememberPsd->setFont(font);
        AutoLogin = new QCheckBox(Loginwindow);
        AutoLogin->setObjectName(QStringLiteral("AutoLogin"));
        AutoLogin->setGeometry(QRect(310, 380, 122, 32));
        AutoLogin->setFont(font);
        LoginButton = new QPushButton(Loginwindow);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(240, 420, 80, 37));
        LoginButton->setFont(font);
        label->raise();
        Designedby->raise();
        PasswordEdit->raise();
        Account->raise();
        FogetPassword->raise();
        ButtonRegistAccount->raise();
        RememberPsd->raise();
        AutoLogin->raise();
        LoginButton->raise();

        retranslateUi(Loginwindow);

        QMetaObject::connectSlotsByName(Loginwindow);
    } // setupUi

    void retranslateUi(QWidget *Loginwindow)
    {
        Loginwindow->setWindowTitle(QApplication::translate("Loginwindow", "Form", Q_NULLPTR));
        Designedby->setText(QApplication::translate("Loginwindow", "Designed by Young Inc \302\251 2021 ", Q_NULLPTR));
        Account->setText(QString());
        FogetPassword->setText(QApplication::translate("Loginwindow", "Find Code", Q_NULLPTR));
        ButtonRegistAccount->setText(QApplication::translate("Loginwindow", "Register", Q_NULLPTR));
        label->setText(QString());
        RememberPsd->setText(QApplication::translate("Loginwindow", "Remember", Q_NULLPTR));
        AutoLogin->setText(QApplication::translate("Loginwindow", "Auto-login", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("Loginwindow", "Login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Loginwindow: public Ui_Loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
