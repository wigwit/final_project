#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCharacter();
    setComboBox();
    connect(ui->hair_box,SIGNAL(activated(QString)),hair,SLOT(setLabel(QString)));
    connect(ui->skin_box,SIGNAL(activated(QString)),skin,SLOT(setLabel(QString)));
    connect(ui->mood_box,SIGNAL(activated(QString)),mood,SLOT(setLabel(QString)));
    connect(ui->hat_box,SIGNAL(activated(QString)),hat,SLOT(setLabel(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCharacter()
{
    skin =new character(this,ui->skin_label);

    //  I tried to reimplement this part with pointer
    //However, it does not work well with resource file
    // However, i feel like this part could reimplemented into generic algorithm
    skin->addfeature(new feature(skin,"dark",":/skin/character pics/dark_skin.png"));
    skin->addfeature(new feature(skin,"medium",":/skin/character pics/medium_skin.png"));
    skin->addfeature(new feature(skin,"light",":/skin/character pics/light_skin.png"));


    hair=new character(this,ui->hat_label);
    hair->addfeature(new feature(hair,"black",":/hair/character pics/black_hair.png"));
    hair->addfeature(new feature(hair,"purple",":/hair/character pics/purple_hair.png"));
    hair->addfeature(new feature(hair,"brown",":/hair/character pics/brown_hair.png"));
    hair->addfeature(new feature(hair,"pink",":/hair/character pics/pink_hair.png"));


    mood=new character (this,ui->mood_label);
    mood->addfeature(new feature(mood,"happy",":/mood/character pics/happy_mood.png"));
    mood->addfeature(new feature(mood,"sad",":/mood/character pics/sad_mood.png"));


    hat=new character(this,ui->hat_label);
    hat->addfeature(new feature(hat,"balck",":/hat/character pics/black_hat.png"));
    hat->addfeature(new feature(hat,"green",":/hat/character pics/green_hat.png"));
    hat->addfeature(new feature(hat,"red",":/hat/character pics/red_hat.png"));
}

void MainWindow::setComboBox()
{
   skin->setComboBox(ui->skin_box);
   hair->setComboBox(ui->hair_box);
   mood->setComboBox(ui->mood_box);
   hat->setComboBox(ui->hat_box);
}
