#include "chesspiece.h"

ChessPiece::ChessPiece(QString team, QGraphicsItem* parent)
    : team_(team)
    , is_placed_(true) {}

bool ChessPiece::get_is_placed() const {
    return is_placed_;
}

void ChessPiece::set_is_placed(bool is_placed) {
    is_placed_ = is_placed;
}

QString ChessPiece::get_team() const {
    return team_;
}

void ChessPiece::set_team(const QString& team) {
    team_ = team;
}

ChessBox* ChessPiece::get_box() const {
    return box_;
}

void ChessPiece::set_box(ChessBox* box) {
    box_ = box;
}

QList<ChessBox*> ChessPiece::get_possible_locations() const {
    return possible_locations;
}
