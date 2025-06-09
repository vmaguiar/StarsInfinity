#include "star.hpp"
#include "utils.hpp"

std::vector<Star> Star::initializateStars(uint16_t contador, uint16_t screenX, uint16_t screenY) {
    static std::vector<Star> stars;
    stars.reserve(contador);

    // Create randomly distributed stars on the screen
    for (uint32_t i{contador}; i--;) {
        const float x = randomBetweenZeroAndOne() * screenX;
        const float y = randomBetweenZeroAndOne() * screenY;

        stars.push_back({{x, y}});
    }
    return stars;
}
