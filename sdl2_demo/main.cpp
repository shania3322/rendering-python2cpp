// Example program:
// Using SDL2 to create an application window

// To compile with gcc:  (tested on Ubuntu 14.04 64bit):
// If using openGL:
//	 g++ sdl2_opengl.cpp -lSDL2 -lGL
// if using SDL only:
//   g++ main.cpp -o prog -lSDL2 -lSDL2_image
// To compile with msvc: (tested on Windows 7 64bit)
//   cl sdl2_opengl.cpp /I C:\sdl2path\include /link C:\path\SDL2.lib C:\path\SDL2main.lib /SUBSYSTEM:CONSOLE /NODEFAULTLIB:libcmtd.lib opengl32.lib

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_opengl.h>
//#include <GL/gl.h>
#include <stdio.h>
#include <cstdint>
#include <iostream>

int main(int argc, char* argv[]) {

    SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	uint32_t windowflags=SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE;
	int win_height=480;
	int win_width=640;
	int running=1;


    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "SYRenderer",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        win_width,                               // width, in pixels
        win_height,                               // height, in pixels
        windowflags                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		// In the case that the window could not be made...
		printf("Could not create renderer: %s\n", SDL_GetError());
		return 1;
	}

	//texture = IMG_LoadTexture(renderer, "badger.png");
    texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STREAMING, win_width, win_height);

    //Pixel drawing goes here.
    unsigned int pixels[win_width*win_height];
    int pitch = win_width*sizeof(int);

    for (int i=0; i<(win_width*win_height); i++){
        pixels[i] = 0x00;
    }
    for (int i=win_width*win_height/2;i<win_width*win_height/2+win_width*2;i++){
        pixels[i] =0xFF000000;
    }
    SDL_UpdateTexture(texture, NULL, pixels, pitch);

	//SDL_Rect texture_rect;
	//texture_rect.x=0;
	//texture_rect.y=0;
	//texture_rect.w=win_width;
	//texture_rect.h=win_height;

	// The window is open: could enter program loop here (see SDL_PollEvent())
	while(running) {
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				//case SDL_WINDOWEVENT:
				//	switch(event.window.event)
				//	{
				//		case SDL_WINDOWEVENT_RESIZED:
				//			{
				//				int ww;
				//				int hh;
				//				SDL_GetWindowSize(window, &ww, &hh);
				//				texture_rect.w = ww;
				//				texture_rect.h = hh;
				//			}
				//			break;
				//	}
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
							std::cout<<"left"<<std::endl;
							break;
						case SDLK_w:
							std::cout<<"up"<<std::endl;
							break;
						case SDLK_d:
							std::cout<<"right"<<std::endl;
							break;
						case SDLK_s:
							std::cout<<"down"<<std::endl;
							break;
						case SDLK_q:
							running=0;
							break;
						default:
							break;
					}
					break;
				case SDL_QUIT:
					running=0;
					break;
			}
		}
		SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00, SDL_ALPHA_OPAQUE);
		//SDL_RenderCopy(renderer, texture, NULL, &texture_rect);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

    //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
