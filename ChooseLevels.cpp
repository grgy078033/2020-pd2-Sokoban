#include "ChooseLevels.h"
#include "ui_ChooseLevels.h"

ChooseLevels::ChooseLevels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseLevels)
{
    ui->setupUi(this);
    connect(ui->Level1, SIGNAL(clicked()), this, SLOT(Choose_Level1()));
    connect(ui->Level2, SIGNAL(clicked()), this, SLOT(Choose_Level2()));
}

ChooseLevels::~ChooseLevels()
{
    delete ui;
}

void ChooseLevels::Choose_Level1(){

}
void ChooseLevels::Choose_Level2(){

}
