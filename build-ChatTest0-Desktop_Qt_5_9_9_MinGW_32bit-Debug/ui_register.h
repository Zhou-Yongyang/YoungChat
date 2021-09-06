/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *Question1;
    QLineEdit *Answer2content;
    QLabel *PasswordConfirm;
    QPushButton *pButtonCancel;
    QToolButton *toolButton;
    QLabel *label;
    QLineEdit *Answer1content;
    QLabel *Question2;
    QLabel *Designedby;
    QLabel *Answer1;
    QLabel *Answer2;
    QLabel *Username;
    QLabel *Username_2;
    QLineEdit *Question1Content;
    QLineEdit *Question2Content;
    QLineEdit *PasswordEdit;
    QLabel *Password;
    QLineEdit *PasswordConfirmEdit;
    QLineEdit *Acount;
    QPushButton *pButtonOk;
    QLabel *Username_3;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(800, 700);
        Question1 = new QLabel(Register);
        Question1->setObjectName(QStringLiteral("Question1"));
        Question1->setGeometry(QRect(80, 350, 201, 31));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        Question1->setFont(font);
        Answer2content = new QLineEdit(Register);
        Answer2content->setObjectName(QStringLiteral("Answer2content"));
        Answer2content->setGeometry(QRect(80, 590, 371, 30));
        Answer2content->setFont(font);
        Answer2content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        PasswordConfirm = new QLabel(Register);
        PasswordConfirm->setObjectName(QStringLiteral("PasswordConfirm"));
        PasswordConfirm->setGeometry(QRect(80, 280, 161, 31));
        PasswordConfirm->setFont(font);
        pButtonCancel = new QPushButton(Register);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(670, 630, 91, 20));
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
        toolButton = new QToolButton(Register);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(400, 160, 150, 150));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Pic/a3t.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(150, 150));
        toolButton->setAutoRaise(true);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 800, 700));
        label->setMinimumSize(QSize(800, 700));
        label->setMaximumSize(QSize(800, 700));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Background/CHAT.png);"));
        Answer1content = new QLineEdit(Register);
        Answer1content->setObjectName(QStringLiteral("Answer1content"));
        Answer1content->setGeometry(QRect(80, 450, 371, 30));
        Answer1content->setFont(font);
        Answer1content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Question2 = new QLabel(Register);
        Question2->setObjectName(QStringLiteral("Question2"));
        Question2->setGeometry(QRect(80, 490, 191, 31));
        Question2->setFont(font);
        Designedby = new QLabel(Register);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setGeometry(QRect(240, 670, 271, 31));
        Designedby->setFont(font);
        Answer1 = new QLabel(Register);
        Answer1->setObjectName(QStringLiteral("Answer1"));
        Answer1->setGeometry(QRect(80, 420, 261, 31));
        Answer1->setFont(font);
        Answer2 = new QLabel(Register);
        Answer2->setObjectName(QStringLiteral("Answer2"));
        Answer2->setGeometry(QRect(80, 560, 271, 31));
        Answer2->setFont(font);
        Username = new QLabel(Register);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(80, 120, 281, 31));
        Username->setFont(font);
        Username_2 = new QLabel(Register);
        Username_2->setObjectName(QStringLiteral("Username_2"));
        Username_2->setGeometry(QRect(400, 120, 281, 31));
        Username_2->setFont(font);
        Question1Content = new QLineEdit(Register);
        Question1Content->setObjectName(QStringLiteral("Question1Content"));
        Question1Content->setGeometry(QRect(80, 380, 371, 30));
        Question1Content->setFont(font);
        Question1Content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Question2Content = new QLineEdit(Register);
        Question2Content->setObjectName(QStringLiteral("Question2Content"));
        Question2Content->setGeometry(QRect(80, 520, 371, 30));
        Question2Content->setFont(font);
        Question2Content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        PasswordEdit = new QLineEdit(Register);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(80, 230, 190, 30));
        PasswordEdit->setFont(font);
        PasswordEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Password = new QLabel(Register);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(80, 200, 81, 31));
        Password->setFont(font);
        PasswordConfirmEdit = new QLineEdit(Register);
        PasswordConfirmEdit->setObjectName(QStringLiteral("PasswordConfirmEdit"));
        PasswordConfirmEdit->setGeometry(QRect(80, 310, 190, 30));
        PasswordConfirmEdit->setFont(font);
        PasswordConfirmEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Acount = new QLineEdit(Register);
        Acount->setObjectName(QStringLiteral("Acount"));
        Acount->setGeometry(QRect(80, 150, 190, 30));
        Acount->setFont(font);
        Acount->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        pButtonOk = new QPushButton(Register);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setGeometry(QRect(540, 630, 91, 20));
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
        Username_3 = new QLabel(Register);
        Username_3->setObjectName(QStringLiteral("Username_3"));
        Username_3->setGeometry(QRect(490, 590, 301, 31));
        label->raise();
        Question1->raise();
        Answer2content->raise();
        PasswordConfirm->raise();
        pButtonCancel->raise();
        toolButton->raise();
        Answer1content->raise();
        Question2->raise();
        Designedby->raise();
        Answer1->raise();
        Answer2->raise();
        Username->raise();
        Username_2->raise();
        Question1Content->raise();
        Question2Content->raise();
        PasswordEdit->raise();
        Password->raise();
        PasswordConfirmEdit->raise();
        Acount->raise();
        pButtonOk->raise();
        Username_3->raise();

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", Q_NULLPTR));
        Question1->setText(QApplication::translate("Register", "Security Question1\357\274\232", Q_NULLPTR));
        PasswordConfirm->setText(QApplication::translate("Register", "Confirm it\357\274\232", Q_NULLPTR));
        pButtonCancel->setText(QApplication::translate("Register", "Cancel", Q_NULLPTR));
        toolButton->setText(QString());
        label->setText(QString());
        Question2->setText(QApplication::translate("Register", "Security Question2\357\274\232", Q_NULLPTR));
        Designedby->setText(QApplication::translate("Register", "Designed by Young Inc \302\251 2021 ", Q_NULLPTR));
        Answer1->setText(QApplication::translate("Register", "Answer of Security Question1\357\274\232", Q_NULLPTR));
        Answer2->setText(QApplication::translate("Register", "Answer of Security Question2\357\274\232", Q_NULLPTR));
        Username->setText(QApplication::translate("Register", "Please select a user name\357\274\232", Q_NULLPTR));
        Username_2->setText(QApplication::translate("Register", "Please choose your profile photo\357\274\232", Q_NULLPTR));
        Password->setText(QApplication::translate("Register", "Code\357\274\232", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("Register", "Confirm", Q_NULLPTR));
        Username_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
