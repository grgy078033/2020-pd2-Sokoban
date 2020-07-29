#ifndef LEVEL2_H
#define LEVEL2_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>

namespace Ui {
class level2;
}

class level2 : public QDialog
{
    Q_OBJECT

public:
    explicit level2(QWidget *parent = nullptr);
    ~level2();
    void keyPressEvent(QKeyEvent *key);
    void setPosition(int x, int y);
    void getPosition(int &x, int &y);
    void setAll(int x[], int y[]);
    void setInvincible(int x);
    void setR(int x);
    void setI(int x);
    void setC(int x);
    void setH(int x);
    void check_pass();
    void check_die();

public slots:
    void setMap();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void add();
    void restart();
    void pass();
    void finish();

signals:

    void up_signal();
    void left_signal();
    void down_signal();
    void right_signal();
    void add_step();
    void pass_signal();

private:
    Ui::level2 *ui;
    QLabel *box[7];
    QLabel *box2;
    QLabel *position;
    QLabel *point;
    QLabel *player;
    QLabel *trap;
    int x_position;
    int y_position;
    int step = 0;
    int box_x[7], box_y[7];
    int position_x[7], position_y[7];
    int ban_x[39], ban_y[39];
    int invincible;
    int trap_position_x = 360;
    int trap_position_y = 480;
    int R, I, C, H;
};

#endif // LEVEL2_H
