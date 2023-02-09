#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QGraphicsPixmapItem>
#include <QString>
#include "chessbox.h"

class ChessBox;
class ChessPiece : public QGraphicsPixmapItem {
public:
    ChessPiece(QString team = "", QGraphicsItem* parent = 0);

    //getters and setters
    bool get_is_placed() const;
    void set_is_placed(bool);
    QString get_team() const;
    void set_team(const QString&);
    ChessBox* get_box() const;
    void set_box(ChessBox*);
    QList<ChessBox*> get_possible_locations() const;

    virtual void SetImage() = 0;
    virtual void Move() = 0;

protected:
    void Decolor();

private:
    bool is_placed_;
    QString team_;
    ChessBox* box_;
    QList<ChessBox*> possible_locations;
};

#endif // CHESSPIECE_H
