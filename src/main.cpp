#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configurationConsts.hpp"
#include "star.hpp"

int main() {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(config::windowSize), "Stars Infinity");
    window.setFramerateLimit(config::maxFramerate);

    // Stars Creation
    std::vector<Star> stars = Star::initializateStars(config::starsCount);

    while (window.isOpen()) {
        processEvents(window);

        Star::makeStarsTravel(stars);

        window.clear();
        // Render...
        Star::renderAndDrawStars(stars, window);
        window.display();
    }
}
