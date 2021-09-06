#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QTextBrowser>
#include <QTextEdit>
#include <QListWidget>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

    QTextBrowser* getLabel();
    QTextEdit* getTextEdit();
    QListWidget* getTextBrowser();

private slots:
    void on_exitBtn_clicked();

    void on_sendBtn_clicked();



private:
    Ui::ChatDialog *ui;
};

#endif // CHATDIALOG_H
