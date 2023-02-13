#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h"

class Bishop : public ChessPiece {
public:
    Bishop(const QString& team, QGraphicsItem* = nullptr);

    void SetImage() override;
    void Move() override;
};

#endif // BISHOP_H
