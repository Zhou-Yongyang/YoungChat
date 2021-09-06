/********************************************************************************
** Form generated from reading UI file 'passwordreset.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRESET_H
#define UI_PASSWORDRESET_H

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

class Ui_PasswordReset
{
public:
    QLabel *PasswordConfirm;
    QLabel *Designedby;
    QLabel *Password;
    QLineEdit *PasswordEdit;
    QLabel *warningLable;
    QLineEdit *PasswordConfirmEdit;
    QPushButton *pButtonCancel;
    QPushButton *pButtonOk;
    QLabel *label;

    void setupUi(QWidget *PasswordReset)
    {
        if (PasswordReset->objectName().isEmpty())
            PasswordReset->setObjectName(QStringLiteral("PasswordReset"));
        PasswordReset->resize(560, 500);
        PasswordReset->setMinimumSize(QSize(560, 500));
        PasswordReset->setMaximumSize(QSize(560, 500));
        PasswordConfirm = new QLabel(PasswordReset);
        PasswordConfirm->setObjectName(QStringLiteral("PasswordConfirm"));
        PasswordConfirm->setGeometry(QRect(190, 260, 171, 31));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        PasswordConfirm->setFont(font);
        Designedby = new QLabel(PasswordReset);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setGeometry(QRect(160, 480, 271, 21));
        Designedby->setFont(font);
        Password = new QLabel(PasswordReset);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(190, 180, 141, 31));
        Password->setFont(font);
        PasswordEdit = new QLineEdit(PasswordReset);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(190, 210, 190, 30));
        PasswordEdit->setFont(font);
        PasswordEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        warningLable = new QLabel(PasswordReset);
        warningLable->setObjectName(QStringLiteral("warningLable"));
        warningLable->setGeometry(QRect(190, 340, 291, 31));
        warningLable->setFont(font);
        PasswordConfirmEdit = new QLineEdit(PasswordReset);
        PasswordConfirmEdit->setObjectName(QStringLiteral("PasswordConfirmEdit"));
        PasswordConfirmEdit->setGeometry(QRect(190, 290, 190, 30));
        PasswordConfirmEdit->setFont(font);
        PasswordConfirmEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        pButtonCancel = new QPushButton(PasswordReset);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(310, 400, 91, 20));
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
        pButtonOk = new QPushButton(PasswordReset);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setGeometry(QRect(160, 400, 91, 20));
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
        label = new QLabel(PasswordReset);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 560, 500));
        label->setMinimumSize(QSize(560, 500));
        label->setMaximumSize(QSize(560, 500));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Background/BKSM.png);"));
        label->raise();
        PasswordConfirmEdit->raise();
        pButtonOk->raise();
        PasswordConfirm->raise();
        PasswordEdit->raise();
        Designedby->raise();
        Password->raise();
        pButtonCancel->raise();
        warningLable->raise();

        retranslateUi(PasswordReset);

        QMetaObject::connectSlotsByName(PasswordReset);
    } // setupUi

    void retranslateUi(QWidget *PasswordReset)
    {
        PasswordReset->setWindowTitle(QApplication::translate("PasswordReset", "Form", Q_NULLPTR));
        PasswordConfirm->setText(QApplication::translate("PasswordReset", "Please Confirm it\357\274\232", Q_NULLPTR));
        Designedby->setText(QApplication::translate("PasswordReset", "\357\274\232", Q_NULLPTR));
        Password->setText(QApplication::translate("PasswordReset", "Your New Code: \357\274\232", Q_NULLPTR));
        warningLable->setText(QString());
        pButtonCancel->setText(QApplication::translate("PasswordReset", "Cancel", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("PasswordReset", "Confirm", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PasswordReset: public Ui_PasswordReset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRESET_H
