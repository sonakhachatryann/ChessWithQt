#include "chessbox.h"

ChessBox::ChessBox(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
    , current_piece_(nullptr)
{
    setRect(0,0,80,80);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    set_has_chess_piece(false);
    set_chess_piece_color("NONE");
}

ChessBox::~ChessBox() {
    delete current_piece_;
}

int ChessBox::get_row() const {
    return row_;
}

void ChessBox::set_row(int row) {
    row_ = row;
}

int ChessBox::get_col() const {
    return col_;
}

void ChessBox::set_col(int col) {
    col_ = col;
}

bool ChessBox::get_has_chess_piece() const {
    return has_chess_piece_;
}

void ChessBox::set_has_chess_piece(bool has_chess_piece) {
    has_chess_piece_ = has_chess_piece;
}

QString ChessBox::get_chess_piece_color() const {
    return chess_piece_color_;
}

void ChessBox::set_chess_piece_color(const QString& chess_piece_color) {
    chess_piece_color_ = chess_piece_color;
}

void ChessBox::set_color(const QColor& color) {
    color_ = color;
    brush.setColor(color_);
    setBrush(color_);
}

QColor ChessBox::get_color() const {
    return color_;
}

ChessPiece* ChessBox::get_current_piece() const {
    return current_piece_;
}

void ChessBox::set_current_piece(ChessPiece* piece) {
    current_piece_ = piece;
}

void ChessBox::ResetInitialColor() {
    brush.setColor(color_);
    setBrush(color_);
}
