#include <iostream>
#include "Block.h"
#include "Level.h"

Block::Block(TileType type, const sf::Color &color, const sf::Vector2f &position) :
        tile{type, color, true, position} {}

Block::~Block() = default;


void Block::draw(Window &window) {
    tile.draw(window);
}

bool Block::move(MOVE_DIR direction) {
    sf::Vector2f newPos = getNewPos(direction);
    auto collidingObject = Level::getInstance().getCollidingObject(newPos);
    if(collidingObject) {
        if(collidingObject->move(direction)) {
            tile.setPosition(newPos);
            if(Level::getInstance().isBlockAtCorrectPlate(*collidingObject)) {
                std::cout << "plate at correct positon" << std::endl;
            }
            return true;
        }
        else{
            return false;
        }
    }
    if(!Level::getInstance().isCollisionWithTile(newPos)) {
        tile.setPosition(newPos);
        return true;
    }
}

sf::Vector2f Block::getNewPos(MOVE_DIR direction) {
    switch (direction) {
        case UP:
            return  {tile.getPosition().x,
                      tile.getPosition().y - TILE_SIZE};
        case DOWN:
            return  {tile.getPosition().x,
                      tile.getPosition().y + TILE_SIZE};
        case LEFT:
            return  {tile.getPosition().x - TILE_SIZE,
                      tile.getPosition().y};
        case RIGHT:
            return  {tile.getPosition().x + TILE_SIZE,
                      tile.getPosition().y};
    }
}
