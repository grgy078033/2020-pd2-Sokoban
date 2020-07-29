#ifndef PASS2_H
#define PASS2_H

#include <QDialog>

namespace Ui {
class pass2;
}

class pass2 : public QDialog
{
    Q_OBJECT

public:
    explicit pass2(QWidget *parent = nullptr);
    ~pass2();

private:
    Ui::pass2 *ui;
};

#endif // PASS2_H
