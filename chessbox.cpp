#include "chessbox.h"
#include "game.h"
#include "king.h"

extern Game* game;

ChessBox::ChessBox(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
    , current_piece_(nullptr)
{
    setRect(0,0,80,80);
    brush_.setStyle(Qt::SolidPattern);
    setZValue(-1);
    set_has_chess_piece(false);
    set_chess_piece_color("NONE");
}

ChessBox::~ChessBox() {
    delete current_piece_;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (current_piece_ == game->piece_to_move_ && current_piece_) {
        current_piece_->mousePressEvent(event);
        return;
    }
    if (game->piece_to_move_) {
        if (get_chess_piece_color() == game->piece_to_move_->get_team()) {
            return;
        }
        QList<ChessBox*> movLoc = game->piece_to_move_->get_possible_locations();
        int check = 0;
        for (qsizetype i = 0; i < movLoc.size(); ++i) {
            if (movLoc[i] == this) {
                ++check;
            }
        }
        if(check == 0) {
            return;
        }
        game->piece_to_move_->Decolor();
        game->piece_to_move_->first_move_ = false;
        if (get_has_chess_piece()) {
            current_piece_->set_is_placed(false);
            current_piece_->set_box(nullptr);
            game->PlaceInTakensHolder(current_piece_);
        }
        game->piece_to_move_->get_box()->set_has_chess_piece(false);
        game->piece_to_move_->get_box()->current_piece_ = nullptr;
        game->piece_to_move_->get_box()->ResetOriginalColor();
        PlacePiece(game->piece_to_move_);
        game->piece_to_move_ = nullptr;
        game->ChangeTurn();
        Check();
    }
    else if (get_has_chess_piece()) {
        current_piece_->mousePressEvent(event);
    }
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

void ChessBox::set_has_chess_piece(bool has_chess_piece, ChessPiece* piece) {
    has_chess_piece_ = has_chess_piece;
    if (has_chess_piece_) {
        set_chess_piece_color(piece->get_team());
    }
    else {
        set_chess_piece_color("NONE");
    }
}

QString ChessBox::get_chess_piece_color() const {
    return chess_piece_color_;
}

void ChessBox::set_chess_piece_color(const QString& chess_piece_color) {
    chess_piece_color_ = chess_piece_color;
}

void ChessBox::set_brush(const QColor& color) {
    brush_.setColor(color);
    setBrush(color);
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

void ChessBox::set_color(const QColor& color) {
    color_ = color;
    set_brush(color_);
}

void ChessBox::PlacePiece(ChessPiece* piece) {
    piece->setPos(x() + 40 - piece->pixmap().width() / 2, y() + 40 - piece->pixmap().width() / 2);
    piece->set_box(this);
    set_has_chess_piece(true, piece);
    current_piece_ = piece;
}

void ChessBox::Check() {
    int c = 0;
    QList<ChessPiece*> pList = game->pieces_on_board_;
    for (qsizetype i = 0; i < pList.size(); ++i) {
        King* p = dynamic_cast<King*>(pList[i]);
        if (p) {
            continue;
        }
        pList[i]->Move();
        pList[i]->Decolor();
        QList<ChessBox*> bList = pList[i]->get_possible_locations();
        for (qsizetype j = 0; j < bList.size(); ++j) {
            King* p = dynamic_cast<King*>(bList[j]->current_piece_);
            if (p) {
                if (p->get_team() == pList[i]->get_team()) {
                    continue;
                }
                bList[j]->set_brush(Qt::blue);
                pList[i]->get_box()->set_brush(Qt::darkRed);
                if (!game->check_->isVisible()) {
                    game->check_->setVisible(true);
                }
                else {
                    bList[j]->ResetOriginalColor();
                    pList[i]->get_box()->ResetOriginalColor();
                    game->GameOver();
                }
                ++c;
            }
        }
    }
    if (!c) {
        game->check_->setVisible(false);
        for (qsizetype i = 0; i < pList.size(); ++i) {
            pList[i]->get_box()->ResetOriginalColor();
        }
    }
}

void ChessBox::ResetOriginalColor() {
    set_brush(color_);
}
