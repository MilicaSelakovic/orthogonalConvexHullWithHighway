#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"



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
    int number = ui->spinBox->value();

    ui->widget->generateHull(number);
}


void MainWindow::insertPoint()
{
      ui->widget->insertPoint(ui->spinBox_2->value(), ui->spinBox_3->value());
}

void MainWindow::moveSlider(int value)
{
    ui->horizontalSlider->setValue(value);
}

void MainWindow::playPressed()
{
    int number = ui->widget->numberOfPoints();

    ui->doubleSpinBox->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

    ui->spinBox_2->setEnabled(false);
    ui->spinBox_3->setEnabled(false);

    ui->horizontalSlider->setMaximum(number);
    ui->pushButton->setEnabled(true);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_3->setEnabled(true);

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
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(false);


    ui->doubleSpinBox->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);

    ui->spinBox_2->setEnabled(true);
    ui->spinBox_3->setEnabled(true);

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

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionHelp_RS_triggered()
{
    Dialog * dialog = new Dialog(this);

    dialog->show();

    dialog->setSerbianContnet();

}

