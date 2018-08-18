//
// Created by Lyosha12 on 18.06.2018.
//

#include "Utility/WindowForTests/WindowForTests.hpp"
#include "DefaultRectangle.hpp"

DefaultRectangle::DefaultRectangle(float cell_width, float cell_height)
    : prototype({cell_width, cell_height})
{ }

sf::Sprite DefaultRectangle::
makeSprite(sf::Texture const& texture, Coord on_field, double rotation) const {
    sf::Sprite sprite(texture);

    // Узнаем коэффициенты масштабов спрайта, чтобы он влез в прямоугольник.
    sf::Vector2f scale = {
        prototype.getSize().x / texture.getSize().x,
        prototype.getSize().y / texture.getSize().y
    };
    sprite.setScale(scale);
    
    // Повернём относительно центра.
    sf::Vector2f origin = {
        sprite.getTextureRect().width / 2.0f,
        sprite.getTextureRect().height / 2.0f
    };
    sprite.setOrigin(origin);
    // Т.к. угол поворота получен как против часовой стрелки,
    // а функция вращения работает по часовой - инвертируем.
    sprite.rotate(static_cast<float>(-rotation));
    
    // Установим нужную позицию на поле для спрайта.
    float width  = prototype.getSize().x;
    float height = prototype.getSize().y;
    sprite.setPosition(width * on_field.x + origin.x + width/2 - width/5, height * on_field.y + origin.y + height/2 - height/5);
    
    return sprite;
}

sf::Vector2f DefaultRectangle::getSize() const {
    return prototype.getSize();
}


