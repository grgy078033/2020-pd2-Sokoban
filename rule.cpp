#include "rule.h"
#include "ui_rule.h"

rule::rule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rule)
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

}

rule::~rule()
{
    delete ui;
}
