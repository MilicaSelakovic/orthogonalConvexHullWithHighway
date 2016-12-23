#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /*
     * slot koji je povezan sa signalom pritiska dugmeta generateHull
     * delegira informaciju drawarea da generise skup tacaka i pocne generisanje omotaca
     */
    void generateHull();
    void moveSlider(int value);

    void playPressed();
    void pausePressed();
    void stopPressed();
    void endOfAlgorithm();

    void enablePlay(int value);


    void insertPoint();

private slots:

    void on_actionClose_triggered();

    void on_actionHelp_RS_triggered();
    //void on_actionHelp_EN_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
