#ifndef PASSWORDRESET_H
#define PASSWORDRESET_H

#include <QWidget>

namespace Ui {
class PasswordReset;
}

class PasswordReset : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordReset(QWidget *parent = nullptr);
    ~PasswordReset();
    QString Res_password1, Res_password2;
    bool CheckPwd();

private slots:
    void on_pButtonOk_clicked();

    void on_pButtonCancel_clicked();

private:
    Ui::PasswordReset *ui;
};

#endif // PASSWORDRESET_H
