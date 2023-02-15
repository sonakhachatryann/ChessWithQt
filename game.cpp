#include "game.h"
#include "button.h"
#include <QPixmap>
#include "king.h"

Game::Game(QWidget* parent)
    : QGraphicsView(parent)
    , piece_to_move_(nullptr)
{
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0, 0, 1300, 700);
    setFixedSize(1300,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene_);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    display_the_turn_ = new QGraphicsTextItem();
    display_the_turn_->setPos(width() / 2 - 100, 5);
    display_the_turn_->setZValue(1);
    display_the_turn_->setDefaultTextColor(Qt::white);
    display_the_turn_->setFont(QFont("Times New Roman", 18));
    display_the_turn_->setPlainText("Turn : WHITE");

    check_ = new QGraphicsTextItem();
    check_->setPos(width() / 2 - 80, 670);
    check_->setZValue(4);
    check_->setDefaultTextColor(Qt::red);
    check_->setFont(QFont("Times New Roman", 18));
    check_->setPlainText("CHECK!");
    check_->setVisible(false);

    set_turn("WHITE");
}

void Game::DrawTakensHolder(int x, int y, const QColor& color) {
    takens_holder_ = new QGraphicsRectItem(x, y, 330, 700);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    takens_holder_->setBrush(brush);
    AddToScene(takens_holder_);
}

void Game::DrawChessBoard() {
    board_ = new ChessBoard();
    DrawTakensHolder(0, 0, Qt::gray);
    DrawTakensHolder(970, 0, Qt::darkGray);
    board_->DrawChessBoxes();
}

void Game::DisplayWhiteTakens() {
    int SHIFT = 80;
    int j = 0;
    int k = 0;
    for (qsizetype i = 0; i < white_takens_.size(); ++i) {
        if (j == 4) {
            ++k;
            j = 0;
        }
        white_takens_[i]->setPos(20 + SHIFT * j++, 80 + SHIFT * 2 * k);
    }
}

void Game::DisplayBlackTakens() {
    int SHIFT = 80;
    int j = 0;
    int k = 0;
    for (qsizetype i = 0; i < black_takens_.size(); ++i) {
        if (j == 4) {
            ++k;
            j = 0;
        }
        black_takens_[i]->setPos(990 + SHIFT * j++, 80 + SHIFT * 2 * k);
    }
}

void Game::PlaceInTakensHolder(ChessPiece* piece) {
    if(piece->get_team() == "WHITE") {
        white_takens_.append(piece);
        King* g = dynamic_cast<King*>(piece);
        if (g) {
            check_->setPlainText("Black Won");
            GameOver();
        }
        DisplayWhiteTakens();
    }
    else {
        black_takens_.append(piece);
        King* g = dynamic_cast<King*>(piece);
        if (g) {
            check_->setPlainText("White Won");
            GameOver();
        }
        DisplayBlackTakens();
    }
    pieces_on_board_.removeAll(piece);
}

void Game::ChangeTurn() {
    if (get_turn() == "WHITE") {
        set_turn("BLACK");
    }
    else {
        set_turn("WHITE");
    }
    display_the_turn_->setPlainText("Turn : " + get_turn());
}

QString Game::get_turn() {
    return turn_;
}

void Game::set_turn(const QString& turn) {
    turn_ = turn;
}

void Game::DisplayMenu() {
    Button* play_button = new Button("PLAY");
    int b_x_pos = width() / 2 - play_button->boundingRect().width() / 2;
    int b_y_pos= 300;
    play_button->setPos(b_x_pos, b_y_pos);
    connect(play_button, SIGNAL(clicked()), this, SLOT(start()));
    AddToScene(play_button);
    graphics_list_.append(play_button);
    Button* quit_button = new Button("QUIT");
    int q_x_pos = width() / 2 - quit_button->boundingRect().width() / 2;
    int q_y_pos = 375;
    quit_button->setPos(q_x_pos, q_y_pos);
    connect(quit_button, SIGNAL(clicked()), this, SLOT(close()));
    AddToScene(quit_button);
    DrawChessBoard();
    graphics_list_.append(quit_button);
}

void Game::GameOver() {
    set_turn("WHITE");
    pieces_on_board_.clear();
    board_->Reset();
}

void Game::RemoveAll() {
    QList<QGraphicsItem*> items_list = scene_->items();
    for (qsizetype i = 0; i < items_list.size(); ++i) {
        if (items_list[i] != check_) {
            scene_->removeItem((items_list[i]));
        }
    }
}

void Game::set_scene(QGraphicsScene* scene) {
    scene_ = scene;
}

QGraphicsScene* Game::get_scene() const {
    return scene_;
}

void Game::start() {
    for (qsizetype i = 0; i < graphics_list_.size(); ++i) {
        scene_->removeItem(graphics_list_[i]);
    }
    AddToScene(display_the_turn_);
    QGraphicsTextItem* white_piece = new QGraphicsTextItem();
    white_piece->setPos(70, 10);
    white_piece->setZValue(1);
    white_piece->setDefaultTextColor(Qt::white);
    white_piece->setFont(QFont("Times new roman", 16));
    white_piece->setPlainText("WHITE PIECES");
    AddToScene(white_piece);

    QGraphicsTextItem* black_piece = new QGraphicsTextItem();
    black_piece->setPos(1070,10);
    black_piece->setZValue(1);
    black_piece->setDefaultTextColor(Qt::black);
    black_piece->setFont(QFont("Times New Roman", 16));
    black_piece->setPlainText("BLACK PIECES");
    AddToScene(black_piece);
    AddToScene(check_);
    board_->AddPiece();
}

void Game::AddToScene(QGraphicsItem* item) {
    scene_->addItem(item);
}
