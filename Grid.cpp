// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include "Grid.h"

/*! \class Grid
    \brief  

    This file contains of the methods used by the Grid objects.

*/

/*! Constructor for Grid object */
Grid::Grid(){

    /*! Throws an error if the image of the grid does not load */
    if (!gridTexture.loadFromFile("images/grid.png"))
    {
       std::cout<<"Error loading grid.png";
    }
    
    gridSprite.setTexture(gridTexture);
    gridSprite.setScale(1, 1);
}

sf::Sprite Grid::getGridSprite()
{
    return gridSprite;   
}
