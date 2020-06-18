#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"


class Game
{

public:
    static void Start();
    static std::map<sf::Keyboard::Key, bool> getInput();
    static sf::RenderWindow& GetWindow();
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;
    static GameObjectManager _gameObjectManager;


private:
    static bool IsExiting();
    static void GameLoop();

    static void ShowSplashScreen();
    static void ShowMenu();

    const float FPS = 60.0f;

    enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;

    static std::map<sf::Keyboard::Key, bool> _keyMap;
};
