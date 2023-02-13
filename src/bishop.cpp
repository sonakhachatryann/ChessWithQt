#include "bishop.h"
#include "game.h"

extern Game* game;

Bishop::Bishop(const QString& team, QGraphicsItem* parent)
    : ChessPiece(team, parent)
{
    Bishop::SetImage();
}

void Bishop::SetImage() {
    if (team_ == "WHITE") {
        setPixmap(QPixmap(":/image/bishop_white.png"));
    }
    else {
        setPixmap(QPixmap(":/image/bishop_black.png"));
    }
}


void Bishop::Move() {
    possible_locations.clear();
    int row = get_box()->get_row();
    int col = get_box()->get_col();
    QString team = get_team();
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
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
    for(int i = row - 1, j = col + 1; i >= 0 && j <= 7; --i, ++j) {
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
    for (int i = row + 1, j = col + 1; i <= 7 && j <= 7; ++i, ++j) {
        if (game->all_pieces_[i][j]->get_chess_piece_color() == team) {
            break;
        }
        else {
            possible_locations.append(game->all_pieces_[i][j]);
            if(BoxSetting(possible_locations.last())){
                break;
            }
        }
    }
    for (int i = row + 1, j = col - 1; i <= 7 && j >= 0; ++i, --j) {
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
}
