#include <iostream>
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameBall.h"

void Game::Start(void)
{
    if (_gameState != Uninitialized)
    {
        return;
    }
    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pang!");

    PlayerPaddle *player1 = new PlayerPaddle();
    player1->SetPosition((1024 / 2) - 45, 700);

    GameBall *ball = new GameBall();
    ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

    _gameObjectManager.Add("Paddle1", player1);
    _gameObjectManager.Add("Ball", ball);


    _gameState = Game::ShowingSplash;


    while (!IsExiting())
    {
        GameLoop();
    }

    _mainWindow.close();
}

bool Game::IsExiting()
{
    if (_gameState == Game::Exiting)
    {
        return true;
    } else
    {
        return false;
    }
}

void Game::GameLoop()
{
    while(true)
    {
        sf::Event currentEvent;
        while (_mainWindow.pollEvent(currentEvent))
        {
            if (currentEvent.type == sf::Event::KeyPressed)
            {
                _keyMap[currentEvent.key.code] = true;
            } else if (currentEvent.type == sf::Event::KeyReleased)
            {
                _keyMap.erase(currentEvent.key.code);
            }
        }
            switch (_gameState)
            {
                case Game::ShowingMenu:
                {
                    ShowMenu();
                    break;
                }
                case Game::ShowingSplash:
                {
                    ShowSplashScreen();
                    break;
                }
                case Game::Playing:
                {

                    _mainWindow.clear(sf::Color(0, 0, 0));

                    _gameObjectManager.UpdateAll();
                    _gameObjectManager.DrawAll(_mainWindow);
                    _mainWindow.display();

                    if (currentEvent.type == sf::Event::Closed)
                    {
                        _gameState = Game::Exiting;
                    }
                    break;
                }

            }
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
    switch (result)
    {
        case MainMenu::Exit:
            _gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            _gameState = Game::Playing;
            _gameObjectManager._gameClock.restart();
            break;
    }
}

std::map<sf::Keyboard::Key, bool> Game::getInput()
{
    return _keyMap;
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
std::map<sf::Keyboard::Key, bool> Game::_keyMap;