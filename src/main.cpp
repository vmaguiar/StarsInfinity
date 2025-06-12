#include <iostream>
#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configurationConsts.hpp"
#include "star.hpp"
#include "version.hpp"

int main() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(config::windowSize), "Stars Infinity", sf::State::Fullscreen);
    window.setFramerateLimit(config::maxFramerate);

    // Text Creation
    sf::Font versionFont;
    if (!versionFont.openFromFile("res/Roboto-Italic.ttf")) {
        std::cerr << "Failed to load Font" << std::endl;
    }
    const std::string versionString = "Version - " + StarsInfinity::getVersionString();
    sf::Text versionText = sf::Text(versionFont, versionString, 15);

    // Stars Creation
    sf::Texture starTexture;
    if (!starTexture.loadFromFile("res/star.png", true)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    starTexture.setSmooth(true);
    std::vector<Star> stars = Star::bootStars(config::starsCount);
    uint32_t indxOfFirst = 0;

    while (window.isOpen()) {
        processEvents(window);

        Star::makeStarsTravel(stars, indxOfFirst);

        window.clear();
        // Render...
        Star::renderAndDrawStars(stars, indxOfFirst, starTexture, window);
        window.draw(versionText);
        window.display();
    }
}
