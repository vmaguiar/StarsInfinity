#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "utils.hpp"
#include "configurationConsts.hpp"

struct Star {
    sf::Vector2f position;
    float starDepth = 1.0f;
    float starScale = 1.0f;

    static std::vector<Star> initializateStars(uint16_t contador);

    static void renderAndDrawStars(const std::vector<Star> &stars, sf::RenderWindow &window);

    static void makeStarsTravel(std::vector<Star> &stars);

    void setStarPosition(sf::Vector2f position);
};
