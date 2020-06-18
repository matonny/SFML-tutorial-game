#include "GameBall.h"
#include "Game.h"
GameBall::GameBall()
{
    Load("images/ball.png");
    assert(isLoaded());

    GetSprite().setOrigin(initialPosition.x,initialPosition.y);
}
GameBall::~GameBall()
{}
void GameBall::Update(float elapsedTime)
{
    sf::Vector2f pos = this->GetPosition();
    if(pos.y > Game::SCREEN_HEIGHT){
        exit(0);
    }
    if((pos.x < 0) || (pos.x >(Game::SCREEN_WIDTH)))
    {
        if(velocity.x > 0){
            velocity.x = -velocity.x;
        }
        else if(velocity.x < 0){
            velocity.x = -velocity.x;
        }
    }
    GetSprite().move( velocity*elapsedTime);
}