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
    void generateHull();
    void moveSlider(int value);

    void playPressed();
    void pausePressed();
    void stopPressed();
    void endOfAlgorithm();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
