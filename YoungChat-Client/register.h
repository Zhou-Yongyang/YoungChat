#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QMessageBox>
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    bool CheckPwd();

private slots:
    void on_pButtonOk_clicked();

    void on_pButtonCancel_clicked();

private:
    Ui::Register *ui;
    QString secQues1,secAns1,secQues2,secAns2,userName,firstPassWrd,secondPassWrd;
};

#endif // REGISTER_H
