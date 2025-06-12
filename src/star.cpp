#include "star.hpp"
#include <algorithm>
// #include <iostream>

std::vector<Star> Star::bootStars(uint16_t contador) {
    static std::vector<Star> stars;
    stars.reserve(contador);

    // Create randomly distributed stars on the screen
    for (uint32_t i{contador}; i--;) {
        const float x = (randomBetweenZeroAndOne() - 0.5f) * config::windowSize.x * config::zDepthMax;
        const float y = (randomBetweenZeroAndOne() - 0.5f) * config::windowSize.y * config::zDepthMax;
        const float z = (randomBetweenZeroAndOne() * (config::zDepthMax - config::zDepthMin)) + config::zDepthMin;

        if (starFreeZoneChecker(x, y)) {
            i++;
            continue;
        }

        stars.push_back({{x, y}, z, (1.0f / z)});
    }
    // Sort by depth
    std::sort(stars.begin(), stars.end(), [](const Star &starA, const Star &starB) {
        return starA.starDepth > starB.starDepth;
    });
    return stars;
}

void Star::renderAndDrawStars(std::vector<Star> &stars, const uint32_t &indxOfFirst, const sf::Texture &texture,
                              sf::RenderWindow &window) {
    sf::CircleShape shape{config::starRadius};
    shape.setOrigin({config::starRadius, config::starRadius});

    sf::Sprite starSprite(texture);
    starSprite.setOrigin({static_cast<float>(texture.getSize().x) * 0.5f, static_cast<float>(texture.getSize().y) * 0.5f});

    for (uint32_t i = 0; i < config::starsCount; i++) {
        uint32_t idx = (i + indxOfFirst) % config::starsCount;
        Star &star = stars[idx];

        if (star.starDepth > config::zDepthMin) {
            starSprite.setTexture(texture);
            starSprite.setPosition(star.position * star.starScale + (config::windowSize_f * 0.5f));
            starSprite.setScale({star.starScale, star.starScale});
            star.setStarColor();
            starSprite.setColor({star.starColor, star.starColor, star.starColor});
            window.draw(starSprite);
        }
    }
}

void Star::makeStarsTravel(std::vector<Star> &stars, uint32_t &indxOfFirst) {
    for (uint32_t i = config::starsCount; i--;) {
        Star &star = stars[i];
        star.starDepth = star.starDepth - (config::cameraSpeed * config::configDeltaTime);
        star.starScale = 1.0f / star.starDepth;

        if (star.starDepth < config::zDepthMin) {
            star.starDepth = config::zDepthMax - (config::zDepthMin - star.starDepth);
            indxOfFirst = i;
        }
    }
}

bool Star::starFreeZoneChecker(float x, float y) {
    sf::Vector2f windowScaled = config::windowSize_f * config::zDepthMin;
    sf::FloatRect starFreeZone = {-windowScaled * 0.5f, windowScaled};

    return starFreeZone.contains({x, y});
}


void Star::setStarColor() {
    this->depthRatio = (this->starDepth - config::zDepthMin) / (config::zDepthMax - config::zDepthMin);
    this->colorRatio = 1.0f - this->depthRatio;
    this->starColor = static_cast<uint8_t>(this->colorRatio * 255.0f);
}

void Star::setStarPosition(sf::Vector2f position) {
    this->position = position;
}
