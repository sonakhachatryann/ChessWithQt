#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(const QString&, QGraphicsItem* = nullptr);
    void SetImage();
    void Move();
};

#endif // PAWN_H
