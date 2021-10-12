#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    connect(ui->pushButton_add,SIGNAL(clicked()),this,SIGNAL(add_new_user_clicked()));

    ui->lineEdit_ID->setToolTip("<font color='black'><b>ID </b> ");
    ui->pushButton_add->setToolTip("<font color='black'><b>ID DELETE </b> ");
}

settings::~settings()
{
    delete ui;
}

QString settings::id_getir()
{
    return ui->lineEdit_ID->text();
}

void settings::clear_lineEdit()
{
    ui->lineEdit_ID->clear();
}
