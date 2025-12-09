#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QTimer>
#include <QPoint>
#include "snake.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard() override;

    void startGame();
    void pauseGame();
    void resetGame();

signals:
    void scoreChanged(int score);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void updateGame();
    void generateFood();
    bool checkCollision();

    Snake *m_snake;
    QTimer *m_gameTimer;
    QPoint m_food;
    int m_score;
    bool m_isGameRunning;
    bool m_isGamePaused;
    static const int GRID_SIZE = 20;
    static const int GAME_SPEED = 150; // 毫秒
};

#endif // GAMEBOARD_H