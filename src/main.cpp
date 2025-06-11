#include <iostream>
#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configurationConsts.hpp"
#include "star.hpp"

int main() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(config::windowSize), "Stars Infinity", sf::State::Fullscreen);
    window.setFramerateLimit(config::maxFramerate);

    // Stars Creation
    sf::Texture starTexture;
    if (!starTexture.loadFromFile("res/star.png", true)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    starTexture.setSmooth(true);
    std::vector<Star> stars = Star::initializateStars(config::starsCount);
    uint32_t indxOfFirst = 0;

    while (window.isOpen()) {
        processEvents(window);

        Star::makeStarsTravel(stars, indxOfFirst);

        window.clear();
        // Render...
        Star::renderAndDrawStars(stars, indxOfFirst, starTexture, window);
        window.display();
    }
}
