// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

#include <iostream>
#include "Grid.h"
#include "Fish.h"
#include "Shark.h"
#include <SFML/Graphics.hpp>
#include "Config.h"

/*! 
    \brief 

    This is the main file that runs the program. It creates the Grid Fish 
    and Shark Objects and preforms logic on them to place them in their correct position on each new chronon.

*/

using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1360, 560), "Wator Ecosystem Simulator");//1285, 560

    /*!< Create a single grid sprite object */
    Grid grid;
    /*!< Create a single fish sprite object */
    Fish fish;
    /*!< Create a single shark sprite object */
    Shark shark;    
    /*!< Creates the sprite for the grid */
    sf::Sprite GRID[GRID_ROWS][GRID_COLS];
    /*!< Makes rand() more random, only needs to be called once */
    srand (time (0));  

    /*! Fill FISH array wih -1's */
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
           fish.FISH[i][j]=-1;
        }
    }

    /*! Fill FISHMOVE array wih -1's */
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
           fish.FISHMOVE[i][j]=-1;
        }
    }

    /*! Enter fish notated by 1's at random locations into the FISH array */
    for (int i=0; i<nFish; i++){
        fish.putFishOnMapAtRandomLocations();
    }

    /*! Fill SHARKS array wih -1's */
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
           shark.SHARKS[i][j]=-1;
        }
    }

    /*! Fill SHARKSMOVE array wih -1's */
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
           shark.SHARKSMOVE[i][j]=-1;
        }
    }

    /*! Enter shark notated by 1's at random locations into the SHARKS array */
    for (int i=0; i<nSharks; i++){
        shark.putSharksOnMapAtRandomLocations();
    }

    /*!< Sets the FPS and the Speed (chronons) can be set in Config.h */
    sf::Time timePerFrame = sf::seconds(1.0f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    /*!< Creates the clock object */
    sf::Clock clock;
    clock.restart();

    int timeCounter=0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*!< Get the time since last update and restart the clock */
        timeSinceLastUpdate += clock.restart();

        /*! Update every chronon when on new chronon */
        if (timeSinceLastUpdate > timePerFrame)
        {
            window.clear();

            for (int i=0; i<GRID_ROWS; i++){
                for (int j=0; j<GRID_COLS; j++) {

		    /*! Sharks eat fish if on same location */
                    if(shark.SHARKS[i][j]!=-1 && fish.FISH[i][j]!=-1){  
                        fish.FISH[i][j]=-1;
                    }

                    fish.removeStarvedFish(i, j); 

                    /*! Fill GRID array with grid, shark and fish sprites */
                    if(fish.FISH[i][j]==-1){
                        GRID[i][j]=grid.getGridSprite();
                    }
                    if (shark.SHARKS[i][j]!=-1){
                        GRID[i][j]=shark.getSharkSprite();      
                    }
                    if (fish.FISH[i][j]!=-1){
                        GRID[i][j]=fish.getFishSprite();
                    }               

                    /*! Move Fish */
                    if(fish.FISH[i][j]!=-1 && fish.FISHMOVE[i][j]!=1){            
                        fish.FISH[i][j]=timeCounter;
                        fish.removeStarvedFish(i, j);  
                        fish.moveFish(fish.findMoveLocation(i,j), i, j, timeCounter);   
                    }

                    /*! Move Sharks */
                    if(shark.SHARKS[i][j]!=-1 && shark.SHARKSMOVE[i][j]!=1){            
                        shark.SHARKS[i][j]=timeCounter;
                        shark.moveShark(shark.findMoveLocation(i,j), i, j, timeCounter);   
                    }
                } 
            }
                    

            /*! Updates the grid after the fish and shark movements are made. */           
            for (int i=0; i<GRID_ROWS; i++){
                for (int j=0; j<GRID_COLS; j++) {

                    fish.removeStarvedFish(i, j); 

                    if(fish.FISH[i][j]==-1){
                        GRID[i][j]=grid.getGridSprite();
                    }
                    if (shark.SHARKS[i][j]!=-1){
                        GRID[i][j]=shark.getSharkSprite();      
                    }
                    if (fish.FISH[i][j]!=-1){
                        GRID[i][j]=fish.getFishSprite();
                    } 

                    /*!< Set position of sprite to make grid and darw */
                    GRID[i][j].setPosition(j * 40,i * 40);
                    window.draw(GRID[i][j]); 
                    fish.FISHMOVE[i][j]=-1;  
                    shark.SHARKSMOVE[i][j]=-1;  
                }
            }

            timeCounter++;

            window.display();

            /*!< Reset the timeSinceLastUpdate to 0 */
            timeSinceLastUpdate = sf::Time::Zero;

        }
    }
}
