#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//TODO: a texture class to control texture position, update and rendering


class Texture
{
	public:
		int twidth;
		int theight;
		SDL_Texture* texture;

	public:
		Texture(int w, int h);
		~Texture();

		void createTexture(SDL_Renderer* renderer);
		void render(SDL_Renderer *renderer, unsigned int *pixels, int pitch,
				SDL_RendererFlip flip, bool running);
};

