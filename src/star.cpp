#include "star.hpp"

#include <algorithm>
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
    // Sort by depth
    std::sort(stars.begin(), stars.end(), [](const Star &starA, const Star &starB) {
        return starA.starDepth > starB.starDepth;
    });
    return stars;
}

void Star::renderAndDrawStars(std::vector<Star> &stars, sf::RenderWindow &window) {
    sf::CircleShape shape{config::starRadius};
    for (Star &star: stars) {
        if (star.starDepth > config::zDepthMin) {
            shape.setPosition(star.position * star.starScale + (config::windowSize_f * 0.5f));
            shape.setScale({star.starScale, star.starScale});
            star.setStarColor();
            shape.setFillColor({star.starColor, star.starColor, star.starColor});
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

void Star::setStarColor() {
    this->depthRatio = (this->starDepth - config::zDepthMin) / (config::zDepthMax - config::zDepthMin);
    this->colorRatio = 1.0f - this->depthRatio;
    this->starColor = static_cast<uint8_t>(this->colorRatio * 255.0f);
}

void Star::setStarPosition(sf::Vector2f position) {
    this->position = position;
}
