#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QSettings"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    LoadSettings();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    SaveSettings();
    delete ui;
}

void MainWindow::on_btn_calculate_clicked()
{
    if(ui->lineVal2->text().isEmpty() || ui->line_val1->text().isEmpty()){
        QMessageBox::information(this, tr("Info..."), tr("All values need to be filled."));
    }else{

        double first_val = ui->line_val1->text().trimmed().toDouble();
        double second_val = ui->lineVal2->text().trimmed().toDouble();

        double diff = second_val - first_val;
        double result = ((diff/first_val) * 100 );

        ui->doubleSpinBox->setValue(result);
        ui->doubleSpinBox->setSuffix("%");
        ui->lineVal2->clear();
        ui->lineVal2->setFocus();
    }
}

void MainWindow::SaveSettings()
{
    QSettings setting("bedi1982","Porcenteitor");
    setting.beginGroup("MainWindow");
    setting.setValue("position",this->geometry());
    setting.endGroup();
}

void MainWindow::LoadSettings()
{
    QSettings setting("bedi1982","Porcenteitor");
    setting.beginGroup("MainWindow");
    QRect myrect = setting.value("position").toRect();
    setGeometry(myrect);
    setting.endGroup();
}
//End block to keep windows position and size//
