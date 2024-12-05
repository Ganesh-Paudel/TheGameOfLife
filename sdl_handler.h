#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;
class sdl_handler
{
public:
	bool init();

	~sdl_handler();

	void drawGrid();
	void StartButton();
	void updateGrid();
	
	vector<vector<int>> grid{ vector<vector<int>>(20, vector<int>(19, 0)) };
	

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	const int gridColNum = 20;
	const int gridColRow = 19;
	const int gridSize = 20;
	const int width = gridColNum * gridSize;
	const int height = (gridColNum * gridSize);

private:

};

