#ifndef CHOOSELEVELS_H
#define CHOOSELEVELS_H

#include <QDialog>

namespace Ui {
class ChooseLevels;
}

class ChooseLevels : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseLevels(QWidget *parent = nullptr);
    ~ChooseLevels();

public slots:
    void choose_level1();
    void choose_level2();

private:
    Ui::ChooseLevels *ui;
};

#endif // CHOOSELEVELS_H
