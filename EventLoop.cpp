#include "EventLoop.h"
#include "sdl_handler.h"

void EventLoop::run() {
	sdl_handler* handler = new sdl_handler();

	handler->init();
	handler->drawGrid();
	handler->StartButton();

	int x = -1;
	int y = -1;

	bool running = true;
	bool startLife = false;
	while (running) {
		while (SDL_PollEvent(&handler->e)) {
			if (handler->e.type == SDL_QUIT) {
				running = false;
			}
			else if (handler->e.type == SDL_MOUSEBUTTONDOWN && !startLife)
			{
				x = handler->e.button.x / handler->gridSize;
				y = handler->e.button.y / (handler->gridSize);
				if (x >= 0 && x < handler->gridColNum && y >= 0 && y < handler->gridColNum - 1) {

					handler->grid[x][y] = 1;
				}
				else if (x == 7 && y == 19 ) {
					startLife = true;
				}
				std::cout << x << std::endl;
				std::cout << y << std::endl;

			}


		}
		if (startLife) {
			handler->updateGrid();
			SDL_Delay(1000);
		}

		handler->drawGrid();
		

	}
}

