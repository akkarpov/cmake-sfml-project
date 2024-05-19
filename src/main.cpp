#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Circle");
    sf::Vector2f circlePosition(40, 40);
    float circleRadius = 40.f;
    float cellSize = 80.f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            circlePosition.x -= cellSize;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            circlePosition.x += cellSize;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            circlePosition.y -= cellSize;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            circlePosition.y += cellSize;
        }
        window.clear(sf::Color::White);
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(i * cellSize, j * cellSize);
                cell.setOutlineThickness(1.f);
                cell.setOutlineColor(sf::Color::Black);
                window.draw(cell);
            }
        }
        sf::CircleShape circle(circleRadius);
        circle.setFillColor(sf::Color::Yellow);
        circle.setOrigin(circleRadius, circleRadius);
        circle.setPosition(circlePosition);
        window.draw(circle);
        window.display();
    }
    return 0;
}