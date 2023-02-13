#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(const QString& name, QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
    text = new QGraphicsTextItem(name, this);
    int x_pos = rect().width() / 2 - text->boundingRect().width() / 2;
    int y_pos = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(x_pos, y_pos);
    text->setDefaultTextColor(Qt::white);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event) {
        emit clicked();
    }
}
