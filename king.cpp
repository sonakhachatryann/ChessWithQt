#include "king.h"

extern Game* game;

King::King(const QString& team, QGraphicsItem* parent)
    : ChessPiece(team, parent)
{
    King::SetImage();
}

void King::SetImage()
{
    if (team_ == "WHITE") {
        setPixmap(QPixmap(":/image/king_white.png"));
    }
    else {
        setPixmap(QPixmap(":/image/king_black.png"));
    }
}

void King::Move() {
    possible_locations.clear();
    int row = get_box()->get_row();
    int col = get_box()->get_col();
    QString team = get_team();
    if (col > 0 && row > 0 && !(game->all_pieces_[row - 1][col - 1]->get_chess_piece_color() == team)) { //left up is not a mate
        possible_locations.append(game->all_pieces_[row - 1][col - 1]);
        game->all_pieces_[row - 1][col - 1]->set_brush(Qt::darkRed);
        if(possible_locations.last()->get_has_chess_piece()) { //a potential victim
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (col < 7 && row > 0 && !(game->all_pieces_[row - 1][col + 1]->get_chess_piece_color() == team)) { //right up is not a mate
        possible_locations.append(game->all_pieces_[row - 1][col + 1]);
        game->all_pieces_[row - 1][col + 1]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (row > 0 && !(game->all_pieces_[row - 1][col]->get_chess_piece_color() == team)) { //front is not a mate
        possible_locations.append(game->all_pieces_[row - 1][col]);
        game->all_pieces_[row - 1][col]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (row < 7 && !(game->all_pieces_[row + 1][col]->get_chess_piece_color() == team)) { //back is not a mate
        possible_locations.append(game->all_pieces_[row + 1][col]);
        game->all_pieces_[row + 1][col]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (col > 0 && !(game->all_pieces_[row][col - 1]->get_chess_piece_color() == team)) { //the same for right side
        possible_locations.append(game->all_pieces_[row][col - 1]);
        game->all_pieces_[row][col - 1]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (col < 7 && !(game->all_pieces_[row][col + 1]->get_chess_piece_color() == team)) { //the same for left one
        possible_locations.append(game->all_pieces_[row][col + 1]);
        game->all_pieces_[row][col + 1]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (col > 0 && row < 7 && !(game->all_pieces_[row + 1][col - 1]->get_chess_piece_color() == team)) { //left down
        possible_locations.append(game->all_pieces_[row + 1][col - 1]);
        game->all_pieces_[row + 1][col - 1]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    if (col < 7 && row < 7 && !(game->all_pieces_[row + 1][col + 1]->get_chess_piece_color() == team)) { //right up
        possible_locations.append(game->all_pieces_[row + 1][col + 1]);
        game->all_pieces_[row + 1][col + 1]->set_brush(Qt::darkRed);
        if (possible_locations.last()->get_has_chess_piece()) {
            possible_locations.last()->set_brush(Qt::red);
        }
    }
    FindUnSafeLocation();
}

void King::FindUnSafeLocation() {
    QList<ChessPiece*> pList = game->pieces_on_board_;
    for (qsizetype i = 0; i < pList.size(); ++i) {
        if (pList[i]->get_team() != get_team()) { //if the piece is from the rival team
            QList<ChessBox*> bList = pList[i]->get_possible_locations();
            for (qsizetype j = 0; j < bList.size(); ++j) {
                Pawn* c = dynamic_cast<Pawn*>(pList[i]) ;
                if (c) {
                    continue;
                }
                for (qsizetype k = 0; k < possible_locations.size(); ++k) {
                   if (bList[j] == possible_locations[k]) {
                       possible_locations[k]->set_brush(Qt::blue); //with blue are marked the places the King can't go
                   }
                }
            }
        }
    }
}
