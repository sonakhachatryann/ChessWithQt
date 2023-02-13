#include "chesspiece.h"
#include "game.h"
#include "king.h"

extern Game* game;

ChessPiece::ChessPiece(QString team, QGraphicsItem* parent) 
    : is_placed_(true)
    , team_(team)
    , first_move_(true)
    , QGraphicsPixmapItem(parent)
{}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (this == game->piece_to_move_) {
        game->piece_to_move_->get_box()->set_brush(game->piece_to_move_->get_box()->get_color());
        game->piece_to_move_->Decolor();
        game->piece_to_move_ = nullptr;
        return;
    }
    if ((!get_is_placed()) || ((game->get_turn() != get_team()) && (!game->piece_to_move_))) {
        return;
    }
    if (!game->piece_to_move_) {
        game->piece_to_move_ = this;
        game->piece_to_move_->get_box()->set_brush(Qt::red);
        game->piece_to_move_->Move();
    }
    else if (get_team() != game->piece_to_move_->get_team()) {
        get_box()->mousePressEvent(event);
    }
}

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

void ChessPiece::Decolor() {
    for(qsizetype i = 0; i < possible_locations.size(); ++i) {
        possible_locations[i]->set_brush(possible_locations[i]->get_color());
    }
}

bool ChessPiece::BoxSetting(ChessBox* box) {
    if (box->get_has_chess_piece()) {
        King* q = dynamic_cast<King*>(possible_locations.last()->current_piece_);
        if (q) {
            box->set_brush(Qt::blue); //if in the box was the King
        }
        else {
            box->set_brush(Qt::red); //if in the box is potential victim
        }
        return true; //the box wasn't empty
    }
    else {
        possible_locations.last()->set_brush(Qt::darkRed); //if the box was empty
    }
    return false;
}
