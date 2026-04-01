#include <iostream>
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	//초기화
	SDL_Init(SDL_INIT_EVERYTHING);
	//윈도우 생성
	SDL_Window* MyWindow = SDL_CreateWindow("SDL_Project", 100,100, 1024, 768, SDL_WINDOW_SHOWN);
	//렌더러 생성
	SDL_Renderer* MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	SDL_Event MyEvent;
	bool IsRunning = true;

	int PositionX = 0;
	int PositionY = 0;
	while (IsRunning)
	{
		SDL_PollEvent(&MyEvent);

		if (MyEvent.type == SDL_QUIT)
		{
			IsRunning = false;
		}

		if (MyEvent.type == SDL_KEYDOWN)
		{
			if (MyEvent.key.keysym.sym == SDLK_w)
			{
				PositionY -= 10;
			}
			if (MyEvent.key.keysym.sym == SDLK_s)
			{
				PositionY += 10;
			}
			if (MyEvent.key.keysym.sym == SDLK_a)
			{
				PositionX -= 10;
			}
			if (MyEvent.key.keysym.sym == SDLK_d)
			{
				PositionX += 10;
			}
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
		}

		SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
		SDL_RenderClear(MyRender);

		SDL_Rect Rect{ PositionX, PositionY, 100, 100 };
		SDL_SetRenderDrawColor(MyRender, 255, 255, 0, 255);
		SDL_RenderFillRect(MyRender, &Rect);

		SDL_RenderPresent(MyRender);
	}

	//삭제
	SDL_DestroyWindow(MyWindow);
	SDL_DestroyRenderer(MyRender);

	SDL_Quit();

	return 0;
}