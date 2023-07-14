//
// Created by Fernando on 26/06/2023.
//

#ifndef JUEGOC___CUADRADO_H
#define JUEGOC___CUADRADO_H
#include <SFML/Graphics.hpp>
template<typename T>
class Cuadrado {
private:
    sf::RectangleShape shape;
    sf::Vector2<T> position;
    sf::Vector2<T> size;

public:
    //Hacemos una comprobacion de que T es un tipo float

    Cuadrado(const sf::Vector2<T>& position, const sf::Vector2<T>& size,const sf::Color&color) {
        static_assert(std::is_floating_point_v<T>,"no son del mismo tipo");
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(color);
        this->position = position;
        this->size = size;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }

    sf::RectangleShape getShape() const {
        return shape;
    }

    bool checkCollision(const sf::FloatRect& bounds) const {
        return shape.getGlobalBounds().intersects(bounds);
    }
};
#endif //JUEGOC___CUADRADO_H
