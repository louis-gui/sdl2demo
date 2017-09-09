#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
SDL_Window* gw=0;
SDL_Surface* gss=0;
SDL_Surface* gs=0;
SDL_Surface* lddsfc(std::string path) {
	SDL_Surface* op=0;
	SDL_Surface* lddsfc2 = SDL_LoadBMP(path.c_str());
	op=SDL_ConvertSurface(lddsfc2,gss->format,0);
	SDL_FreeSurface(lddsfc2);
	lddsfc2=0;
	return op;
}
main() {
	printf("%d", SDL_WINDOWPOS_UNDEFINED);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Rect s;
	s.x = 0;
	s.y = 0;
	s.w = 640;
	s.h = 480;
	gw=SDL_CreateWindow("SDL2_demo:suofang",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
	gss=SDL_GetWindowSurface(gw);
	gs=lddsfc("imgs/5.bmp");
	int quit=0;
	SDL_Event e;
	while(!quit) {
		SDL_Delay(33);
		while(SDL_PollEvent(&e)!=0) {
			if(e.type==SDL_QUIT) {
				quit = 1;
			}
			// SDL_BlitSurface(gs,0,gss,0);
			SDL_BlitScaled(gs, 0, gss, &s);
			SDL_UpdateWindowSurface(gw);
		}
	}
}
