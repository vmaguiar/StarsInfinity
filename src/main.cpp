#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configurationConsts.hpp"
#include "star.hpp"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(config::windowSize), "Stars Infinity");
    window.setFramerateLimit(config::maxFramerate);

    // Stars Creation
    std::vector<Star> stars = Star::initializateStars(config::starsCount, config::windowSize.x, config::windowSize.y);

    while (window.isOpen()) {
        processEvents(window);

        window.clear();
        // Render...
        sf::CircleShape shape{config::starRadius};
        for (Star const &star: stars) {
            shape.setPosition(star.position);
            window.draw(shape);
        }
        window.display();
    }
}
