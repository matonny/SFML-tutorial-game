#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
    _isLoaded = false;
}

VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
    if (!_image.loadFromFile(filename))
    {
        _filename = "";
        _isLoaded = false;
    }
    else
    {
        _filename = filename;
        _sprite.setTexture(_image);
        _isLoaded = true;
    }
}

void VisibleGameObject::Update(float elapsedTime)
{

}
void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
    if(_isLoaded)
    {
        renderWindow.draw(_sprite);
    }
}

void VisibleGameObject::SetPosition(float x, float y)
{
    if(_isLoaded)
    {
        _sprite.setPosition(x,y);
    }
}
sf::Vector2f VisibleGameObject::GetPosition() const
{
    if(_isLoaded)
    {
        return _sprite.getPosition();
    }
    return sf::Vector2f();
}
sf::Sprite& VisibleGameObject::GetSprite()
{
    return _sprite;
}
bool VisibleGameObject::isLoaded() const
{
    return _isLoaded;
}