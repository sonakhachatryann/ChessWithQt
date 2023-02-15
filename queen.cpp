#include "queen.h"
#include "game.h"

extern Game* game;

Queen::Queen(const QString& team, QGraphicsItem* parent)
    : ChessPiece(team, parent)
{
    Queen::SetImage();
}

void Queen::SetImage() {
    if (team_ == "WHITE") {
        setPixmap(QPixmap(":/image/queen_white.png"));
    }
    else {
        setPixmap(QPixmap(":/image/queen_black.png"));
    }
}

void Queen::Move() {
    possible_locations.clear();
    int row = get_box()->get_row();
    int col = get_box()->get_col();
    QString team = get_team();
    for (int i = row - 1, j = col; i >= 0; --i) { //up
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
    for (int i = row + 1, j = col; i <= 7; ++i) { //down
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
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) { //up left
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
    for (int i = row - 1, j = col + 1; i >= 0 && j <= 7; --i, ++j) { //up right
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
    for (int i = row + 1,j = col + 1; i <= 7 && j <= 7; ++i, ++j) { //down right
        if (game->all_pieces_[i][j]->get_chess_piece_color() == team) {
            break;
        }
        else {
            possible_locations.append(game->all_pieces_[i][j]);
            if (BoxSetting(possible_locations.last())){
                break;
            }
        }
    }
    for (int i = row + 1, j = col - 1; i <= 7 && j >= 0; ++i, --j) { //down left
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
