#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_calculate_clicked()
{
    double first_val = ui->line_val1->text().trimmed().toDouble();
    double second_val = ui->lineVal2->text().trimmed().toDouble();

    double diff = second_val - first_val;
    double result = ((diff/first_val) * 100 );

    ui->doubleSpinBox->setValue(result);


}
