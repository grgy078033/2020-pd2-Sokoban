#include "chooselevels.h"
#include "ui_chooselevels.h"
#include "level1.h"
#include "level2.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

ChooseLevels::ChooseLevels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseLevels)
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

    connect(ui->Level1, SIGNAL(clicked()), this, SLOT(choose_level1()));
    connect(ui->Level2, SIGNAL(clicked()), this, SLOT(choose_level2()));
}

ChooseLevels::~ChooseLevels()
{
    delete ui;
}

void ChooseLevels::choose_level1(){
    close();
    level1 level1;
    level1.setModal(true);
    level1.exec();
}
void ChooseLevels::choose_level2(){
    close();
    level2 level2;
    level2.setModal(true);
    level2.exec();
}
