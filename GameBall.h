#pragma once
#include "VisibleGameObject.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class GameBall:
        public VisibleGameObject
{
public:
    GameBall();
    virtual ~GameBall();
    void Update(float elapsedTime);

private:
    sf::Vector2<float> velocity{400.0,100.0};
    sf::Vector2<int> initialPosition{15, 15};
};