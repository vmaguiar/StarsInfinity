#pragma once
#include <SFML/Graphics.hpp>

namespace config {
    // Window Config
    constexpr sf::Vector2u windowSize = {1920u, 1080u};
    constexpr sf::Vector2f windowSize_f = static_cast<sf::Vector2f>(windowSize);
    constexpr uint8_t maxFramerate = 60;
    constexpr float configDeltaTime = 1.0f / static_cast<float>(maxFramerate);

    // Star Config
    constexpr uint32_t starsCount = 10000;
    constexpr float starRadius = 20.0f;
    constexpr float zDepthMax = 20.0f;
    constexpr float zDepthMin = 0.1f;

    // Camera Config
    constexpr float cameraSpeed = 0.5f; //max: 20 min: 0.1
}
