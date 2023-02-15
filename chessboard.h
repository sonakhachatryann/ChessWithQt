#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsItem>
#include "chesspiece.h"

class ChessBoard {

public:
    ChessBoard();

    void DrawChessBoxes();
    void DrawWhites();
    void DrawBlacks();
    void AddPiece();
    void Reset();

private:
    QList<ChessPiece*> whites_;
    QList<ChessPiece*> blacks_;
};

#endif // CHESSBOARD_H
