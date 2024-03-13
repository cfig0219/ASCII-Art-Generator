#include <iostream>
#include <random>

const int WIDTH = 80;
const int HEIGHT = 30;

char board[HEIGHT][WIDTH];

void generateScene() {
    std::random_device rd;  
    std::mt19937 gen(rd());
    
    // Initialize board with ocean  
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = '~';  // Ocean by default
        }
    }
    
    // Ocean waves
    int numWaves = std::uniform_int_distribution<int>(5,15)(gen);
    for (int i = 0; i < numWaves; i++) {
        int wavePos;  
        for (int j = 0; j < HEIGHT; j++) {
            wavePos = std::uniform_int_distribution<int>(0, WIDTH)(gen);  
	    board[j][wavePos] = ' ';
	}
    }
    
    // Island
    int numIslands = std::uniform_int_distribution<int>(1,5)(gen);

	int islandWidth[numIslands];   
	int islandHeight[numIslands];  
	int islandX[numIslands];       
	int islandY[numIslands];

	for (int i = 0; i < numIslands; i++) {
	    
	    islandWidth[i] = std::uniform_int_distribution<int>(10,30)(gen);   
	    islandHeight[i] = std::uniform_int_distribution<int>(5,10)(gen);
	    islandX[i] = std::uniform_int_distribution<int>(0, WIDTH - islandWidth[i])(gen);    
	    islandY[i] = std::uniform_int_distribution<int>(5, HEIGHT - islandHeight[i])(gen);  
		
	    for (int j = islandY[i]; j < islandY[i] + islandHeight[i]; j++) {
		for (int k = islandX[i]; k < islandX[i] + islandWidth[i]; k++) {
		     board[j][k] = '/';   
		}      
	    }     
	    
	    //sky
		for (int j = 0; j < HEIGHT/3; j++) {
		   for (int k = 0; k < WIDTH; k++) {
		       board[j][k] = ' ';   
		   }       
		}

		int numClouds = std::uniform_int_distribution<int>(3,8)(gen);

		for (int i = 0; i < numClouds; i++) {
		   int j = std::uniform_int_distribution<int>(0, HEIGHT/3-1)(gen);
		   int k = std::uniform_int_distribution<int>(0, WIDTH-6)(gen);  
			
		   board[j][k]     = '(';
		   board[j][k + 1] = '_'; 
		   board[j][k + 2] = '_';
		   board[j][k + 3] = '_';
		   board[j][k + 4] = '_'; 
		   board[j][k + 5] = ')';
		} 
		    
	      // Palm tree  
	        int treeHeight = 5;  // Fixed height for example
	      
	       int treeX = islandX[i];
		int treeY = islandY[i];  // Start from top of island
		      
		for (int j = 0; j < treeHeight; j++) {  
		  treeY--;       
		  board[treeY][treeX] = '|';    
		}

		board[treeY][treeX + 1] = '.';  
		board[treeY][treeX + 1] = '/';       
		board[treeY][treeX + 2] = '\\';
	}

	// Access coordinates for a random island    
	int randIsland = std::uniform_int_distribution<int>(0, numIslands-1)(gen);
	int pirateX = islandX[randIsland];  
	int pirateY = islandY[randIsland]; 
    
    // Pirate 
    //int pirateX = std::uniform_int_distribution<int>(islandX, islandX + islandWidth)(gen);
    //int pirateY = std::uniform_int_distribution<int>(islandY, islandY + islandHeight)(gen);  
     
    // Randomly choose one of 4 pirate poses     
	int pose = std::uniform_int_distribution<int>(0,3)(gen);
	if (pose == 0) {  
	  board[pirateY][pirateX] = '/';  
	} else if (pose == 1) {
	  board[pirateY][pirateX] = '|';
	} else if (pose == 2) {  
	  board[pirateY][pirateX + 1] = '\\';
	} else {
	  board[pirateY][pirateX] = '.';  
	  board[pirateY + 1][pirateX] = 'o';  
	  board[pirateY + 1][pirateX + 1] = '.';  
	}
}  

void printScene() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            std::cout << board[i][j];  
        }
        std::cout << std::endl;
    }    
}

int main() {
    generateScene(); 
    printScene();
}
