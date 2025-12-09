#include "snake.h"

Snake::Snake(QObject *parent) : QObject(parent)
{
    reset();
}

Snake::~Snake()
{
}

QList<QPoint> Snake::getBody() const
{
    return m_body;
}

Snake::Direction Snake::getDirection() const
{
    return m_direction;
}

bool Snake::isGrowing() const
{
    return m_isGrowing;
}

void Snake::setDirection(Direction direction)
{
    // 防止蛇直接反向移动
    if ((m_direction == Up && direction == Down) ||
        (m_direction == Down && direction == Up) ||
        (m_direction == Left && direction == Right) ||
        (m_direction == Right && direction == Left)) {
        return;
    }

    m_direction = direction;
}

void Snake::move()
{
    // 获取蛇头位置
    QPoint head = m_body.first();

    // 根据方向计算新的蛇头位置
    switch (m_direction) {
    case Up:
        head.setY(head.y() - 1);
        break;
    case Down:
        head.setY(head.y() + 1);
        break;
    case Left:
        head.setX(head.x() - 1);
        break;
    case Right:
        head.setX(head.x() + 1);
        break;
    }

    // 将新蛇头插入到身体前部
    m_body.prepend(head);

    // 如果不是在生长，则移除尾部
    if (!m_isGrowing) {
        m_body.removeLast();
    } else {
        m_isGrowing = false;
    }
}

void Snake::grow()
{
    m_isGrowing = true;
}

void Snake::reset()
{
    m_body.clear();
    // 初始化蛇的身体，从(10,10)开始，长度为3
    for (int i = 0; i < INITIAL_LENGTH; ++i) {
        m_body.append(QPoint(10 - i, 10));
    }
    m_direction = Right;
    m_isGrowing = false;
}