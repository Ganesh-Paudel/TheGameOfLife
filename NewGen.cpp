#include "NewGen.h"
#include "sdl_handler.h"

vector<vector<int>> NewGen::updateNextGen(vector<vector<int>> arr) {
	//go through the whole array
	//check for the surrounding members
	//if less than 2 or more than 3  and alive, then it's dies
	//if 3 and dead, then it's regenaretes

	

	vector<vector<int>> newGrid = arr;
	int aliveNeighbours = 0;

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 19; ++j) {
			aliveNeighbours = 0;
			//checks
			//get the 3 by 3 grid around the current cell
			for (int k = i - 1; k <= i + 1; k++) {
				for (int l = j - 1; l <= j + 1; l++) {
					if (k == i && j == l) continue;
					//out of bounds check
					if (k >= 0 && k < 15 && l >= 0 && l < 14) {
						if (arr[k][l] == 1) {
							aliveNeighbours++;
						}
					}
				}
			}
			if ((aliveNeighbours < 2 || aliveNeighbours > 3) && arr[i][j] == 1) {
				newGrid[i][j] = 0;
			}
			else if (arr[i][j] == 0 && aliveNeighbours == 3) {
				newGrid[i][j] = 1;
			}

		}
	}
	return newGrid;
	
}