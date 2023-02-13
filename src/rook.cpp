#include "rook.h"
#include "game.h"

extern Game* game;

Rook::Rook(const QString& team, QGraphicsItem* parent)
    : ChessPiece(team, parent) {
    Rook::SetImage();
}

void Rook::SetImage() {
    if (team_ == "WHITE") {
        setPixmap(QPixmap(":/image/rook_white.png"));
    }
    else {
        setPixmap(QPixmap(":/image/rook_black.png"));
    }
}

void Rook::Move() {
    int row = get_box()->get_row();
    int col = get_box()->get_col();
    QString team = get_team();
    for (int i = row - 1, j = col; i >= 0; --i) { //up
        if (game->all_pieces_[i][j]->get_chess_piece_color() == team) {
            break;
        }
        else {
            possible_locations.append(game->all_pieces_[i][j]);
            if(BoxSetting(possible_locations.last())) {
                break;
            }
        }
    }
    for (int i = row + 1,j = col; i <= 7; ++i) { //down
        if (game->all_pieces_[i][j]->get_chess_piece_color() == team) {
            break;
        }
        else {
            possible_locations.append(game->all_pieces_[i][j]);
            if(BoxSetting(possible_locations.last())) {
                break;
            }
        }
    }
    for (int i = row, j = col - 1; j >= 0; --j) { //left
        if (game->all_pieces_[i][j]->get_chess_piece_color() == team) {
            break;
        }
        else {
            possible_locations.append(game->all_pieces_[i][j]);
            if (BoxSetting(possible_locations.last())) {
                break;
            }
        }
    }
    for (int i = row, j = col + 1; j <= 7; ++j) { //right
        if (game->all_pieces_[i][j]->get_chess_piece_color() == team) {
            break;
        }
        else {
            possible_locations.append(game->all_pieces_[i][j]);
            if (BoxSetting(possible_locations.last())) {
                break;
            }
        }
    }
}
