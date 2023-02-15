#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

class Button : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Button(const QString&, QGraphicsItem* parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    void clicked();

private:
    QGraphicsTextItem* text;
};
#endif // BUTTON_H
