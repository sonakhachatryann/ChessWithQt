#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "chessboard.h"
#include "king.h"
#include "button.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"

class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget* parent = nullptr);
    void DrawTakensHolder(int, int, const QColor&);
    void DrawChessBoard();
    void DisplayWhiteTakens();
    void DisplayBlackTakens();
    void PlaceInTakensHolder(ChessPiece*);
    void ChangeTurn();

    QString get_turn();
    void set_turn(const QString&);

    void DisplayMenu();
    void GameOver();
    void RemoveAll();
    void set_scene(QGraphicsScene*);
    QGraphicsScene* get_scene() const;
    void AddToScene(QGraphicsItem*);

public:
    ChessBox* all_pieces_[8][8];
    QList<ChessPiece*> pieces_on_board_;
    QGraphicsTextItem* check_;
    ChessPiece* piece_to_move_;

public slots:
    void start();

private:
    QGraphicsScene* scene_;
    ChessBoard* board_;
    QString turn_;
    QGraphicsRectItem* takens_holder_;
    QList<ChessPiece*> white_takens_;
    QList<ChessPiece*> black_takens_;
    QGraphicsTextItem* display_the_turn_;
    QList <QGraphicsItem*> graphics_list_;
};

#endif // GAME_H
