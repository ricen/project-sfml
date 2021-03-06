#include <SFML/Window/Event.hpp>
#include "MainMenuState.h"
#include "PlayState.h"
#include "TextManager.h"

void MainMenuState::handleInput(Game &game) {
    sf::Event event{};
    while (game.getWindow().pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    game.getWindow().close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    game.changeState(std::make_shared<PlayState>());
                }
                break;

            default:
                break;
        }
    }
}

MainMenuState::MainMenuState() = default;

MainMenuState::~MainMenuState() = default;

void MainMenuState::init() {}

void MainMenuState::draw(Game &game) {
    TextManager::drawAtCenter("Press 'SPACE' to start", game.getWindow(), 32);
    TextManager::draw("Press 'ESC' to quit", game.getWindow(),
                      {game.getWindow().getSize().x / 2 - 130, game.getWindow().getSize().y / 2 + 40}, 32);
}
