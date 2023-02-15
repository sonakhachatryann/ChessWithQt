#ifndef KNIGHT_H
#define KNIGHT_H

#include "chesspiece.h"

class Knight : public ChessPiece {
public:
    Knight(const QString& team, QGraphicsItem* = nullptr);

    void SetImage();
    void Move();
};

#endif // KNIGHT_H
