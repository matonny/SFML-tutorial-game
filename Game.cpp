//
// Created by Mateusz Wygonny on 14/06/2020.
//

#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

void Game::Start(void)
{
    if (_gameState != Uninitialized)
    {
        return;
    }
    _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");

    _player1.Load("images/paddle.png");
    _player1.SetPosition(1024 / 2 - 45, 700);

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
    sf::Event currentEvent;
    while (_mainWindow.pollEvent(currentEvent))
    {
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
                _mainWindow.clear(sf::Color(255, 0, 0));
                _player1.Draw(_mainWindow);
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
            break;
    }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
PlayerPaddle Game::_player1;