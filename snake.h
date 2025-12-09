#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QPoint>
#include <QList>

class Snake : public QObject
{
    Q_OBJECT

public:
    enum Direction {
        Up,
        Down,
        Left,
        Right
    };

    explicit Snake(QObject *parent = nullptr);
    ~Snake() override;

    QList<QPoint> getBody() const;
    Direction getDirection() const;
    bool isGrowing() const;

    void setDirection(Direction direction);
    void move();
    void grow();
    void reset();

private:
    QList<QPoint> m_body;
    Direction m_direction;
    bool m_isGrowing;
    static const int INITIAL_LENGTH = 3;
};

#endif // SNAKE_H