#pragma once

#include "VisibleGameObject.h"

class PlayerPaddle :
        public VisibleGameObject
{
public:
    PlayerPaddle();

    ~PlayerPaddle();

    void Update(float elapsedTime);

    void Draw(sf::RenderWindow &rw);

    float GetVelocity() const;

private:
    float _velocity = 0;
    const float acceleration = 800.0f;
    const float _maxVelocity = 900.0f;

    enum direction{
        left,
        right,
        none
    };
    direction currentDirection = none;
};