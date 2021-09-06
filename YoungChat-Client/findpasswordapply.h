 #ifndef FINDPASSWORDAPPLY_H
#define FINDPASSWORDAPPLY_H

#include <QWidget>



namespace Ui {
class FindPasswordApply;
}

class FindPasswordApply : public QWidget
{
    Q_OBJECT

public:
    explicit FindPasswordApply(QWidget *parent = nullptr);
     void receiverFindPasswordQandA(QString q1, QString a1, QString q2, QString a2);
    ~FindPasswordApply();
private:
     QString question1;
     QString answer1;
     QString question2;
     QString answer2;



private slots:

    void on_pButtonOk_clicked();
    void on_pButtonCancel_clicked();

    //wwx
    void on_sendName_clicked();
private:
    Ui::FindPasswordApply *ui;

    //wwx
    QString userName;

};

#endif // FINDPASSWORDAPPLY_H
