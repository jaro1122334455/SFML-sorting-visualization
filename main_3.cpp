#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sortowanie w SFML");

    // Inicjalizacja wektora z liczbami do posortowania
    std::vector<int> numbers;
    for (int i = 0; i < 100; ++i) {
        numbers.push_back(rand() % 600 + 1); // Losowe liczby z zakresu 1-600
    }

    // Ustawienia do rysowania linii
    sf::VertexArray lines(sf::LinesStrip, numbers.size());
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        lines[i].position = sf::Vector2f(i * 8, 600 - numbers[i]);
        lines[i].color = sf::Color::White;
    }

    bool isSorting = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (isSorting) {
            // Sortowanie bąbelkowe - jedna iteracja
            for (std::size_t i = 0; i < numbers.size() - 1; ++i) {
                for (std::size_t j = 0; j < numbers.size() - i - 1; ++j) {
                    if (numbers[j] > numbers[j + 1]) {
                        std::swap(numbers[j], numbers[j + 1]);
                    }
                }
            }

            // Aktualizacja położenia linii na ekranie
            for (std::size_t i = 0; i < numbers.size(); ++i) {
                lines[i].position.y = 600 - numbers[i];
            }

            window.clear();
            window.draw(lines);
            window.display();

            // Opóźnienie między iteracjami
            sf::sleep(sf::milliseconds(100));
        }

        // Sprawdź, czy sortowanie zostało zakończone
        isSorting = !std::is_sorted(numbers.begin(), numbers.end());
    }

    return 0;
}
