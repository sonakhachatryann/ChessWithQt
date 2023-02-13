#ifndef CHESSBOX_H
#define CHESSBOX_H

#include "chesspiece.h"

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class ChessPiece;

class ChessBox : public QGraphicsRectItem {
public:
    ChessBox(QGraphicsItem* parent = nullptr);
    ~ChessBox();

    void mousePressEvent(QGraphicsSceneMouseEvent*);

    int get_row() const;
    void set_row(int);
    int get_col() const;
    void set_col(int);
    bool get_has_chess_piece() const;
    void set_has_chess_piece(bool, ChessPiece* = nullptr);
    QString get_chess_piece_color() const;
    void set_chess_piece_color(const QString&);
    void set_brush(const QColor&);
    QColor get_color() const;
    ChessPiece* get_current_piece() const;
    void set_current_piece(ChessPiece*);
    void set_color(const QColor&);
    void PlacePiece(ChessPiece*);
    void Check();
    void ResetOriginalColor();

public:
    ChessPiece* current_piece_;

private:
    int row_;
    int col_;
    bool has_chess_piece_;
    QString chess_piece_color_;
    QColor color_;
    QBrush brush_;
};

#endif // CHESSBOX_H
