#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QDebug>
#include <QString>
#include <QIcon>
#include <QCompleter>
#include <QStringListModel>
#include <QComboBox>
#include <string>
#include <QMessageBox>
#include <cstring>
using namespace Qt;


////////干员数据定义////////
class Crew {
private:
public:
    virtual double Hp_calc(int Tier,int ExTier) = 0;
    virtual double Atk_calc(int AtkBase,int Tier) = 0;
    virtual double Def_calc(int DefBase,int Tier) = 0;
};
//Sex
class Male :public Crew {
public:
    char sex[10] = "male";
    virtual ~Male(){}
};
class Female :public Crew {
public:
    char sex[10] = "female";
    virtual ~Female(){}
};
////////Male////////
//Carrier
class Pioneer_M :public Male {
public:
    char carrier[10] = "pioneer";
};
class Guard_M :public Male {
public:
    char carrier[10] = "guard";
};
class Auxiliary_M :public Male {
public:
    char carrier[10] = "auxiliary";
};
//Tag
class Protection_Pio_M :public Pioneer_M {
    char tag[10] = "protect";
    char name[10] = "courier";
    char img[100] = ":/ArkImage/Courier.png";
    int HpBase[3] = {758,1083,1389};
    int AtkBase[3] = {170,254,348};
    int DefBase[3] = {137,196,273};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={7,5,9};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={2,1.5,1};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={1.2,1,0.8};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }

};
class Support_Grd_M :public Guard_M {
    char tag[10] = "support";
    char name[10] = "castle";
    char img[100] = ":/ArkImage/Castle.png";
    int HpBase[3] = {862,1106,1106};
    int AtkBase[3] = {221,316,316};
    int DefBase[3] = {63,90,90};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={9,9,9};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={3,3,3};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={1,1,1};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};
class Output_Grd_M :public Guard_M {
    char tag[10] = "output";
    char name[10] = "silverash";
    char img[100] = ":/ArkImage/Silverash.png";
    int HpBase[3] = {1075,1536,2022};
    int AtkBase[3] = {297,444,577};
    int DefBase[3] = {189,259,329};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={10,6,6};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={3,2,2};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={1.2,1,1};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};
///////Female///////
//Carrier
class Pioneer_F :public Female {
public:
    char carrier[10] = "pioneer";
};
class Guard_F :public Female {
public:
    char carrier[10] = "guard";
};
class Auxiliary_F :public Female {
public:
    char carrier[10] = "auxiliary";
};
class Medical_F:public Female{
public:
    char carrier[10]="medical";

};
class Sniper_F:public Female{
    char carrier[10]="sniper";
};
class Shield_F:public Female{
    char carrier[10]="shield";
};
//Tag
class AOE_Grd_F :public Guard_F {
    char tag[10] = "aoe";
    char name[10] = "specter";
    char img[100] = ":/ArkImage/Specter.png";
    int HpBase[3] = {1199,1538,1972};
    int AtkBase[3] = {293,407,551};
    int DefBase[3] = {150,215,291};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={7,6,9};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={3,2,3};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={1,1,1};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};
class Support_Aux_F :public Auxiliary_F {
    char tag[10] = "support";
    char name[10] = "angelina";
    char img[100] = ":/ArkImage/Angelina.png";
    int HpBase[3] = {629,863,1108};
    int AtkBase[3] = {228,336,449};
    int DefBase[3] = {53,77,100};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={5,3,3};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={3,2,1};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={1,0.5,0.25};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};
class Support_Med_F:public Medical_F{
    char tag[10]="support";
    char name[10]="ptilopsis";
    char img[100] = ":/ArkImage/Ptilopsis.png";
    int HpBase[3] = {751,1016,1271};
    int AtkBase[3] = {122,198,268};
    int DefBase[3] = {71,95,124};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={5,4,4};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={1.5,1,1};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={0.5,0.4,0.4};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};
class Output_Snp_F:public Sniper_F{
    char tag[10]="output";
    char name[10]="blupoison";
    char img[100] = ":/ArkImage/Bluepoison.png";
    int HpBase[3] = {536,767,984};
    int AtkBase[3] = {178,297,438};
    int DefBase[3] = {45,76,109};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={5,3,3};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={2,2,1.2};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={0.5,1,0.5};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};
class Cure_Med_F:public Shield_F{
    char tag[10]="cure";
    char name[10]="saria";
    char img[100] = ":/ArkImage/Saria.png";
    int HpBase[3] = {1309,1769,2268};
    int AtkBase[3] = {205,292,393};
    int DefBase[3] = {254,371,493};
public:
    char* ImgPathOut(){
        return img;
    }
    double Hp_calc(int Tier,int ExTier){
        double hp;
        double TierAdd[3]={10,6,10};
        hp=HpBase[ExTier]+Tier*TierAdd[ExTier];
        return hp;
    }
    double Atk_calc(int Tier,int ExTier){
        double atk;
        double TierAdd[3]={2,1.3,1};
        atk=AtkBase[ExTier]+Tier*TierAdd[ExTier];
        return atk;
    }
    double Def_calc(int Tier,int ExTier){
        double def;
        double TierAdd[3]={3,2,1};
        def=DefBase[ExTier]+Tier*TierAdd[ExTier];
        return def;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief MainWindow::MainWindow
/// \param parent
///////////主窗口定义

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //////////////////////界面布置，样式表设定//////////////////////
    this->setStyleSheet("#MainWindow{border-image:url(:/ArkImage/background2.png);}");
    ui->searchLineEdit->setStyleSheet("background-color: rgba(12%,56%,100%,30%)");
    ui->TierBox->setStyleSheet("background-color: rgba(12%,56%,100%,60%)");
    ui->tierChooseBox->setStyleSheet("background-color: rgba(12%,56%,100%,60%)");
    ui->treeWidget->setStyleSheet("background-color: rgba(12%,56%,100%,60%)");
    ui->treeWidget->setFont(QFont("Helvetica",9,QFont::Bold));
    ui->searchButton->setFlat(false);
    ui->border_lbl->setPixmap(QPixmap(":/ArkImage/border.jpg"));
    ui->lbl_dialog->setPixmap(QPixmap(":/ArkImage/dialog.png"));
    ui->adLabel->setPixmap(QPixmap(":/ArkImage/ad.png"));
    ui->adBtn->setFlat(true);
    ui->searchButton->setEnabled(false);
    //////////////////////////////////////////////////////////////

    //点击广告栏后会弹出寻访界面
    connect(ui->adBtn,&QPushButton::clicked,[=]()mutable{
        QDialog *dlg=new QDialog(this);
        dlg->setStyleSheet("background-image:url(:/ArkImage/adafrican.png);");
        dlg->resize(1440,740);
        dlg->show();
    });

    //资料栏设定
    ui->treeWidget->setHeaderLabels(QStringList()<<"干员"<<"精英等级"<<"生命"<<"攻击"<<"防御");
    for(int i=0;i<5;i++){ui->treeWidget->setColumnWidth(i,80);}
    ui->treeWidget->setColumnWidth(3,70);
    ui->treeWidget->setColumnWidth(2,60);
    ui->treeWidget->setColumnWidth(0,110);

    //精英等级下拉框设定
    QHeaderView *head = ui->treeWidget->header();
    head->setStretchLastSection(false);
    ui->lbl_Image->setPixmap(QPixmap(":/ArkImage/amilv.png"));
    ui->TierBox->addItem("初始");
    ui->TierBox->addItem("精一");
    ui->TierBox->addItem("精二");

    //历史记录功能
    ui->searchButton->setStyleSheet("background-color: rgba(94%,97%,100%,80%)");
    ui->searchButton->setIcon(QIcon(":/ArkImage/crew_un.png"));
    QStringList history;
    QStringListModel histModel;
    histModel.setParent(this);
    histModel.setStringList(history);

    //搜索框变动之后，使能寻访按钮
    connect(ui->searchLineEdit,&QLineEdit::textChanged,[=](){
       ui->searchButton->setEnabled(true);
       ui->searchButton->setIcon(QIcon(":/ArkImage/crew.png"));
       //ui->searchButton->setText("寻访");
    });

    //////以下代码实现根据输入的名字匹配干员信息//////
    connect(ui->searchButton,&QPushButton::clicked,[=]()mutable{

        //自动补全搜索历史
        QString text = ui->searchLineEdit->text();
        history<<text;
        QCompleter *completer = new QCompleter(history, this);
        completer->setCaseSensitivity(Qt::CaseSensitive);
        ui->searchLineEdit->setCompleter(completer);

        //接受下拉框的消息（精英等级）
        int ExTier = ui->TierBox->currentIndex();
        //接受等级信息（普通等级）
        int Tier = ui->tierChooseBox->value();
        /////////DEBUG/////////

        //非常非常死板的数据匹配（不知道要怎么改进）
        //虚函数
        Crew *dataptr;
        int acceptedFlag = 0;
        QStringList data;
        char dstimg[100]="";
        QString HP;
        QString ATK;
        QString DEF;
        QString crewname;
        QString EXTIER = ui->TierBox->currentText();

        if(text=="courier")
        {
            Protection_Pio_M courier;
            dataptr=&courier;
            strcpy(dstimg, courier.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="讯使";
        }
        else if(text=="castle")
        {
            Support_Grd_M castle;
            dataptr=&castle;
            strcpy(dstimg, castle.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="Castle-3";
        }
        else if(text=="silverash")
        {
            Output_Grd_M silverash;
            dataptr=&silverash;
            strcpy(dstimg, silverash.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="银灰";
        }
        else if(text=="spector")
        {
            AOE_Grd_F spector;
            dataptr=&spector;
            strcpy(dstimg, spector.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="幽灵鲨";
        }
        else if(text=="angelina")
        {
            Support_Aux_F angelina;
            dataptr=&angelina;
            strcpy(dstimg, angelina.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="安洁莉娜";
        }
        else if(text=="ptilopsis")
        {
            Support_Med_F ptilopsis;
            dataptr=&ptilopsis;
            strcpy(dstimg, ptilopsis.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="白面鸮";
        }
        else if(text=="bluepoison")
        {
            Output_Snp_F bluepoison;
            dataptr=&bluepoison;
            strcpy(dstimg, bluepoison.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="蓝毒";
        }
        else if(text=="saria")
        {
            Cure_Med_F saria;
            dataptr=&saria;
            strcpy(dstimg, saria.ImgPathOut());
            acceptedFlag=1;
            HP.setNum(dataptr->Hp_calc(Tier,ExTier));
            ATK.setNum(dataptr->Atk_calc(Tier,ExTier));
            DEF.setNum(dataptr->Def_calc(Tier,ExTier));
            crewname="塞雷亚";
        }
        if(acceptedFlag==0)
            {QMessageBox::warning(this,"OOPS!","这个干员还没有投简历噢QAQ");
            ui->searchLineEdit->clear();
            }
        if(acceptedFlag==1){
            ui->lbl_Image->setPixmap(QPixmap(dstimg));
            data<<crewname<<EXTIER<<HP<<ATK<<DEF;
            QTreeWidgetItem * dataItem =new QTreeWidgetItem(data);
            ui->treeWidget->addTopLevelItem(dataItem);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

