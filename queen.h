#ifndef QUEEN_H
#define QUEEN_H

#include "chesspiece.h"

class Queen : public ChessPiece {
public:
    Queen(const QString& team, QGraphicsItem* = nullptr);

    void SetImage() override;
    void Move() override;
};

#endif // QUEEN_H
