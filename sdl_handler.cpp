#include "sdl_handler.h"
#include "NewGen.h"


NewGen* nextGen = new NewGen();


bool sdl_handler::init() {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL initialization failed" << std::endl;
		return false;
	}
	else {
		window = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			std::cout << "Window creation Failed" << std::endl;
			return false;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL) {
			std::cout << "Renderer creation failed" << std::endl;
		}

		return true;
	}



}


void sdl_handler::drawGrid(){
	

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	for (int i = 0; i < gridColNum; i++)
	{
		for (int j = 0; j < gridColNum-1; j++)
		{
			
				if (grid[i][j] == 0)
				{
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				}
				else
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				}
				SDL_Rect rectangle = { i * gridSize, j * gridSize,  gridSize,  gridSize };
				SDL_RenderFillRect(renderer, &rectangle);
			
		}
		
	}
	StartButton();
	SDL_RenderPresent(renderer);
	
}



sdl_handler::~sdl_handler() {

	delete nextGen;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}


void sdl_handler::StartButton() {
	SDL_SetRenderDrawColor(renderer, 255, 21, 20, 255);
	SDL_Rect rect = { 6 * gridSize, 19 * gridSize, gridSize * 2, gridSize };
	SDL_RenderFillRect(renderer, &rect);
}

void sdl_handler::updateGrid()
{
	grid = nextGen->updateNextGen(grid);
}

