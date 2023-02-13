#ifndef ROOK_H
#define ROOK_H

#include "chesspiece.h"

class Rook : public ChessPiece {
public:
    Rook(const QString& team, QGraphicsItem* = nullptr);

    void SetImage();
    void Move();
};

#endif // ROOK_H
