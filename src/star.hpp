#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "utils.hpp"
#include "configurationConsts.hpp"

struct Star {
    sf::Vector2f position;
    float starDepth = 1.0f;
    float starScale = 1.0f;
    float depthRatio = 1.0f;
    float colorRatio = 1.0f;
    uint8_t starColor = 255;

    static std::vector<Star> initializateStars(uint16_t contador);

    static void renderAndDrawStars(std::vector<Star> &stars, const uint32_t &indxOfFirst, const sf::Texture &texture,
                                   sf::RenderWindow &window);

    static void makeStarsTravel(std::vector<Star> &stars, uint32_t &indxOfFirst);

    static bool starFreeZoneChecker(float x, float y);

    void setStarColor();

    void setStarPosition(sf::Vector2f position);
};
