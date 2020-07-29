#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "level1.h"
#include "level2.h"
#include "ChooseLevels.h"
#include "rule.h"
#include <QPixmap>
#include <QPalette>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    connect(ui->start, SIGNAL(clicked()), this, SLOT(clickStart()));
    connect(ui->choose, SIGNAL(clicked()), this, SLOT(clickChoose()));
    connect(ui->quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->rule, SIGNAL(clicked()), this, SLOT(clickRule()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickStart(){//close mainWindow, show level1.
    hide();
    level1 level1;
    level1.setModal(true);
    level1.exec();
}
void MainWindow::clickChoose(){//close mainWindow, show chooselevel.
    hide();
    ChooseLevels chooselevels;
    chooselevels.setModal(true);
    chooselevels.exec();
}
void MainWindow::clickRule(){
    rule rule;
    rule.setModal(true);
    rule.exec();
}
