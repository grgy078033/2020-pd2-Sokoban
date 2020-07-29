#ifndef PASS1_H
#define PASS1_H

#include <QDialog>

namespace Ui {
class pass1;
}

class pass1 : public QDialog
{
    Q_OBJECT

public:
    explicit pass1(QWidget *parent = nullptr);
    ~pass1();

private:
    Ui::pass1 *ui;
};

#endif // PASS1_H
