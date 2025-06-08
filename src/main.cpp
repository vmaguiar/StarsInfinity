#include <SFML/Graphics.hpp>


int main(){
    // Config Tela
    constexpr int SCREEN_WIDTH = 1920;
    constexpr int SCREEN_HEIGHT = 1080;
    constexpr int FPS = 60;

    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH,SCREEN_HEIGHT}), "SFML WORKS!!");
    window.setFramerateLimit(FPS);


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }


window.clear();
window.display();
    }
}