#pragma once
#include <SFML/Graphics.hpp>

class Line : public sf::Drawable
{
public:
    float static lineThickness;
    float static distance;
    sf::RectangleShape shape;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

public:
    Line(float height);
    Line() = delete;
    ~Line() = default;

    float static getLineThickness();
    void updateLineColor(sf::Color color);
    float getLineHeight();
    float getLinePositionX();
    void setLineHeight(float height);

    void static swapLines(Line& L1, Line& L2);


};
