#ifndef KING_H
#define KING_H

#include "chesspiece.h"
#include "game.h"
#include "pawn.h"

class King : public ChessPiece {

public:
    King(const QString&, QGraphicsItem* = nullptr);
    void Move() override;
    void SetImage() override;
    void FindUnSafeLocation();
};

#endif // KING_H
