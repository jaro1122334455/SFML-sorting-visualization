#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <list>
#include <vector>
#include "setup.h"
#include "line.h"
#include "algorithms.h"
#include <unistd.h>


float limit_2 = setup::W/Line::getLineThickness();


float iter_2 = 0;


int main()
{
    srand (time(NULL));
    
    sf::RenderWindow window(sf::VideoMode(setup::W, setup::H), "SFML works!");

    window.setFramerateLimit(setup::frameRate);

    std::vector<Line> lines;

    for(int i = 0; i <= setup::W/Line::getLineThickness(); i++)
    {
        lines.emplace_back(Line(rand() % int(setup::H) + 1));
    }



    


    while(window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
            {
                // clk.restart();
            }
        }
        window.clear();


        // sleep(0.9f);

        // sleep(1);
        // std::cout << time_interval << std::endl;


        algorithms::bubbleSort(lines, algorithms::descendingCompare);

        // algorithms::bubbleSort_2(lines);

        




        for(auto& line : lines)
        {
            window.draw(line);
        }

        // std::cout << "TEST koniec" << std::endl;
        
        window.display();
    }

    

}