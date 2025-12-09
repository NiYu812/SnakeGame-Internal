#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_resetButton_clicked();
    void updateScore(int score);

private:
    Ui::MainWindow *ui;
    GameBoard *gameBoard;
};

#endif // MAINWINDOW_H