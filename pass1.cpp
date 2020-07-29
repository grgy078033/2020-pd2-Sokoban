#include "pass1.h"
#include "level1.h"
#include "level2.h"
#include "ui_pass1.h"

pass1::pass1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pass1)
{
    ui->setupUi(this);
    level1 level1;
    connect(ui->Confirm, SIGNAL(clicked()), this, SLOT(close()));
}

pass1::~pass1()
{
    delete ui;
}
