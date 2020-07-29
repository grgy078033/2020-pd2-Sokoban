#ifndef LEVEL1_H
#define LEVEL1_H

#include <QDialog>
#include <QLabel>
#include <QKeyEvent>

namespace Ui {
class level1;
}

class level1 : public QDialog
{
    Q_OBJECT

public:
    explicit level1(QWidget *parent = nullptr);
    ~level1();
    void keyPressEvent(QKeyEvent *key);
    void setPosition(int x, int y);
    void getPosition(int &x, int &y);
    void check_pass();
    void setAll(int x[], int y[]);
    int getAllx(int x[], int index);
    int getAlly(int y[], int index);
    void setInvincible(int x);
    void setR(int x);
    void setI(int x);
    void setC(int x);
    void setH(int x);

public slots:
    void setMap();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void add();
    void Pass();
    void goto_level2();
    void restart();

signals:
    void up_signal();
    void left_signal();
    void down_signal();
    void right_signal();
    void add_step();
    void pass_signal();

private:
    Ui::level1 *ui;
    QLabel *box[3];
    QLabel *box2;
    QLabel *position;
    QLabel *point;
    QLabel *player;
    int x_position;
    int y_position;
    int step = 0;
    int box_x[3], box_y[3];
    int position_x[3];
    int position_y[3];
    int ban_x[41];
    int ban_y[41];
    int invincible;
    int R, I, C, H;

};

#endif // LEVEL1_H
