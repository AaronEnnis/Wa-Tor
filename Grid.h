// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Grid 
{
private:
    /*!< Texture of the Grid */
    sf::Texture gridTexture;
    /*!< Sprite of the Grid */
    sf::Sprite gridSprite;

public:
    Grid();
    sf::Sprite getGridSprite();
};
