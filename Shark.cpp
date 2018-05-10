// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include "Shark.h"

/*! \class Shark
    \brief  

    This file contains of the methods used by the Shark objects.

*/

/*! Construstor for Shark object */
Shark::Shark(){
    /*! Throws an error if the image of the shark does not load */
    if (!sharkTexture.loadFromFile("images/shark.png"))
    {
       std::cout<<"Error loading shark.png";
    }
    
    sharkSprite.setTexture(sharkTexture);
    sharkSprite.setScale(1, 1);
}
/*! Gets shark sprite */
sf::Sprite Shark::getSharkSprite()
{
    return sharkSprite;   
}

/*! Puts a shark at a random point on the grid.
  Works recursively if location is already taken to find another */
void Shark::putSharksOnMapAtRandomLocations(){
    int randomRow = std::rand() % GRID_ROWS + 1;
    int randomCol = std::rand() % GRID_COLS + 1;
    if(SHARKS[randomRow][randomCol]!=1){
        SHARKS[randomRow][randomCol]=1;
    }else{
        putSharksOnMapAtRandomLocations();
    }
}

/*! Finds and returns a direction to fish by checking the grid points North, South, East, or West of the current location.
 If no fish is found in each direction relative to x,y the location is free so we can
 add that location to an array the holds the available move loctions (N,S,E,W) */
std::vector< char > Shark::findMoveLocation(int x, int y)
{
        /*!< Array of shark location */
	std::vector< char > arr;
        /*! If the shark is North */
	if (SHARKS[x-1][y]==-1 && x-1>0){
		arr.push_back('N');
	}
	/*! If the shark is South */
	if (SHARKS[x+1][y]==-1 && x+1<GRID_ROWS){
		arr.push_back('S');
	}
	/*! If the shark is East */
	if (SHARKS[x][y+1]==-1 && y+1<GRID_COLS){ 
		arr.push_back('E');
	}
	/*! If the shark is West */
	if (SHARKS[x][y-1]==-1 && y-1>0){ 
		arr.push_back('W');
	}

	return arr;
}


void Shark::moveShark(std::vector< char > possibleLocations, int x, int y, int timeCounter){

	if(possibleLocations.size()>1){
		char randomLocationFromPossible = possibleLocations[std::rand() % possibleLocations.size()];

		if(randomLocationFromPossible=='N'){
		  /*!< Remove shark from old location */
		  SHARKS[x][y]=-1;
		  /*!< Set shark north of old location */
		  SHARKS[x-1][y]=timeCounter;
		  /*!< Store sharks positions that have already been moved in this cycle/chronon */
	       	  SHARKSMOVE[x-1][y]=1;	        
		}
		else if(randomLocationFromPossible=='E'){
		  SHARKS[x][y]=-1;
		  SHARKS[x][y+1]=timeCounter; 
		  SHARKSMOVE[x][y+1]=1;
		}
		else if(randomLocationFromPossible=='S'){
		  SHARKS[x][y]=-1;
		  SHARKS[x+1][y]=timeCounter; 
		  SHARKSMOVE[x+1][y]=1;
		}
		else if(randomLocationFromPossible=='W'){
		  SHARKS[x][y]=-1;
		  SHARKS[x][y-1]=timeCounter; 
	       	  SHARKSMOVE[x][y-1]=1;
		}
	}
}
