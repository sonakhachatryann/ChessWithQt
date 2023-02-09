#include "game.h"

#include <QGraphicsScene>

Game::Game()
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}
