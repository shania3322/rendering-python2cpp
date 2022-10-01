#include <iostream>
#include "sdltexture.h"

Texture::Texture(int w, int h){
	twidth = w;
	theight = h;
	texture = NULL;
}

Texture::~Texture(){
	SDL_DestroyTexture(texture);
}

void Texture::createTexture(SDL_Renderer* renderer)
{
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, twidth, theight);

}

void Texture::render(SDL_Renderer *renderer, unsigned int *pixels, int pitch,
		SDL_RendererFlip flip, bool running)
{
	SDL_UpdateTexture(texture, NULL, pixels, pitch);

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
		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderCopyEx(renderer, texture, NULL, NULL, 0.0, NULL,flip);
		SDL_RenderPresent(renderer);
	}
}

