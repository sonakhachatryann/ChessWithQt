#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include "chesspiece.h"

class ChessPiece;
class ChessBox : public QGraphicsRectItem {
public:
    ChessBox(QGraphicsItem* parent = nullptr);
    ~ChessBox();

    //getters/setters
    int get_row() const;
    void set_row(int);
    int get_col() const;
    void set_col(int);
    bool get_has_chess_piece() const;
    void set_has_chess_piece(bool);
    QString get_chess_piece_color() const;
    void set_chess_piece_color(const QString&);
    void set_color(const QColor&);
    QColor get_color() const;
    ChessPiece* get_current_piece() const;
    void set_current_piece(ChessPiece*);

    void ResetInitialColor();
    void placePiece(ChessPiece* piece);

private:
    int row_;
    int col_;
    bool has_chess_piece_;
    QString chess_piece_color_;
    QColor color_;
    QBrush brush;
    ChessPiece* current_piece_;
};

#endif // CHESSBOX_H
