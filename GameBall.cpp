#include "GameBall.h"
GameBall::GameBall()
{
    Load("images/ball.png");
    assert(isLoaded());

    GetSprite().setOrigin(15,15);
}
GameBall::~GameBall()
{}