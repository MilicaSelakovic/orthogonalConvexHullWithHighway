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

void MainWindow::generateHull()
{
    float speed = ui->doubleSpinBox->value();
    int number = ui->spinBox->value();

    ui->doubleSpinBox->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    ui->horizontalSlider->setMaximum(number);
    ui->pushButton->setEnabled(true);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_3->setEnabled(true);

    ui->widget->generateHull(number, speed);
}

void MainWindow::moveSlider(int value)
{
    ui->horizontalSlider->setValue(value);
}

void MainWindow::playPressed()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    ui->horizontalSlider->setEnabled(false);
}

void MainWindow::pausePressed()
{
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(false);
}

void MainWindow::stopPressed()
{
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);


    ui->doubleSpinBox->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->pushButton_2->setEnabled(true);

}

void MainWindow::endOfAlgorithm()
{
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
}

void MainWindow::enablePlay(int value)
{
    int number = ui->spinBox->value();

    if(number == value){
        ui->pushButton_3->setEnabled(false);
    } else {
        ui->pushButton_3->setEnabled(true);
    }

}

