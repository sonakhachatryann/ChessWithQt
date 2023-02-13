#include "pawn.h"
#include "game.h"
#include <typeinfo>
#include "king.h"

extern Game* game;

Pawn::Pawn(const QString& team, QGraphicsItem* parent)
    : ChessPiece(team, parent)
{
    first_move_ = true;
    Pawn::SetImage();
}

void Pawn::SetImage()
{
    if (team_ == "WHITE") {
        setPixmap(QPixmap(":/image/pawn_white.png"));
    }
    else {
        setPixmap(QPixmap(":/image/pawn_black.png"));
    }
}

void Pawn::Move() {
    possible_locations.clear();
    int row = get_box()->get_row();
    int col = get_box()->get_col();
    if (get_team() == "WHITE") {
        if (col > 0 && row > 0 && game->all_pieces_[row - 1][col - 1]->get_chess_piece_color() == "BLACK") { //up left is black
            possible_locations.append(game->all_pieces_[row - 1][col - 1]);
            BoxSetting(possible_locations.last());
        }
        if (col < 7 && row > 0 && game->all_pieces_[row - 1][col + 1]->get_chess_piece_color() == "BLACK") { //up right is black
            possible_locations.append(game->all_pieces_[row - 1][col + 1]);
            BoxSetting(possible_locations.last());
        }
        if (row > 0 && !(game->all_pieces_[row - 1][col]->get_has_chess_piece())) { //front is free
            possible_locations.append(game->all_pieces_[row - 1][col]);
            BoxSetting(possible_locations.last());
            if (first_move_ && !(game->all_pieces_[row - 2][col]->get_has_chess_piece())) { //front 2 places are free
                possible_locations.append(game->all_pieces_[row - 2][col]);
                BoxSetting(possible_locations.last());
            }
        }
    }
    else { //the same for blacks
        if (col > 0 && row < 7 && game->all_pieces_[row + 1][col - 1]->get_chess_piece_color() == "WHITE") {
            possible_locations.append(game->all_pieces_[row + 1][col - 1]);
            BoxSetting(possible_locations.last());
        }
        if (col < 7 && row <  7 && game->all_pieces_[row + 1][col + 1]->get_chess_piece_color() == "WHITE") {
            possible_locations.append(game->all_pieces_[row + 1][col + 1]);
            BoxSetting(possible_locations.last());
        }
        if (row < 7 && (!game->all_pieces_[row + 1][col]->get_has_chess_piece())) {
            possible_locations.append(game->all_pieces_[row + 1][col]);
            BoxSetting(possible_locations.last());
            if (first_move_ && !game->all_pieces_[row + 2][col]->get_has_chess_piece()) {
                possible_locations.append(game->all_pieces_[row + 2][col]);
                BoxSetting(possible_locations.last());
            }
        }
    }
}
