#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QtWidgets/QApplication>



namespace Ui {
class Loginwindow;
}

class Loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Loginwindow(QWidget *parent = nullptr);
    ~Loginwindow();
    QString userName, userPassword;

private slots:

    void on_ButtonRegistAccount_clicked();

    void on_FogetPassword_clicked();

    void on_LoginButton_clicked();

     void paintEvent(QPaintEvent *event);

private:
    Ui::Loginwindow *ui;
};

#endif // LOGINWINDOW_H
