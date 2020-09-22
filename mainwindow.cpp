#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stop->setEnabled(false);
    thread = new Thread(this);
    /// connected to thread class signal which is value changed to slot on value changes
    /// it will change to progress bar when thread change the value
    connect(thread,SIGNAL(ValueChanged(int)),this,SLOT(OnValueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::OnValueChanged(const int &value) {
    ui->progressBar->setValue(value);
}

void MainWindow::on_start_clicked()
{
    ui->start->setEnabled(false);
    ui->stop->setEnabled(true);
    thread->start();
}

void MainWindow::on_stop_clicked()
{
    thread->stop();
    ui->stop->setEnabled(false);
    ui->start->setEnabled(true);
}

void MainWindow::on_manual_clicked()
{
    int value  = ui->manualProgress->value();
    if(value < 100)
        ui->manualProgress->setValue(value+5);
    else
        ui->manualProgress->setValue(0);


}
