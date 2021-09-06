/********************************************************************************
** Form generated from reading UI file 'chatmix.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATMIX_H
#define UI_CHATMIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatmix
{
public:
    QPushButton *searchPushButton;
    QLabel *userLabel;
    QPushButton *transPushButton;
    QGridLayout *gridLayout;
    QPushButton *sendPushButton;
    QLabel *label;
    QTextBrowser *chatTextBrowser;
    QLabel *label_5;
    QTextEdit *chatTextEdit;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *userListTableWidget;

    void setupUi(QWidget *chatmix)
    {
        if (chatmix->objectName().isEmpty())
            chatmix->setObjectName(QStringLiteral("chatmix"));
        chatmix->resize(997, 664);
        searchPushButton = new QPushButton(chatmix);
        searchPushButton->setObjectName(QStringLiteral("searchPushButton"));
        searchPushButton->setGeometry(QRect(164, 100, 191, 26));
        searchPushButton->setFlat(true);
        userLabel = new QLabel(chatmix);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(401, 76, 121, 62));
        QFont font;
        font.setFamily(QStringLiteral("04b_21"));
        font.setPointSize(16);
        userLabel->setFont(font);
        userLabel->setAutoFillBackground(true);
        userLabel->setFrameShape(QFrame::NoFrame);
        userLabel->setFrameShadow(QFrame::Plain);
        userLabel->setAlignment(Qt::AlignCenter);
        transPushButton = new QPushButton(chatmix);
        transPushButton->setObjectName(QStringLiteral("transPushButton"));
        transPushButton->setGeometry(QRect(440, 450, 31, 23));
        transPushButton->setFlat(true);
        gridLayout = new QGridLayout(chatmix);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sendPushButton = new QPushButton(chatmix);
        sendPushButton->setObjectName(QStringLiteral("sendPushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        sendPushButton->setFont(font1);

        gridLayout->addWidget(sendPushButton, 6, 3, 1, 1);

        label = new QLabel(chatmix);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Likie Sun/Desktop/\345\276\256\344\277\241/img/bar.jpg")));

        gridLayout->addWidget(label, 0, 0, 7, 1);

        chatTextBrowser = new QTextBrowser(chatmix);
        chatTextBrowser->setObjectName(QStringLiteral("chatTextBrowser"));

        gridLayout->addWidget(chatTextBrowser, 1, 2, 1, 2);

        label_5 = new QLabel(chatmix);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Likie Sun/Desktop/\345\276\256\344\277\241/img/tool.jpg")));

        gridLayout->addWidget(label_5, 4, 2, 1, 2);

        chatTextEdit = new QTextEdit(chatmix);
        chatTextEdit->setObjectName(QStringLiteral("chatTextEdit"));

        gridLayout->addWidget(chatTextEdit, 3, 2, 1, 2);

        label_2 = new QLabel(chatmix);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Likie Sun/Desktop/\345\276\256\344\277\241/img/search.jpg")));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(chatmix);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Likie Sun/Desktop/\345\276\256\344\277\241/img/title.jpg")));

        gridLayout->addWidget(label_3, 0, 2, 1, 2);

        userListTableWidget = new QTableWidget(chatmix);
        if (userListTableWidget->columnCount() < 1)
            userListTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        userListTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        userListTableWidget->setObjectName(QStringLiteral("userListTableWidget"));
        QFont font2;
        font2.setPointSize(14);
        userListTableWidget->setFont(font2);
        userListTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userListTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userListTableWidget->setShowGrid(false);
        userListTableWidget->horizontalHeader()->setVisible(false);
        userListTableWidget->horizontalHeader()->setDefaultSectionSize(250);
        userListTableWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(userListTableWidget, 2, 2, 1, 1);


        retranslateUi(chatmix);

        QMetaObject::connectSlotsByName(chatmix);
    } // setupUi

    void retranslateUi(QWidget *chatmix)
    {
        chatmix->setWindowTitle(QApplication::translate("chatmix", "Form", Q_NULLPTR));
        searchPushButton->setText(QString());
        userLabel->setText(QString());
        transPushButton->setText(QString());
        sendPushButton->setText(QApplication::translate("chatmix", "\345\217\221 \351\200\201(S)", Q_NULLPTR));
        label->setText(QString());
        label_5->setText(QString());
        chatTextEdit->setHtml(QApplication::translate("chatmix", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = userListTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("chatmix", "\345\234\250 \347\272\277 \345\245\275 \345\217\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chatmix: public Ui_chatmix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATMIX_H
