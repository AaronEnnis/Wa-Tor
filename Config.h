// Authors: Aaron Ennis (C00190504) & Lorcan Bermingham (C00196903)
// Date: 10/05/17

/*! 
  \brief  

    This file contains all the shared configuration variable that can be modified. This file is included in every class.

*/

#ifndef CONFIG_H
#define CONFIG_H
/*!< Number of grid columns 34 */
#define GRID_COLS 34 
/*!< Number of grid rows 14 */
#define GRID_ROWS 14 
/*!< Number of sharks to spawn at launch */
#define nSharks 15
/*!< Number of fish to spawn at launch */
#define nFish 10
/*!< Number of time units that pass before a shark can reproduce */
#define sBreed 10
/*!< Number of time units that pass before a fish can reproduce */
#define fBreed 10
/*!< Period of time units a shark can go without food before dying */
#define starve 500
/*!< Number threads this progrm can create/use */
#define threads 1
/*!< Number of seconds per chronon (chronon = unit of time in this ecosystem) */
#define chronon 1    

#endif
