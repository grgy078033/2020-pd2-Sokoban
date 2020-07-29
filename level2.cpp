#include "level2.h"
#include "ui_level2.h"
#include "pass2.h"
#include <QLabel>
#include <QPixmap>

level2::level2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::level2)
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
    ui->finish->hide();
    player = new QLabel(this);
    int x = 120, y = 180;
    setPosition(x, y);
    player -> setGeometry(x,y,60,60);
    QPixmap playerPix(":/Sokoban icon/player_right.png");
    player -> setPixmap(playerPix);
    player -> setScaledContents(true);

    trap = new QLabel(this);
    trap -> setGeometry(360,480,60,60);
    QPixmap trapPix(":/Sokoban icon/trap.png");
    trap -> setPixmap(trapPix);
    trap -> setScaledContents(true);

    connect(ui->restart, SIGNAL(clicked()), this, SLOT(restart()));
    connect(this, SIGNAL(up_signal()), this , SLOT(move_up()));
    connect(this, SIGNAL(left_signal()), this , SLOT(move_left()));
    connect(this, SIGNAL(down_signal()), this , SLOT(move_down()));
    connect(this, SIGNAL(right_signal()), this , SLOT(move_right()));
    connect(this, SIGNAL(pass_signal()), this, SLOT(pass()));
    connect(ui->finish, SIGNAL(clicked()), this, SLOT(finish()));


}

level2::~level2()
{
    delete ui;
}
void level2::setMap(){
    int i, x = 0, y = 0;
    for(i = 0; i < 5; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x+120,y+60,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i] = x+120;
        ban_y[i] = 60;
        x += 60;
    }
    x = 0;
    for(i = 0; i < 4; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+120,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+5] = x;
        ban_y[i+5] = 120;
        if(i == 2)
            x += 240;
        else {
            x += 60;
        }
    }
    x = 0;
    for(i = 0; i < 2; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+180,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+9] = x;
        ban_y[i+9] = 180;
        x += 360;
    }
    x = 0;
    for(i = 0; i < 4; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+240,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+11] = x;
        ban_y[i+11] = 240;
        if(i == 2)
            x += 240;
        else
            x += 60;
    }
    x = 0;
    for(i = 0; i < 4; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+300,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+15] = x;
        ban_y[i+15] = 300;
        if(i == 0)
            x += 120;
        else if(i == 1)
            x += 60;
        else if(i == 2)
            x += 180;
    }
    x = 0;
    for(i = 0; i < 6; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+360,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+19] = x;
        ban_y[i+19] = 360;
        if(i == 0)
            x += 120;
        else if(i == 1)
            x += 240;
        else
            x += 60;
    }
    x = 0;
    for(i = 0; i < 4; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+420,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+25] = x;
        ban_y[i+25] = y+420;
        if(i == 0)
            x += 420;
        else if(i == 1)
            y += 60;
        else if(i == 2)
            x -= 420;
    }
    x = 0; y = 0;
    for(i = 0; i < 10; i++){
        box2 = new QLabel(this);
        box2 -> setGeometry(x,y+540,60,60);
        QPixmap box2pix(":/Sokoban icon/box2.png");
        box2 -> setPixmap(box2pix);
        box2 -> setScaledContents(true);
        ban_x[i+29] = x;
        ban_y[i+29] = 540;
        x += 60;
    }
    x = 0;
    for(i = 0; i < 7; i++){
        if(i == 0){
            x += 180;
            y += 180;
        }
        else if(i == 1){
            x += 60;
            y += 60;
        }
        else if(i == 2){
            y += 60;
        }
        else if(i == 3){
            x -= 180;
            y += 120;
        }
        else if(i == 4){
            x += 120;
        }
        else
            x += 60;
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
    for(i = 0; i < 7; i++){
        position = new QLabel(this);
        position-> setGeometry(x+60,y+180,60,60);
        QPixmap positionPix(":/Sokoban icon/position.png");
        position -> setPixmap(positionPix);
        position -> setScaledContents(true);
        position_x[i] = x+60;
        position_y[i] = y+180;
        if(i == 0){
            y += 120;
        }
        else if(i == 1){
            x += 240;
            y -= 60;
        }
        else if(i == 2){
            x -= 60;
            y += 120;
        }
        else if(i == 3){
            x += 120;
            y += 60;
        }
        else if(i == 4){
            x -= 180;
        }
        else{
            x += 60;
            y += 60;
        }
    }
    x = 0; y = 0;
    point = new QLabel(this);
    point -> setGeometry(x+540,y+480,60,60);
    QPixmap pointPix(":/Sokoban icon/point.png");
    point -> setPixmap(pointPix);
    point -> setScaledContents(true);

    x = 0; y = 0;
}
void level2::keyPressEvent(QKeyEvent *key){
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
    for(int i = 0; i < 7; i++){
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
    for(int i = 0; i < 7; i++){
        if(up_no == 1)
            break;
        if((x_position == box_x[i]) && (y_position-60 == box_y[i])){
            for(int j = 0; j < 7; j++){
                if((box_x[i] == box_x[j]) && (box_y[i]-60 == box_y[j])){
                    up_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 39; k++){
                if((box_x[i] == ban_x[k]) && (box_y[i])-60 == ban_y[k]){
                    up_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 39; k++){
            if((x_position == ban_x[k]) && (y_position-60 == ban_y[k])){
                up_no = 1;
                break;
            }
        }
    }
    for(int i = 0; i < 7; i++){
        if(left_no == 1)
            break;
        if((y_position == box_y[i]) && (x_position-60 == box_x[i])){
            for(int j = 0; j < 7; j++){
                if((box_y[i] == box_y[j]) && (box_x[i]-60 == box_x[j])){
                    left_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 39; k++){
                if((box_y[i] == ban_y[k]) && (box_x[i])-60 == ban_x[k]){
                    left_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 39; k++){
            if((y_position == ban_y[k]) && (x_position-60 == ban_x[k])){
                left_no = 1;
                break;
            }
        }
    }
    for(int i = 0; i < 7; i++){
        if(down_no == 1)
            break;
        if((x_position == box_x[i]) && (y_position+60 == box_y[i])){
            for(int j = 0; j < 7; j++){
                if((box_x[i] == box_x[j]) && (box_y[i]+60 == box_y[j])){
                    down_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 39; k++){
                if((box_x[i] == ban_x[k]) && (box_y[i])+60 == ban_y[k]){
                    down_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 39; k++){
            if((x_position == ban_x[k]) && (y_position+60 == ban_y[k])){
                down_no = 1;
                break;
            }
        }
    }
    for(int i = 0; i < 7; i++){
        if(right_no == 1)
            break;
        if((y_position == box_y[i]) && (x_position+60 == box_x[i])){
            for(int j = 0; j < 7; j++){
                if((box_y[i] == box_y[j]) && (box_x[i]+60 == box_x[j])){
                    right_no = 1;
                    break;
                }
            }
            for(int k = 0; k < 39; k++){
                if((box_y[i] == ban_y[k]) && (box_x[i])+60 == ban_x[k]){
                    right_no = 1;
                    break;
                }
            }
        }
        for(int k = 0; k < 39; k++){
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
void level2::check_pass(){
    int check = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(box_x[i] == position_x[j] && box_y[i] == position_y[j])
                check+=1;
        }
    }
    if(check == 7){
        emit pass_signal();
    }
    if(x_position == 540 && y_position == 480){
        point -> hide();
        emit pass_signal();
    }
}
void level2::setPosition(int x, int y){
    x_position = x;
    y_position = y;
}
void level2::getPosition(int &x, int &y){
    x = x_position;
    y = y_position;
}
void level2::setAll(int x[], int y[]){
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
void level2::setInvincible(int x){
    invincible = x;
}
void level2::setR(int x){
    R = x;
}
void level2::setI(int x){
    I = x;
}
void level2::setC(int x){
    C = x;
}
void level2::setH(int x){
    H = x;
}
void level2::move_up(){
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
    check_die();
    check_pass();
}
void level2::move_left(){
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
    check_die();
    check_pass();
}
void level2::move_down(){
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
    check_die();
    check_pass();
}
void level2::move_right(){
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
    check_die();
    check_pass();
}
void level2::add(){
    step++;
    ui -> steps_count -> setNum(step);
}
void level2::restart(){
    close();
    level2 again;
    again.setModal(true);
    again.exec();
    setR(0);
    setI(0);
    setC(0);
    setH(0);
    setInvincible(0);
}
void level2::pass(){
    if(invincible == 1){
        QPixmap playerPix(":/Sokoban icon/invincible.png");
        player -> setPixmap(playerPix);
    }
    pass2 pass;
    pass.setModal(true);
    pass.exec();
    ui->finish->show();
}
void level2::finish(){
    close();
}
void level2::check_die(){
    if((x_position == trap_position_x) && (y_position == trap_position_y))
        if(invincible == 0)
            restart();
}

