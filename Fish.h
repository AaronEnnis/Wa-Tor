// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h"

using namespace std;

class Fish 
{
private:
    /*!< Texture of the Sharks */
    sf::Texture fishTexture;
    /*!< Sprite of the Sharks */
    sf::Sprite fishSprite;

public:
    Fish();
    /*!< Location/Age of Fish*/
    int FISH[GRID_ROWS][GRID_COLS];
    /*!< Movement of the Fish*/
    int FISHMOVE[GRID_ROWS][GRID_COLS];
    sf::Sprite getFishSprite();
    std::vector< char > findMoveLocation(int x, int y);
    void moveFish(std::vector< char > possibleLocations, int x, int y, int timeCounter);
    void removeStarvedFish(int x, int y);
    void putFishOnMapAtRandomLocations();
};

