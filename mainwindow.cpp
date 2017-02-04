#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Slider, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->dial, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->Skroll, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            ui->lcdNumber, SLOT(display(int)));
    connect(ui->SliderButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));
    connect(ui->SkrollButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));
    connect(ui->DialButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNumber()
{
    if(ui->SliderButton->isChecked()){
        ui->lcdNumber->display(ui->Slider->value());
    }
    if(ui->DialButton->isChecked()){
        ui->lcdNumber->display(ui->dial->value());
    }
    if(ui->SkrollButton->isChecked()){
        ui->lcdNumber->display(ui->Skroll->value());
    }
}
