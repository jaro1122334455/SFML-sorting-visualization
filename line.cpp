#include "line.h"
#include <iostream>


float Line::lineThickness = 20;
float Line::distance = 0;

Line::Line(float height)
{
    //std::cout << "Konstruktor" << std::endl;
    // lineThickness = 10;

    shape.setSize({height, lineThickness});
    shape.setOutlineThickness(-0.5);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setRotation(90.f);
    shape.setPosition(distance += lineThickness, 500 - height);

}

/*Line::Line(const Line& L)
{
    //std::cout << "Konstruktor Kopiujący: " << std::endl;
    //std::cout << L.shape.getSize().x << " " << L.shape.getSize().y << std::endl;
    

    shape.setSize({L.shape.getSize().x, L.shape.getSize().y});
    shape.setOutlineThickness(L.shape.getOutlineThickness());
    shape.setOutlineColor(L.shape.getOutlineColor());

    //shape.setFillColor(sf::Color::Green);

    shape.setRotation(L.shape.getRotation());
    shape.setPosition(L.shape.getPosition().x, L.shape.getPosition().y);


    //std::cout << "s:" << shape.getSize().x << " " << shape.getSize().y << " " << shape.getOutlineThickness() << std::endl;
    //std::cout << "p: " << L.shape.getPosition().x << " " << L.shape.getPosition().y << std::endl;

}*/



void Line::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    target.draw(this->shape, state);
}

float Line::getLineThickness()
{
    return lineThickness;
}

void Line::updateLineColor(sf::Color color)
{
    this->shape.setFillColor(color);
}
 
float Line::getLinePositionX()
{
    return this->shape.getPosition().x;
}

float Line::getLineHeight()
{
    return this->shape.getSize().x;
}

void Line::setLineHeight(float height)
{
    this->shape.setSize({height, lineThickness});
    this->shape.setPosition(getLinePositionX(), 500 - height);
}

void Line::swapLines(Line& L1, Line& L2)
{
    float temp = L1.getLineHeight();

    L1.setLineHeight(L2.getLineHeight());
    L2.setLineHeight(temp);






}
