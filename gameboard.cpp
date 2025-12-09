#include "gameboard.h"
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>

GameBoard::GameBoard(QWidget *parent) : QWidget(parent)
{
    m_snake = new Snake(this);
    m_gameTimer = new QTimer(this);
    m_score = 0;
    m_isGameRunning = false;
    m_isGamePaused = false;

    // 设置固定大小
    setFixedSize(GRID_SIZE * 20, GRID_SIZE * 20);

    // 连接定时器信号
    connect(m_gameTimer, &QTimer::timeout, this, &GameBoard::updateGame);

    // 生成初始食物
    generateFood();
}

GameBoard::~GameBoard()
{
    delete m_snake;
    delete m_gameTimer;
}

void GameBoard::startGame()
{
    if (!m_isGameRunning) {
        m_isGameRunning = true;
        m_isGamePaused = false;
        m_gameTimer->start(GAME_SPEED);
        setFocus(); // 获取焦点以接收键盘事件
    } else if (m_isGamePaused) {
        m_isGamePaused = false;
        m_gameTimer->start(GAME_SPEED);
        setFocus();
    }
}

void GameBoard::pauseGame()
{
    if (m_isGameRunning && !m_isGamePaused) {
        m_isGamePaused = true;
        m_gameTimer->stop();
    }
}

void GameBoard::resetGame()
{
    m_gameTimer->stop();
    m_snake->reset();
    m_score = 0;
    m_isGameRunning = false;
    m_isGamePaused = false;
    generateFood();
    update();
    emit scoreChanged(m_score);
}

void GameBoard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制网格背景
    painter.setPen(QColor(200, 200, 200));
    for (int i = 0; i <= width(); i += GRID_SIZE) {
        painter.drawLine(i, 0, i, height());
    }
    for (int i = 0; i <= height(); i += GRID_SIZE) {
        painter.drawLine(0, i, width(), i);
    }

    // 绘制食物
    painter.setBrush(QColor(255, 0, 0));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(m_food.x() * GRID_SIZE + 1, m_food.y() * GRID_SIZE + 1,
                         GRID_SIZE - 2, GRID_SIZE - 2);

    // 绘制蛇
    QList<QPoint> snakeBody = m_snake->getBody();
    for (int i = 0; i < snakeBody.size(); ++i) {
        if (i == 0) {
            // 蛇头颜色不同
            painter.setBrush(QColor(0, 100, 0));
        } else {
            painter.setBrush(QColor(0, 150, 0));
        }
        painter.setPen(Qt::NoPen);
        painter.drawRect(snakeBody[i].x() * GRID_SIZE + 1,
                         snakeBody[i].y() * GRID_SIZE + 1,
                         GRID_SIZE - 2, GRID_SIZE - 2);
    }

    // 绘制游戏状态
    if (m_isGamePaused) {
        painter.setBrush(QColor(0, 0, 0, 128));
        painter.drawRect(0, 0, width(), height());
        painter.setPen(QColor(255, 255, 255));
        painter.setFont(QFont("Arial", 24));
        painter.drawText(rect(), Qt::AlignCenter, "游戏暂停");
    }
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    if (!m_isGameRunning || m_isGamePaused) {
        return;
    }

    switch (event->key()) {
    case Qt::Key_Up:
        m_snake->setDirection(Snake::Up);
        break;
    case Qt::Key_Down:
        m_snake->setDirection(Snake::Down);
        break;
    case Qt::Key_Left:
        m_snake->setDirection(Snake::Left);
        break;
    case Qt::Key_Right:
        m_snake->setDirection(Snake::Right);
        break;
    default:
        break;
    }
}

void GameBoard::updateGame()
{
    m_snake->move();

    // 检查是否吃到食物
    if (m_snake->getBody().first() == m_food) {
        m_snake->grow();
        m_score += 10;
        generateFood();
        emit scoreChanged(m_score);
    }

    // 检查碰撞
    if (checkCollision()) {
        m_gameTimer->stop();
        m_isGameRunning = false;
        // 可以添加游戏结束的提示
    }

    update();
}

void GameBoard::generateFood()
{
    QRandomGenerator *generator = QRandomGenerator::global();
    int maxX = width() / GRID_SIZE;
    int maxY = height() / GRID_SIZE;

    do {
        m_food.setX(generator->bounded(maxX));
        m_food.setY(generator->bounded(maxY));
    } while (m_snake->getBody().contains(m_food));
}

bool GameBoard::checkCollision()
{
    QPoint head = m_snake->getBody().first();
    QList<QPoint> body = m_snake->getBody();

    // 检查是否撞墙
    if (head.x() < 0 || head.x() >= width() / GRID_SIZE ||
        head.y() < 0 || head.y() >= height() / GRID_SIZE) {
        return true;
    }

    // 检查是否撞到自己的身体
    for (int i = 1; i < body.size(); ++i) {
        if (head == body[i]) {
            return true;
        }
    }

    return false;
}