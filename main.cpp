#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "config.hpp"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Lorenz's attractor", sf::Style::Fullscreen, settings);

    float x = 0.01;
    float y = 0;
    float z = 0;

    float count = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        count += 0.0005;
        for (int i = 0; i < SIMULTANEOUS_MOVEMENTS; i++) {

            float dx((A * (y - x)) * DT);
            float dy((x * (B - z) - y) * DT);
            float dz((x * y - C * z) * DT);

            x += dx;
            y += dy;
            z += dz;

            sf::CircleShape point(POINT_WIDTH);
            point.setFillColor(sf::Color (abs(sin(2 * PI * count * F1) * 255),
                                          abs(cos(2 * PI * count * F2) * 255),
                                          abs(sin(2 * PI * count * F3) * 255)));
            point.setPosition(INIT_X + (x * SCALE_X), INIT_Y + (y * SCALE_Y));

            window.draw(point);
        }

        window.display();
    }

    return 0;
}