// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h"

using namespace std;

class Shark 
{
private:
    /*!< Texture of the Sharks */
    sf::Texture sharkTexture;
    /*!< Sprite of the Sharks */
    sf::Sprite sharkSprite;

public:
    Shark();
    sf::Sprite getSharkSprite();
    /*!< Location/Age of Sharks */
    int SHARKS[GRID_ROWS][GRID_COLS];
    /*!< Movement of the Sharks */
    int SHARKSMOVE[GRID_ROWS][GRID_COLS];
    /*!< hunger of shark for calculating starvation */
    int hunger;
    int sharkStarve;
    void randomLocation();
    std::vector< char > moveLocations(int x, int y);
    void moveShark(std::vector< char > openLocations, int x, int y, int timer);
    bool removeShark();
};
