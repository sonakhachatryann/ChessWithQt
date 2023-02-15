#include "knight.h"
#include "game.h"

extern Game* game;

Knight::Knight(const QString& team, QGraphicsItem* parent)
    : ChessPiece(team, parent) {
    Knight::SetImage();
}

void Knight::SetImage() {
    if (team_ == "WHITE") {
        setPixmap(QPixmap(":/image/knight_white.png"));
    }
    else {
        setPixmap(QPixmap(":/image/knight_black.png"));
    }
}

void Knight::Move() {
    int row = get_box()->get_row();
    int col = get_box()->get_col();
    int i = 0;
    int j = 0;
    QString team = get_team();
    i = row - 2; //up left
    j = col - 1;
    if (i >= 0 && j >= 0 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red); //possible victim
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
    i = row - 2; //up right
    j = col + 1;
    if (i >= 0 && j <= 7 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
    i = row + 2; //down left
    j = col - 1;
    if (i <= 7 && j >= 0 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if(possible_locations.last()->get_has_chess_piece())
            possible_locations.last()->set_brush(Qt::red);
        else
            possible_locations.last()->set_brush(Qt::darkRed);
    }
    i = row + 2; //down right
    j = col + 1;
    if (i <= 7 && j <= 7 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
    i = row - 1; //up left
    j = col - 2;
    if (i >= 0 && j >= 0 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
    i = row + 1; //down left
    j = col - 2;
    if (i <= 7 && j >= 0 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
    i = row - 1; //up right
    j = col + 2;
    if (i >= 0 && j <= 7 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
    i = row + 1; //down right
    j = col + 2;
    if (i <= 7 && j <= 7 && (game->all_pieces_[i][j]->get_chess_piece_color() != team)) {
        possible_locations.append(game->all_pieces_[i][j]);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
        else {
            possible_locations.last()->set_brush(Qt::darkRed);
        }
    }
}
