#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;
bool is_operation = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()) , this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_sign, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_proc, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_div->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{

    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(is_operation) {
        new_label = button->text();
        is_operation = false;
    }
    else if(ui->result_show->text().contains('.') && button->text() == "0") {
        new_label = ui->result_show->text() + button->text();
    }
    else {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::operations()
{

    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
    else if(button->text() == "%") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{

    QPushButton *button = (QPushButton *)sender();
    num_first = ui->result_show->text().toDouble();

    ui->result_show->setText(button->text());

    button->setChecked(true);
    is_operation = true;
}





void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_div->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);

    ui->result_show->setText("0");
}


void MainWindow::on_pushButton_equal_clicked()
{
    double label_number, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_div->isChecked()) {
        if(num_second == 0) {
            ui->result_show->setText("Invalid operation");
        }
        else {
            label_number = num_first / num_second;
            new_label = QString::number(label_number, 'g', 15);

            ui->result_show->setText(new_label);
        }

        ui->pushButton_div->setChecked(false);
    }
    else if(ui->pushButton_mult->isChecked()) {
        label_number = num_first * num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()) {
        label_number = num_first - num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_plus->isChecked()) {
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }

}


void MainWindow::on_pushButton_C_clicked()
{
    QString new_label;

    new_label = ui->result_show->text();
    if(new_label == "0") {

    }
    else if(new_label.size() == 1) {
        new_label = "0";
    }
    else {
        new_label.resize(new_label.size() - 1);
    }

    if(new_label[new_label.size() - 1] == ".") {
        new_label.resize(new_label.size() - 1);
    }

    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_Z_clicked()
{
    double all_numbers;
    QString new_label;

    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = all_numbers * (1 - 0.14);
    new_label = QString::number(all_numbers, 'g', 15);

    ui->result_show->setText(new_label);
}

