/********************************************************************************
** Form generated from reading UI file 'findpasswordapply.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPASSWORDAPPLY_H
#define UI_FINDPASSWORDAPPLY_H

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

class Ui_FindPasswordApply
{
public:
    QPushButton *pButtonCancel;
    QLineEdit *Acount;
    QPushButton *sendName;
    QPushButton *pButtonOk;
    QLabel *Question2;
    QLabel *Question1;
    QLabel *label;
    QLabel *Designedby;
    QLineEdit *Answer2content;
    QLabel *Username;
    QLineEdit *Answer1content;

    void setupUi(QWidget *FindPasswordApply)
    {
        if (FindPasswordApply->objectName().isEmpty())
            FindPasswordApply->setObjectName(QStringLiteral("FindPasswordApply"));
        FindPasswordApply->resize(640, 560);
        FindPasswordApply->setMinimumSize(QSize(640, 560));
        FindPasswordApply->setMaximumSize(QSize(640, 560));
        pButtonCancel = new QPushButton(FindPasswordApply);
        pButtonCancel->setObjectName(QStringLiteral("pButtonCancel"));
        pButtonCancel->setGeometry(QRect(320, 480, 91, 20));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
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
        Acount = new QLineEdit(FindPasswordApply);
        Acount->setObjectName(QStringLiteral("Acount"));
        Acount->setGeometry(QRect(220, 100, 193, 33));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        Acount->setFont(font1);
        Acount->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        sendName = new QPushButton(FindPasswordApply);
        sendName->setObjectName(QStringLiteral("sendName"));
        sendName->setGeometry(QRect(410, 100, 91, 31));
        sendName->setFont(font);
        sendName->setStyleSheet(QLatin1String("QPushButton\n"
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
        pButtonOk = new QPushButton(FindPasswordApply);
        pButtonOk->setObjectName(QStringLiteral("pButtonOk"));
        pButtonOk->setGeometry(QRect(190, 480, 91, 20));
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
        Question2 = new QLabel(FindPasswordApply);
        Question2->setObjectName(QStringLiteral("Question2"));
        Question2->setGeometry(QRect(120, 330, 241, 31));
        Question2->setFont(font);
        Question1 = new QLabel(FindPasswordApply);
        Question1->setObjectName(QStringLiteral("Question1"));
        Question1->setGeometry(QRect(120, 180, 201, 31));
        Question1->setFont(font);
        label = new QLabel(FindPasswordApply);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 640, 560));
        label->setMinimumSize(QSize(640, 560));
        label->setMaximumSize(QSize(640, 560));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Background/CHAT.png);"));
        Designedby = new QLabel(FindPasswordApply);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setGeometry(QRect(170, 530, 271, 31));
        Designedby->setFont(font);
        Answer2content = new QLineEdit(FindPasswordApply);
        Answer2content->setObjectName(QStringLiteral("Answer2content"));
        Answer2content->setGeometry(QRect(120, 390, 371, 30));
        Answer2content->setFont(font);
        Answer2content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        Username = new QLabel(FindPasswordApply);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(120, 100, 101, 31));
        Username->setFont(font);
        Answer1content = new QLineEdit(FindPasswordApply);
        Answer1content->setObjectName(QStringLiteral("Answer1content"));
        Answer1content->setGeometry(QRect(120, 240, 371, 30));
        Answer1content->setFont(font);
        Answer1content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        label->raise();
        pButtonCancel->raise();
        Acount->raise();
        sendName->raise();
        pButtonOk->raise();
        Question2->raise();
        Question1->raise();
        Designedby->raise();
        Answer2content->raise();
        Username->raise();
        Answer1content->raise();

        retranslateUi(FindPasswordApply);

        QMetaObject::connectSlotsByName(FindPasswordApply);
    } // setupUi

    void retranslateUi(QWidget *FindPasswordApply)
    {
        FindPasswordApply->setWindowTitle(QApplication::translate("FindPasswordApply", "Form", Q_NULLPTR));
        pButtonCancel->setText(QApplication::translate("FindPasswordApply", "Cancel", Q_NULLPTR));
        sendName->setText(QApplication::translate("FindPasswordApply", "Submit", Q_NULLPTR));
        pButtonOk->setText(QApplication::translate("FindPasswordApply", "Confirm", Q_NULLPTR));
        Question2->setText(QApplication::translate("FindPasswordApply", "Security Question2\357\274\232", Q_NULLPTR));
        Question1->setText(QApplication::translate("FindPasswordApply", "Sercurity Question1\357\274\232", Q_NULLPTR));
        label->setText(QString());
        Designedby->setText(QApplication::translate("FindPasswordApply", "Designed by Young Inc \302\251 2021 ", Q_NULLPTR));
        Username->setText(QApplication::translate("FindPasswordApply", "Username\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindPasswordApply: public Ui_FindPasswordApply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPASSWORDAPPLY_H
