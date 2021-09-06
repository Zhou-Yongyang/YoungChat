/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendList
{
public:
    QFrame *frame;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *OnlineList;
    QWidget *page_2;
    QVBoxLayout *OfflineList;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *sendFriendApply;
    QLineEdit *searchEdit;
    QLabel *label_2;

    void setupUi(QWidget *FriendList)
    {
        if (FriendList->objectName().isEmpty())
            FriendList->setObjectName(QStringLiteral("FriendList"));
        FriendList->resize(400, 800);
        frame = new QFrame(FriendList);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 150, 311, 641));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolBox = new QToolBox(frame);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 20, 271, 561));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        toolBox->setFont(font);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 271, 481));
        OnlineList = new QVBoxLayout(page);
        OnlineList->setObjectName(QStringLiteral("OnlineList"));
        toolBox->addItem(page, QStringLiteral("OnlineFriends"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 271, 481));
        OfflineList = new QVBoxLayout(page_2);
        OfflineList->setObjectName(QStringLiteral("OfflineList"));
        toolBox->addItem(page_2, QStringLiteral("OfflineList"));
        verticalLayoutWidget = new QWidget(FriendList);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(330, 0, 71, 801));
        verticalLayoutWidget->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(61, 61));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Background/touxiang .png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon);
        pushButton_5->setIconSize(QSize(61, 61));
        pushButton_5->setFlat(true);

        verticalLayout_2->addWidget(pushButton_5);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(55, 55));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Pic/afx.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);

        verticalLayout_2->addWidget(pushButton);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(55, 55));
        pushButton_6->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Pic/a9s.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(30, 30));
        pushButton_6->setFlat(true);

        verticalLayout_2->addWidget(pushButton_6);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(55, 55));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/Pic/ana.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(30, 30));
        pushButton_3->setFlat(true);

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(55, 55));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/Pic/ao3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(30, 30));
        pushButton_4->setFlat(true);

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(55, 55));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/Pic/ard.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);
        pushButton_2->setIconSize(QSize(30, 30));
        pushButton_2->setFlat(true);

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 200));
        pushButton_10->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        pushButton_10->setFlat(true);

        verticalLayout_2->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(55, 55));
        pushButton_9->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/Pic/amo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon6);
        pushButton_9->setIconSize(QSize(30, 30));
        pushButton_9->setFlat(true);

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(55, 55));
        pushButton_7->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/Pic/anm.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon7);
        pushButton_7->setIconSize(QSize(30, 30));
        pushButton_7->setFlat(true);

        verticalLayout_2->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(55, 55));
        pushButton_8->setStyleSheet(QStringLiteral("background-color: rgb(44, 44, 44, 220);"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/Pic/anb.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon8);
        pushButton_8->setIconSize(QSize(30, 30));
        pushButton_8->setFlat(true);

        verticalLayout_2->addWidget(pushButton_8);

        sendFriendApply = new QPushButton(FriendList);
        sendFriendApply->setObjectName(QStringLiteral("sendFriendApply"));
        sendFriendApply->setGeometry(QRect(0, 80, 51, 51));
        searchEdit = new QLineEdit(FriendList);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setGeometry(QRect(0, 76, 331, 71));
        searchEdit->setFont(font);
        label_2 = new QLabel(FriendList);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 400, 800));
        label_2->setMinimumSize(QSize(400, 800));
        label_2->setMaximumSize(QSize(400, 800));
        label_2->setStyleSheet(QLatin1String("\n"
"border-image: url(:/new/prefix1/Background/FL2.png);"));
        label_2->raise();
        frame->raise();
        verticalLayoutWidget->raise();
        sendFriendApply->raise();
        searchEdit->raise();

        retranslateUi(FriendList);

        toolBox->setCurrentIndex(1);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(FriendList);
    } // setupUi

    void retranslateUi(QWidget *FriendList)
    {
        FriendList->setWindowTitle(QApplication::translate("FriendList", "Form", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("FriendList", "OnlineFriends", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("FriendList", "OfflineList", Q_NULLPTR));
        pushButton_5->setText(QString());
        pushButton->setText(QString());
        pushButton_6->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_2->setText(QString());
        pushButton_10->setText(QString());
        pushButton_9->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        sendFriendApply->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendList: public Ui_FriendList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
