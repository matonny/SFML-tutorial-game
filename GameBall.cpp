#include "GameBall.h"
#include "Game.h"

GameBall::GameBall()
{
    Load("images/ball.png");
    assert(isLoaded());

    GetSprite().setOrigin(initialPosition.x, initialPosition.y);
}

GameBall::~GameBall()
{}

void GameBall::Update(float elapsedTime)
{
    sf::Vector2f pos = this->GetPosition();
    PlayerPaddle *player1 = dynamic_cast<PlayerPaddle *>(Game::_gameObjectManager.Get("Paddle1"));
    if (player1 != nullptr)
    {
        sf::Rect<float> p1BB = player1->GetSprite().getGlobalBounds();
        if (p1BB.intersects(this->GetSprite().getGlobalBounds()))
        {
            velocity.y = -velocity.y;
        }
    }

    if (pos.y < 0)
    {
        velocity.y = -velocity.y;
    }
    if ((pos.x < 0) || (pos.x > (Game::SCREEN_WIDTH)))
    {
        if (velocity.x > 0)
        {
            velocity.x = -velocity.x;
        } else if (velocity.x < 0)
        {
            velocity.x = -velocity.x;
        }
    }
    GetSprite().move(velocity * elapsedTime);
}