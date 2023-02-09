#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>

class ChessBox : public QGraphicsRectItem {
public:
    ChessBox();
    ~ChessBox();

    void set_color(QColor color);

    //getters/setters
    int get_row() const;
    void set_row(int);
    int get_col() const;
    void set_col(int);
    bool get_has_chess_piece() const;
    void set_has_chess_piece(bool);
    QString get_chess_piece_color() const;
    void set_chess_piece_color(const QString&);


private:
    int row_;
    int col_;
    bool has_chess_piece_;
    QString chess_piece_color_;
    QColor color_;
};

#endif // CHESSBOX_H
