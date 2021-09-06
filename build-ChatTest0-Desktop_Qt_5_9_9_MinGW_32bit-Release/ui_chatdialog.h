/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QTextBrowser *nameBrowser;
    QListWidget *msgBrowser;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTBtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *sendTBtn;
    QToolButton *saveTBtn;
    QToolButton *clearTBtn;
    QTextEdit *msgTxtEdit;
    QTableWidget *usrTblWidget;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sendBtn;
    QLabel *Designedby;
    QPushButton *exitBtn;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(950, 750);
        ChatDialog->setMinimumSize(QSize(950, 750));
        ChatDialog->setMaximumSize(QSize(950, 750));
        layoutWidget = new QWidget(ChatDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 921, 651));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameBrowser = new QTextBrowser(layoutWidget);
        nameBrowser->setObjectName(QStringLiteral("nameBrowser"));
        nameBrowser->setMinimumSize(QSize(0, 50));
        nameBrowser->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        nameBrowser->setFont(font);

        verticalLayout->addWidget(nameBrowser);

        msgBrowser = new QListWidget(layoutWidget);
        msgBrowser->setObjectName(QStringLiteral("msgBrowser"));
        msgBrowser->setMinimumSize(QSize(0, 400));
        msgBrowser->setFont(font);

        verticalLayout->addWidget(msgBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fontCbx = new QFontComboBox(layoutWidget);
        fontCbx->setObjectName(QStringLiteral("fontCbx"));
        fontCbx->setFont(font);
        fontCbx->setStyleSheet(QStringLiteral(""));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        fontCbx->setCurrentFont(font1);

        horizontalLayout->addWidget(fontCbx);

        sizeCbx = new QComboBox(layoutWidget);
        sizeCbx->setObjectName(QStringLiteral("sizeCbx"));
        sizeCbx->setFont(font);
        sizeCbx->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(sizeCbx);

        boldTBtn = new QToolButton(layoutWidget);
        boldTBtn->setObjectName(QStringLiteral("boldTBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Pic/amz.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldTBtn->setIcon(icon);
        boldTBtn->setIconSize(QSize(26, 26));
        boldTBtn->setCheckable(true);
        boldTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(boldTBtn);

        italicTBtn = new QToolButton(layoutWidget);
        italicTBtn->setObjectName(QStringLiteral("italicTBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Pic/ao2.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicTBtn->setIcon(icon1);
        italicTBtn->setIconSize(QSize(26, 26));
        italicTBtn->setCheckable(true);
        italicTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(italicTBtn);

        underlineTBtn = new QToolButton(layoutWidget);
        underlineTBtn->setObjectName(QStringLiteral("underlineTBtn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Pic/a9n.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineTBtn->setIcon(icon2);
        underlineTBtn->setIconSize(QSize(26, 26));
        underlineTBtn->setCheckable(true);
        underlineTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(underlineTBtn);

        colorTBtn = new QToolButton(layoutWidget);
        colorTBtn->setObjectName(QStringLiteral("colorTBtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/Pic/tr.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorTBtn->setIcon(icon3);
        colorTBtn->setIconSize(QSize(26, 26));
        colorTBtn->setCheckable(false);
        colorTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(colorTBtn);

        sendTBtn = new QToolButton(layoutWidget);
        sendTBtn->setObjectName(QStringLiteral("sendTBtn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/Pic/ank.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendTBtn->setIcon(icon4);
        sendTBtn->setIconSize(QSize(26, 26));
        sendTBtn->setCheckable(false);
        sendTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(sendTBtn);

        saveTBtn = new QToolButton(layoutWidget);
        saveTBtn->setObjectName(QStringLiteral("saveTBtn"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/Pic/anp.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveTBtn->setIcon(icon5);
        saveTBtn->setIconSize(QSize(26, 26));
        saveTBtn->setCheckable(false);
        saveTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(saveTBtn);

        clearTBtn = new QToolButton(layoutWidget);
        clearTBtn->setObjectName(QStringLiteral("clearTBtn"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/Pic/a9w.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearTBtn->setIcon(icon6);
        clearTBtn->setIconSize(QSize(26, 26));
        clearTBtn->setCheckable(false);
        clearTBtn->setAutoRaise(true);

        horizontalLayout->addWidget(clearTBtn);


        verticalLayout->addLayout(horizontalLayout);

        msgTxtEdit = new QTextEdit(layoutWidget);
        msgTxtEdit->setObjectName(QStringLiteral("msgTxtEdit"));
        msgTxtEdit->setFont(font);

        verticalLayout->addWidget(msgTxtEdit);


        horizontalLayout_5->addLayout(verticalLayout);

        usrTblWidget = new QTableWidget(layoutWidget);
        if (usrTblWidget->columnCount() < 2)
            usrTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(255, 255, 255, 80));
        usrTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(255, 255, 255, 80));
        usrTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        usrTblWidget->setObjectName(QStringLiteral("usrTblWidget"));
        usrTblWidget->setMinimumSize(QSize(211, 560));
        usrTblWidget->setFont(font);
        usrTblWidget->setFrameShape(QFrame::NoFrame);
        usrTblWidget->setFrameShadow(QFrame::Plain);
        usrTblWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        usrTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        usrTblWidget->setShowGrid(false);

        horizontalLayout_5->addWidget(usrTblWidget);

        layoutWidget_2 = new QWidget(ChatDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 710, 921, 39));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sendBtn = new QPushButton(layoutWidget_2);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setFont(font);
        sendBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));

        horizontalLayout_3->addWidget(sendBtn);

        Designedby = new QLabel(layoutWidget_2);
        Designedby->setObjectName(QStringLiteral("Designedby"));
        Designedby->setFont(font);

        horizontalLayout_3->addWidget(Designedby);

        exitBtn = new QPushButton(layoutWidget_2);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setFont(font);
        exitBtn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255, 80);"));

        horizontalLayout_3->addWidget(exitBtn);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(2, 2);
        Designedby->raise();
        sendBtn->raise();
        exitBtn->raise();
        layoutWidget_3 = new QWidget(ChatDialog);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 0, 171, 77));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 75));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        label_2 = new QLabel(ChatDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-20, -30, 1061, 801));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(57, 159, 255);"));
        label_2->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        layoutWidget_3->raise();

        retranslateUi(ChatDialog);

        sizeCbx->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QWidget *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Form", Q_NULLPTR));
        sizeCbx->clear();
        sizeCbx->insertItems(0, QStringList()
         << QApplication::translate("ChatDialog", "8", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "9", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "10", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "11", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "12", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "13", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "14", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "15", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "16", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "17", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "18", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "19", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "20", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "21", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "22", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        boldTBtn->setToolTip(QApplication::translate("ChatDialog", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        boldTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        italicTBtn->setToolTip(QApplication::translate("ChatDialog", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        italicTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        underlineTBtn->setToolTip(QApplication::translate("ChatDialog", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        underlineTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        colorTBtn->setToolTip(QApplication::translate("ChatDialog", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        colorTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sendTBtn->setToolTip(QApplication::translate("ChatDialog", "\344\274\240\350\276\223\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        sendTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveTBtn->setToolTip(QApplication::translate("ChatDialog", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        clearTBtn->setToolTip(QApplication::translate("ChatDialog", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        clearTBtn->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
        msgTxtEdit->setHtml(QApplication::translate("ChatDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = usrTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ChatDialog", "Recent", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = usrTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ChatDialog", "Yshow", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("ChatDialog", "Send", Q_NULLPTR));
        Designedby->setText(QApplication::translate("ChatDialog", "Designed by Young Inc \302\251 2021 ", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("ChatDialog", "Exit", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
