#include "mainwindow.h"
#include "./ui_mainwindow.h"


double num_first;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));



    connect(ui->pushButton_znak,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_prosen,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_sum,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_add,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_del->setCheckable(true);
    ui->pushButton_sum->setCheckable(true);
    ui->pushButton_add->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = ( QPushButton *) sender();
    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".")&&button->text()== "0"){
        new_label = ui->result_show->text() + button->text();
    }else{
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);

    }



    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text()+ ".");
}

void MainWindow::operations()
{
    QPushButton *button = ( QPushButton *) sender();
    double all_numbers;
    QString new_label;
    if(button->text() == "+/-")
    {
      all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * -1;
      new_label = QString::number(all_numbers, 'g', 15);

      ui->result_show->setText(new_label);
    }
    else     if(button->text() == "%")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = ( QPushButton *) sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");

    button->setCheckable(true);

}

void MainWindow::on_pushButton_clicked() //ochistka
{
    ui->pushButton_sum->setChecked(false);
    ui->pushButton_min->setChecked(false);
    ui->pushButton_add->setChecked(false);
    ui->pushButton_del->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_ravno_clicked()
{
    double lobelNumber, num_second;
    QString new_label;
    num_second = ui->result_show->text().toDouble();


    if(ui->pushButton_sum->isChecked()){
        lobelNumber = num_first + num_second;
        new_label = QString::number(lobelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_sum->setChecked(false);
    }
    else     if(ui->pushButton_min->isChecked()){

        lobelNumber = num_first - num_second;
        new_label = QString::number(lobelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_min->setChecked(false);
    }
    else     if(ui->pushButton_add->isChecked()){
        lobelNumber = num_first * num_second;
        new_label = QString::number(lobelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_add->setChecked(false);


    }
    else     if(ui->pushButton_del->isChecked()){
        if(num_second == 0){
            ui->result_show->setText("0");
        }
        else{
        lobelNumber = num_first / num_second;
        new_label = QString::number(lobelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_del->setChecked(false);
        }

    }

}

