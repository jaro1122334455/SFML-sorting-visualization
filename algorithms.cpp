#include "algorithms.h"
#include <iostream>

//using namespace algorithms;

int limit = setup::W/Line::getLineThickness();

int i = 0;
int j = 0;

sf::Clock clk;
float time_interval;

 


bool algorithms::ascendingCompare(float a, float b)                                         //funkcje porównujące dwie liczby (do wykorzystania np. w if)
{
    return a < b;
}

bool algorithms::descendingCompare(float a, float b)
{
    return a > b;
}


void algorithms::bubbleSort(std::vector<Line>& lines, bool(*compareFuncPtr)(float, float))
{
    // std::cout << limit << std::endl;
    bool swapped = false;

    time_interval = clk.getElapsedTime().asSeconds();

    if(i < limit)
    {

        if (time_interval >= 0.5) // checking if time is more than 3 seconds
        {
            for(int j = 0; j < limit; j++)
            {

                std::cout << "j: " << j << std::endl;
                

                    if(compareFuncPtr(lines.at(j).getLineHeight(), lines.at(j + 1).getLineHeight()))
                    {

                            std::cout << "TEST DELAY" << std::endl;
                            Line::swapLines(lines.at(j), lines.at(j + 1));

                            clk.restart();


                    }


            }
        }

        std::cout << "TEST I: " << i << std::endl;

        // i++;

    }
    else
    {
        std::cout << "Finish" << std::endl;
    }

    // i++;

}

void algorithms::bubbleSort_2(std::vector<Line>& lines)
{
    bool swapped = false;
    time_interval = clk.getElapsedTime().asSeconds();
    // for(int i = 0; i < lines.size() - 1; i++)
    // {
        // for(int j = 0; j < lines.size() - 1; j++)
        // {



        // }
    // }

    if(i < lines.size() - 1)
    {
        Line& a = lines.at(j);
        Line& b = lines.at(j + 1);


        a.updateLineColor(sf::Color::Green);

        if(a.getLineHeight() > b.getLineHeight())
        {
            // if(time_interval >= 2.5)
            // {
                Line::swapLines(a, b);
                swapped = true;
                clk.restart();

            // }
        }

        if(swapped == false)
        {
            a.updateLineColor(sf::Color::White);
        }
        
        j++;

        if(j >= lines.size() - 2 - i)
        {
            j = 0;
            i++;
        }
    }
    else
    {
        std::cout << "Finish" << std::endl;
    }

    // std::cout << "i = " << i << " limit = " << limit << std::endl;

    // time_interval = clk.getElapsedTime().asSeconds();

    // if(i < limit)
    // {


    //     for(int j = 0; j < limit; j++)
    //     {

    //         // Line& a = lines.at(j);
    //         // Line& b = lines.at(j + 1);

    //         // std::cout << i << " - " <<  j << std::endl;

    //         // std::cout << time_interval << std::endl;


    //         if(lines.at(j).getLineHeight() > lines.at(j + 1).getLineHeight())
    //         {

    //             if (time_interval >= 5.0) // checking if time is more than 3 seconds
    //             {
    //                 lines.at(j).updateLineColor(sf::Color::Green);
    //                 // std::cout << i << " - minelo 0.5 s" << std::endl;
    //                 std::cout << "swap" << std::endl;
    //                 Line::swapLines(lines.at(j), lines.at(j + 1));
    //                 clk.restart();
    //             }

    //             lines.at(j).updateLineColor(sf::Color::White);

    //         }

    //     }

    //     // i++;

    // }
    // else
    // {
    //     std::cout << "Finish" << std::endl;
    //     // return;
    // }

    



    // std::cout << lines.size() << std::endl;
}
