#ifndef CHATMIX_H
#define CHATMIX_H

#include <QWidget>

namespace Ui {
class chatmix;
}

class chatmix : public QWidget
{
    Q_OBJECT

public:
    explicit chatmix(QWidget *parent = nullptr);
    ~chatmix();

private:
    Ui::chatmix *ui;
};

#endif // CHATMIX_H
