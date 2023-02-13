#include "chessboard.h"
#include "game.h"
#include "bishop.h"

extern Game* game;

ChessBoard::ChessBoard() {
    DrawWhites();
    DrawBlacks();
}

void ChessBoard::DrawChessBoxes() {
    int shift = 80;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            ChessBox* box = new ChessBox();
            game->all_pieces_[i][j] = box;
            box->set_row(i);
            box->set_col(j);
            box->setPos(330 + shift * j, 30 + shift * i);
            if ((i + j) % 2 == 0) {
                box->set_color(Qt::lightGray);
            }
            else {
                box->set_color(Qt::darkGray);
            }
            game->get_scene()->addItem(box);
            game->set_scene(game->get_scene());
        }
    }
}

void ChessBoard::AddPiece() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ChessBox* box = game->all_pieces_[i][j];
            if (i < 2) {
                static int k;
                box->PlacePiece(blacks_[k]);
                game->pieces_on_board_.append(blacks_[k]);
                game->get_scene()->addItem(blacks_[k++]);
            }
            if(i > 5) {
                static int h;
                box->PlacePiece(whites_[h]);
                game->pieces_on_board_.append(whites_[h]);
                game->get_scene()->addItem(whites_[h++]);
            }
        }
    }
}

void ChessBoard::DrawWhites() {
    ChessPiece* piece;
    for(int i = 0; i < 8; ++i) {
        piece = new Pawn("WHITE");
        whites_.append(piece);
    }
    piece = new Rook("WHITE");
    whites_.append(piece);
    piece = new Knight("WHITE");
    whites_.append(piece);
    piece = new Bishop("WHITE");
    whites_.append(piece);
    piece = new Queen("WHITE");
    whites_.append(piece);
    piece = new King("WHITE");
    whites_.append(piece);
    piece = new Bishop("WHITE");
    whites_.append(piece);
    piece = new Knight("WHITE");
    whites_.append(piece);
    piece = new Rook("WHITE");
    whites_.append(piece);
}

void ChessBoard::DrawBlacks() {
    ChessPiece* piece;
    piece = new Rook("BLACK");
    blacks_.append(piece);
    piece = new Knight("BLACK");
    blacks_.append(piece);
    piece = new Bishop("BLACK");
    blacks_.append(piece);
    piece = new Queen("BLACK");
    blacks_.append(piece);
    piece = new King("BLACK");
    blacks_.append(piece);
    piece = new Bishop("BLACK");
    blacks_.append(piece);
    piece = new Knight("BLACK");
    blacks_.append(piece);
    piece = new Rook("BLACK");
    blacks_.append(piece);
    for (int i = 0; i < 8; ++i) {
        piece = new Pawn("BLACK");
        blacks_.append(piece);
    }
}

void ChessBoard::Reset() {
    int k = 0;
    int h = 0;
    for (int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            ChessBox* box =game->all_pieces_[i][j];
            box->set_has_chess_piece(false);
            box->set_chess_piece_color("NONE");
            box->current_piece_ = nullptr;
            if (i < 2) {
                box->PlacePiece(blacks_[k]);
                blacks_[k]->set_is_placed(true);
                blacks_[k]->first_move_ = true;
                game->pieces_on_board_.append(blacks_[k++]);
            }
            if (i > 5) {
                box->PlacePiece(whites_[h]);
                whites_[h]->set_is_placed(true);
                whites_[h]->first_move_ = true;
                game->pieces_on_board_.append(whites_[h++]);
            }
        }
    }
}
