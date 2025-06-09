#include "star.hpp"
#include <iostream>

std::vector<Star> Star::initializateStars(uint16_t contador) {
    static std::vector<Star> stars;
    stars.reserve(contador);

    // Create randomly distributed stars on the screen
    for (uint32_t i{contador}; i--;) {
        const float x = (randomBetweenZeroAndOne() - 0.5f) * config::windowSize.x;
        const float y = (randomBetweenZeroAndOne() - 0.5f) * config::windowSize.y;
        const float z = (randomBetweenZeroAndOne() * (config::zDepthMax - config::zDepthMin)) + config::zDepthMin;

        stars.push_back({{x, y}, z, (1.0f / z)});
    }
    return stars;
}

void Star::renderAndDrawStars(const std::vector<Star> &stars, sf::RenderWindow &window) {
    sf::CircleShape shape{config::starRadius};
    for (const Star &star: stars) {
        if (star.starDepth > config::zDepthMin) {
            const sf::Vector2f tempPosition = star.position * star.starScale + (config::windowSize_f * 0.5f);
            shape.setPosition(tempPosition);
            shape.setScale({star.starScale, star.starScale});
            window.draw(shape);
        }
    }
}

void Star::makeStarsTravel(std::vector<Star> &stars) {
    for (Star &star: stars) {
        star.starDepth = star.starDepth - (config::cameraSpeed * config::configDeltaTime);
        star.starScale = 1.0f / star.starDepth;
    }
}

void Star::setStarPosition(sf::Vector2f position) {
    this->position = position;
}
