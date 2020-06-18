//
// Created by Mateusz Wygonny on 14/06/2020.
//

#include <iostream>
#include "PlayerPaddle.h"
#include "Game.h"
#include <cmath>
#include <cfloat>

bool close_enough(float a, float b){
    return fabs(a - b) <= std::numeric_limits<float>::epsilon() * std::max(std::abs(a), std::abs(b));
}

PlayerPaddle::PlayerPaddle() :
_velocity(0),
_maxVelocity(600.0f)
{
    Load("images/paddle.png");
    assert(isLoaded());

    GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
}

PlayerPaddle::~PlayerPaddle()
{
}
void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
    VisibleGameObject::Draw(rw);
}
float PlayerPaddle::GetVelocity() const
{
    return _velocity;

}
void PlayerPaddle::Update(float elapsedTime)
{

    std::map<sf::Keyboard::Key, bool> _keyMap = Game::getInput();
    {

        if (_keyMap.count(sf::Keyboard::Left) == 1)
        {
            currentDirection = left;
        }
        if (_keyMap.count(sf::Keyboard::Right) == 1)
        {
            currentDirection = right;
        }
        if (_keyMap.count(sf::Keyboard::Down) == 1 || _keyMap.count(sf::Keyboard::Right) == _keyMap.count(sf::Keyboard::Left))
        {
            currentDirection = none;
        }
        switch (currentDirection)
        {
            case left:
                _velocity -= acceleration*elapsedTime;
                break;
            case right:
                _velocity += acceleration*elapsedTime;
                break;
            case none:
                if(!close_enough(_velocity, 0.0f))
                {
                    _velocity -= std::copysign(3*acceleration, _velocity) * elapsedTime;
                    std::cout << _velocity << " " << elapsedTime << std::endl;
                }
                break;
        }
    }
    if(_velocity > _maxVelocity)
    {
        _velocity = _maxVelocity;
    }
    if(_velocity < -_maxVelocity)
    {
        _velocity = -_maxVelocity;
    }
    sf::Vector2f pos = this->GetPosition();

    if(pos.x < GetSprite().getGlobalBounds().width/2 || pos.x >(Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2))
    {
        _velocity = 0.99f*-_velocity;
    }

    GetSprite().move(_velocity * elapsedTime, 0);
}
