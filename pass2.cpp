#include "pass2.h"
#include "ui_pass2.h"

pass2::pass2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pass2)
{
    ui->setupUi(this);
    connect(ui->Confirm, SIGNAL(clicked()), this, SLOT(close()));
}

pass2::~pass2()
{
    delete ui;
}
