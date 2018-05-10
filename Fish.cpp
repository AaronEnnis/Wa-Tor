// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include "Fish.h"
#include <iostream>

/*! \class Fish
    \brief  

    This file contains of the methods used by the Fish objects.

*/

/*! Constructor for Fish object */
Fish::Fish(){
    /*! Throws an error if the image of the fish does not load */
    if (!fishTexture.loadFromFile("images/fish.png"))
    {
       std::cout<<"Error loading fish.png";
    }
    
    fishSprite.setTexture(fishTexture);
    fishSprite.setScale(1, 1);
}

sf::Sprite Fish::getFishSprite()
{
    return fishSprite;   
}
	
/*! Takes in the position of the current location x,y  of the fish object.
 It then checks North, South, East, and West to see if the grid location is free. */
std::vector< char > Fish::findMoveLocation(int x, int y)
{
	std::vector< char > arr;
	/*!< If North */
	if (FISH[x-1][y]==-1 && x-1>0){ 
		arr.push_back('N');
	}
	/*!< If South */
	if (FISH[x+1][y]==-1 && x+1<GRID_ROWS){ 
		arr.push_back('S');
	}
	/*!< If East */
	if (FISH[x][y+1]==-1 && y+1<GRID_COLS){
		arr.push_back('E');
	}
	/*!< If West */
	if (FISH[x][y-1]==-1 && y-1>0){
		arr.push_back('W');
	}

	return arr;
}


void Fish::moveFish(std::vector< char > possibleLocations, int x, int y, int timeCounter){

	if(possibleLocations.size()>1){
		char randomLocationFromPossible = possibleLocations[std::rand() % possibleLocations.size()];

		if(randomLocationFromPossible=='N'){
		  /*!< Remove fish from old location */
		  FISH[x][y]=-1;
		  /*!< Set fish north of old location */
		  FISH[x-1][y]=timeCounter;
		  /*!< Store fish positions that have already been moved in this cycle/chronon */
		  FISHMOVE[x-1][y]=1;	
		}
		else if(randomLocationFromPossible=='E'){
			FISH[x][y]=-1;
			FISH[x][y+1]=timeCounter; 
			FISHMOVE[x][y+1]=1;
		}
		else if(randomLocationFromPossible=='S'){
			FISH[x][y]=-1;
			FISH[x+1][y]=timeCounter; 
			FISHMOVE[x+1][y]=1;
		}
		else if(randomLocationFromPossible=='W'){
			FISH[x][y]=-1;
			FISH[x][y-1]=timeCounter; 
			FISHMOVE[x][y-1]=1;
		}
	}
}
/*! Removes starved fish from the grid */
void Fish::removeStarvedFish(int x, int y){
	if(FISH[x][y]>starve){
		FISH[x][y]=-1;
	}
}
/*! Puts a fish at a random point on the grid.
 Works recursively if location is already taken to find another */
void Fish::putFishOnMapAtRandomLocations(){
    int randomRow = std::rand() % GRID_ROWS + 1;
    int randomCol = std::rand() % GRID_COLS + 1;
    if(FISH[randomRow][randomCol]!=1){
        FISH[randomRow][randomCol]=1;
    }else{
        putFishOnMapAtRandomLocations();
		cout << "rerand";
    }
}
