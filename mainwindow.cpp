#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建游戏板
    gameBoard = new GameBoard(ui->gameBoardWidget);
    // 检查gameBoardWidget是否已经有布局
    QLayout *layout = ui->gameBoardWidget->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->gameBoardWidget);
        layout->setContentsMargins(0, 0, 0, 0);
    }
    layout->addWidget(gameBoard);

    // 连接信号和槽
    connect(gameBoard, &GameBoard::scoreChanged, this, &MainWindow::updateScore);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    gameBoard->startGame();
}

void MainWindow::on_pauseButton_clicked()
{
    gameBoard->pauseGame();
}

void MainWindow::on_resetButton_clicked()
{
    gameBoard->resetGame();
    updateScore(0);
}

void MainWindow::updateScore(int score)
{
    ui->scoreLabel->setText(QString("分数: %1").arg(score));
}