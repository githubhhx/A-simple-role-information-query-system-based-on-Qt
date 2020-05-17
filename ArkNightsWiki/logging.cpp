#include "logging.h"
#include "ui_logging.h"

////最开始的登陆界面////
logging::logging(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logging)
{
    ui->setupUi(this);
    ui->profBtn->setFlat(true);
    this->setStyleSheet("#logging{border-image:url(:/ArkImage/logging.jpg);}");
    connect(ui->profBtn,&QPushButton::clicked,[=](){
       accept();
    });
}

logging::~logging()
{
    delete ui;
}
