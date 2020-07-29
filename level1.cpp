#include "level1.h"
#include "level2.h"
#include "ui_level1.h"
#include "mainwindow.h"
#include "player.h"
#include "pass1.h"
#include <QLabel>
#include <QPixmap>

level1::level1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::level1)
{
    ui->setupUi(this);

    this -> setAutoFillBackground(true);
    QPalette palette = this -> palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/Sokoban icon/background.jpg").scaled(
                                this -> size(),
                                Qt::IgnoreAspectRatio,
                                Qt::SmoothTransformation)));
    this -> setPalette(palette);

    setMap();
    ui->next->hide();

    player = new QLabel(this);
    int x = 480, y = 240;
    setPosition(x, y);
    player -> setGeometry(x,y,60,60);
    QPixmap playerPix(":/Sokoban icon/player_left.png");
    player -> setPixmap(playerPix);
    player -> setScaledContents(true);

    connect(this, SIGNAL(pass_signal()), this, SLOT(Pass()));
    connect(this, SIGNAL(up_signal()), this, SLOT(move_up()));
    connect(this, SIGNAL(left_signal()), this, SLOT(move_left()));
    connect(this, SIGNAL(down_signal()), this, SLOT(move_down()));
    connect(this, SIGNAL(right_signal()), this, SLOT(move_right()));
    connect(ui->restart, SIGNAL(clicked()), this, SLOT(restart()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(goto_level2()));

}

level1::~level1()
{
    delete ui;
}
void level1::setMap(){
    int box_x[3];
    int box_y[3];
    int i, x = 0, y = 0;
    for(i = 0; i < 5; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x+300,60,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i] = x+300;
        ban_y[i] = 60;
        x += 60;
    }
    x = 0;
    for(i = 0; i < 5; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x+240,540,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+5] = x+240;
        ban_y[i+5] = 540;
        x += 60;
    }
    x = 0;
    for(i = 0; i < 6; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,480,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+10] = x;
        ban_y[i+10] = 480;
        if(i < 4)
            x += 60;
        else
            x += 240;
    }
    x = 0;
    for(i = 0; i < 6; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,180,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+16] = x;
        ban_y[i+16] = 180;
        if(i < 3)
            x += 60;
        else if(i == 3)
            x += 120;
        else if(i == 4)
            x += 240;
    }
    x = 0;
    for(i = 0; i < 2; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x+300,120,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+22] = x+300;
        ban_y[i+22] = 120;
        if(i == 0)
            x += 240;
    }
    x = 0;
    for(i = 0; i < 4; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,240,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+24] = x;
        ban_y[i+24] = 240;
        if(i == 0)
            x += 180;
        else if(i == 1)
            x += 120;
        else
            x += 240;
    }
    x = 0;
    for(i = 0; i < 7; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,300,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+28] = x;
        ban_y[i+28] = 300;
        if(i == 0)
            x += 180;
        else if(i == 3)
            x += 120;
        else
            x += 60;
    }
    x = 0;
    for(i = 0; i < 3; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,360,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+35] = x;
        ban_y[i+35] = 360;
        if(i == 0)
            x += 420;
        else
            x += 60;
    }
    x = 0;
    for(i = 0; i < 3; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,420,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+38] = x;
        ban_y[i+38] = 420;
        x += 240;
    }
    x = 0;
    for(i = 0; i < 3; i++){
        if(i == 0){
            x += 360;
            y += 180;
        }
        else if(i == 1){
            x += 60;
        }
        else if(i == 2){
            y += 60;
        }
        box[i] = new QLabel(this);
        box[i] -> setGeometry(x,y,60,60);
        QPixmap boxPix(":/Sokoban icon/box1.png");
        box[i] -> setPixmap(boxPix);
        box[i] -> setScaledContents(true);
        box_x[i] = x;
        box_y[i] = y;
    }
    setAll(box_x, box_y);
    x = 0; y = 0;
    for(i = 0; i < 3; i++){
        position = new QLabel(this);
        position -> setGeometry(x+60,y+240,60,60);
        QPixmap positionPix(":/Sokoban icon/position.png");
        position -> setPixmap(positionPix);
        position -> setScaledContents(true);
        if(i == 0)
            x += 60;
        if(i == 1){
            x -= 60;
            y += 60;
        }
        position_x[i] = x+60;
        position_y[i] = y+240;
    }
    x = 0; y = 0;

        point = new QLabel(this);
        point -> setGeometry(x+=540,y+=540,60,60);
        QPixmap pointPix(":/Sokoban icon/point.png");
        point -> setPixmap(pointPix);
        point -> setScaledContents(true);

    x = 0; y = 0;
}
void level1::keyPressEvent(QKeyEvent *key){

    if(key -> key() == Qt::Key_R){
        setR(1);
    }
    if(key -> key() == Qt::Key_I){
        setI(1);
    }
    if(key -> key() == Qt::Key_C){
        setC(1);
    }
    if(key -> key() == Qt::Key_H){
        setH(1);
    }
    if(R == 1 && I == 1 && C == 1 && H == 1){
        setInvincible(1);
    }
    int up = 0, left = 0, down = 0, right = 0;
    int up_i = 0, left_i = 0, down_i = 0, right_i = 0;
    for(int i = 0; i < 3; i++){
        if(box_x[i] == x_position){
            if(box_y[i] == (y_position - 60)){
                up += 1;
                up_i = i;
            }
            if(box_y[i] == (y_position + 60)){
                down += 1;
                down_i = i;
            }
        }
        if(box_y[i] == y_position){
            if(box_x[i] == (x_position - 60)){
                left += 1;
                left_i = i;
            }
            if(box_x[i] == (x_position + 60)){
                right += 1;
                right_i = i;
            }
        }
    }
    int up_no = 0, left_no = 0, down_no = 0, right_no = 0;
    for(int i = 0; i < 3; i++){
        if(up_no == 1)
            break;
        if((x_position == box_x[i]) && (y_position-60 == box_y[i])){
            for(int j = 0; j < 3; j++){
                if((box_x[i] == box_x[j]) && (box_y[i]-60 == box_y[j])){
                    up_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 41; k++){
                if((box_x[i] == ban_x[k]) && (box_y[i])-60 == ban_y[k]){
                    up_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 41; k++){
            if((x_position == ban_x[k]) && (y_position-60 == ban_y[k])){
                up_no = 1;
                break;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        if(left_no == 1)
            break;
        if((y_position == box_y[i]) && (x_position-60 == box_x[i])){
            for(int j = 0; j < 3; j++){
                if((box_y[i] == box_y[j]) && (box_x[i]-60 == box_x[j])){
                    left_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 41; k++){
                if((box_y[i] == ban_y[k]) && (box_x[i])-60 == ban_x[k]){
                    left_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 41; k++){
            if((y_position == ban_y[k]) && (x_position-60 == ban_x[k])){
                left_no = 1;
                break;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        if(down_no == 1)
            break;
        if((x_position == box_x[i]) && (y_position+60 == box_y[i])){
            for(int j = 0; j < 3; j++){
                if((box_x[i] == box_x[j]) && (box_y[i]+60 == box_y[j])){
                    down_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 41; k++){
                if((box_x[i] == ban_x[k]) && (box_y[i])+60 == ban_y[k]){
                    down_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 41; k++){
            if((x_position == ban_x[k]) && (y_position+60 == ban_y[k])){
                down_no = 1;
                break;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        if(right_no == 1)
            break;
        if((y_position == box_y[i]) && (x_position+60 == box_x[i])){
            for(int j = 0; j < 3; j++){
                if((box_y[i] == box_y[j]) && (box_x[i]+60 == box_x[j])){
                    right_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 41; k++){
                if((box_y[i] == ban_y[k]) && (box_x[i])+60 == ban_x[k]){
                    right_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 41; k++){
            if((y_position == ban_y[k]) && (x_position+60 == ban_x[k])){
                right_no = 1;
                break;
            }
        }
    }
    if(invincible == 1){
        up_no = 0;
        left_no = 0;
        down_no = 0;
        right_no = 0;
    }
    if(key -> key() == Qt::Key_W){
        if(up_no == 0){
            if(up != 0){
                box_y[up_i] -= 60;
                box[up_i] -> setGeometry(box_x[up_i],box_y[up_i],60,60);
                QPixmap boxPix(":/Sokoban icon/box1.png");
                box[up_i] -> setPixmap(boxPix);
                box[up_i] -> setScaledContents(true);
            }
            emit up_signal();
        }
    }
    if(key -> key() == Qt::Key_A){
        if(left_no == 0){
            if(left != 0){
                box_x[left_i] -= 60;
                box[left_i] -> setGeometry(box_x[left_i],box_y[left_i],60,60);
                QPixmap boxPix(":/Sokoban icon/box1.png");
                box[left_i] -> setPixmap(boxPix);
                box[left_i] -> setScaledContents(true);
            }
            emit left_signal();
        }
    }
    if(key -> key() == Qt::Key_S){
        if(down_no == 0){
            if(down != 0){
                box_y[down_i] += 60;
                box[down_i] -> setGeometry(box_x[down_i],box_y[down_i],60,60);
                QPixmap boxPix(":/Sokoban icon/box1.png");
                box[down_i] -> setPixmap(boxPix);
                box[down_i] -> setScaledContents(true);
            }
            emit down_signal();
        }
    }
    if(key -> key() == Qt::Key_D){
        if(right_no == 0){
            if(right != 0){
                box_x[right_i] += 60;
                box[right_i] -> setGeometry(box_x[right_i],box_y[right_i],60,60);
                QPixmap boxPix(":/Sokoban icon/box1.png");
                box[right_i] -> setPixmap(boxPix);
                box[right_i] -> setScaledContents(true);
            }
            emit right_signal();
        }
    }
    if(invincible == 1){
        QPixmap playerPix(":/Sokoban icon/invincible.png");
        player -> setPixmap(playerPix);
    }
    setAll(box_x, box_y);
}
void level1::check_pass(){
    int check = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(box_x[i] == position_x[j] && box_y[i] == position_y[j])
                check+=1;
        }
    }
    if(check == 3){
        emit pass_signal();
    }
    else if(x_position == 540 && y_position == 540){
        point -> hide();
        emit pass_signal();
    }
}
void level1::setPosition(int x, int y){
    x_position = x;
    y_position = y;
}
void level1::getPosition(int &x, int &y){
    x = x_position;
    y = y_position;
}
void level1::setAll(int x[], int y[]){
    int i;
    int *px = x;
    int *py = y;
    for(i = 0; i < 3; i++){
       box_x[i] = *px;
       box_y[i] = *py;
       px++;
       py++;
    }
}
int level1::getAllx(int x[], int index){
    return x[index] = box_x[index];
}
int level1::getAlly(int y[], int index){
    return y[index] = box_y[index];
}
void level1::setInvincible(int x){
    invincible = x;
}
void level1::setR(int x){
    R = x;
}
void level1::setI(int x){
    I = x;
}
void level1::setC(int x){
    C = x;
}
void level1::setH(int x){
    H = x;
}
void level1::move_up(){
    int x = 0 , y = 0;
    int &x_pos = x;
    int &y_pos = y;
    getPosition(x_pos, y_pos);
    if(y_pos > 0){
        player -> setGeometry(x_pos,y_pos-=60,60,60);
        QPixmap playerPix(":/Sokoban icon/player_up.png");
        player -> setPixmap(playerPix);
        player -> setScaledContents(true);
        setPosition(x, y);
        add();
    }
    check_pass();
}
void level1::move_left(){
    int x = 0 , y = 0;
    int &x_pos = x;
    int &y_pos = y;
    getPosition(x_pos, y_pos);
    if(x_pos > 0){
        player -> setGeometry(x_pos-=60,y_pos,60,60);
        QPixmap playerPix(":/Sokoban icon/player_left.png");
        player -> setPixmap(playerPix);
        player -> setScaledContents(true);
        setPosition(x, y);
        add();
    }
    check_pass();
}
void level1::move_down(){
    int x = 0 , y = 0;
    int &x_pos = x;
    int &y_pos = y;
    getPosition(x_pos, y_pos);
    if(y_pos < 540){
        player -> setGeometry(x_pos,y_pos+=60,60,60);
        QPixmap playerPix(":/Sokoban icon/player_down.png");
        player -> setPixmap(playerPix);
        player -> setScaledContents(true);
        setPosition(x, y);
        add();
    }
    check_pass();
}
void level1::move_right(){
    int x = 0 , y = 0;
    int &x_pos = x;
    int &y_pos = y;
    getPosition(x_pos, y_pos);
    if(x_pos < 540){
        player -> setGeometry(x_pos+=60,y_pos,60,60);
        QPixmap playerPix(":/Sokoban icon/player_right.png");
        player -> setPixmap(playerPix);
        player -> setScaledContents(true);
        setPosition(x, y);
        add();
    }
    check_pass();
}
void level1::add(){
    step++;
    ui -> steps_count -> setNum(step);
}
void level1::Pass(){
    if(invincible == 1){
        QPixmap playerPix(":/Sokoban icon/invincible.png");
        player -> setPixmap(playerPix);
    }
    pass1 pass;
    pass.setModal(true);
    pass.exec();
    ui->next->show();
}
void level1::goto_level2(){
    close();
    level2 level2;
    level2.setModal(true);
    level2.exec();
}
void level1::restart(){
    close();
    level1 again;
    again.setModal(true);
    again.exec();
    setR(0);
    setI(0);
    setC(0);
    setH(0);
    setInvincible(0);
}
