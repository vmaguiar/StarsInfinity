#pragma once
#include <cstdint>
#include <vector>
#include <SFML/System/Vector2.hpp>

struct Star {
    sf::Vector2f position;
    float zDepth = 1.0f;

    static std::vector<Star> initializateStars(uint16_t contador, uint16_t screenX, uint16_t screenY);
};
