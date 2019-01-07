#pragma once

#include <csc/SDLGL.h>
#include <csc/debug.h>
#include <csc/debug_gl.h>
#include <csc/v4.h>
#include <csc/shader.h>
#include <csc/gen.h>
#include <csc/gtext.h>
#include <csc/xxgl.h>


#include <stdio.h>
#include <unistd.h>


#define APP_WINDOW_WIDTH 1024
#define APP_WINDOW_HEIGHT 768
#define APP_TITLE "Video and plot"

#define APP_QUIT 0x0001
#define APP_ERROR 0x0002


enum di_index
{
	DI_BOX1,
	DI_TEXT,
	DI_BOX2,
	DI_N
};


void app_init (uint32_t * flags)
{
	int r = SDL_Init (SDL_INIT_VIDEO);
	ASSERT_F (r == 0, "SDL_Init %i\n", SDL_GetError ());
}


void app_set_icon (SDL_Window * window)
{
	uint16_t pixels [16*16] = 
	{
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0aab, 0x0789, 0x0bcc, 0x0eee, 0x09aa, 0x099a, 0x0ddd,
		0x0fff, 0x0eee, 0x0899, 0x0fff, 0x0fff, 0x1fff, 0x0dde, 0x0dee,
		0x0fff, 0xabbc, 0xf779, 0x8cdd, 0x3fff, 0x9bbc, 0xaaab, 0x6fff,
		0x0fff, 0x3fff, 0xbaab, 0x0fff, 0x0fff, 0x6689, 0x6fff, 0x0dee,
		0xe678, 0xf134, 0x8abb, 0xf235, 0xf678, 0xf013, 0xf568, 0xf001,
		0xd889, 0x7abc, 0xf001, 0x0fff, 0x0fff, 0x0bcc, 0x9124, 0x5fff,
		0xf124, 0xf356, 0x3eee, 0x0fff, 0x7bbc, 0xf124, 0x0789, 0x2fff,
		0xf002, 0xd789, 0xf024, 0x0fff, 0x0fff, 0x0002, 0x0134, 0xd79a,
		0x1fff, 0xf023, 0xf000, 0xf124, 0xc99a, 0xf024, 0x0567, 0x0fff,
		0xf002, 0xe678, 0xf013, 0x0fff, 0x0ddd, 0x0fff, 0x0fff, 0xb689,
		0x8abb, 0x0fff, 0x0fff, 0xf001, 0xf235, 0xf013, 0x0fff, 0xd789,
		0xf002, 0x9899, 0xf001, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0xe789,
		0xf023, 0xf000, 0xf001, 0xe456, 0x8bcc, 0xf013, 0xf002, 0xf012,
		0x1767, 0x5aaa, 0xf013, 0xf001, 0xf000, 0x0fff, 0x7fff, 0xf124,
		0x0fff, 0x089a, 0x0578, 0x0fff, 0x089a, 0x0013, 0x0245, 0x0eff,
		0x0223, 0x0dde, 0x0135, 0x0789, 0x0ddd, 0xbbbc, 0xf346, 0x0467,
		0x0fff, 0x4eee, 0x3ddd, 0x0edd, 0x0dee, 0x0fff, 0x0fff, 0x0dee,
		0x0def, 0x08ab, 0x0fff, 0x7fff, 0xfabc, 0xf356, 0x0457, 0x0467,
		0x0fff, 0x0bcd, 0x4bde, 0x9bcc, 0x8dee, 0x8eff, 0x8fff, 0x9fff,
		0xadee, 0xeccd, 0xf689, 0xc357, 0x2356, 0x0356, 0x0467, 0x0467,
		0x0fff, 0x0ccd, 0x0bdd, 0x0cdd, 0x0aaa, 0x2234, 0x4135, 0x4346,
		0x5356, 0x2246, 0x0346, 0x0356, 0x0467, 0x0356, 0x0467, 0x0467,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
		0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff
	};
	SDL_Surface * surface = SDL_CreateRGBSurfaceFrom (pixels,16,16,16,16*2,0x0f00,0x00f0,0x000f,0xf000);
	ASSERT (surface);
	SDL_SetWindowIcon (window, surface);
	SDL_FreeSurface (surface);
}


SDL_Window * app_create_window ()
{
	SDL_Window * window = NULL;
	window = SDL_CreateWindow 
	(
		APP_TITLE, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		APP_WINDOW_WIDTH, 
		APP_WINDOW_HEIGHT, 
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);
	ASSERT_F (window != NULL, "SDL_CreateWindow: %s", SDL_GetError());
	app_set_icon (window);
	//SDL_SetWindowBordered (window, SDL_FALSE);
	//SDL_SetWindowOpacity (window, 0.5);
	return window;
}


void gpu_setup_vertex1 (GLuint vbo [3], uint32_t vn)
{
	GLenum const target [] = {GL_ARRAY_BUFFER, GL_ARRAY_BUFFER, GL_ARRAY_BUFFER};
	uint32_t const index [] = {0, 1, 2};
	GLenum const type [] = {GL_FLOAT, GL_FLOAT, GL_FLOAT};
	GLboolean const normalized [] = {GL_FALSE, GL_FALSE, GL_FALSE};
	uint32_t const offset [] = {0, 0, 0};
	uint32_t const dim [] = {4, 4, 4};
	uint32_t const stride [] = {sizeof (float) * dim [0], sizeof (float) * dim [1], sizeof (float) * dim [2]};
	GLbitfield const flags [] = {GL_MAP_WRITE_BIT, GL_MAP_WRITE_BIT, GL_MAP_WRITE_BIT};
	
	xxgl_layout 
	(
		3,
		index,
		dim,
		type,
		normalized,
		stride,
		offset,
		target,
		vbo
	);
	
	TRACE_F ("vn: %i", vn);
	xxgl_allocate 
	(
		3,
		target,
		vbo,
		stride,
		NULL,
		flags,
		vn
	);
}



void setup_test_texture ()
{
	GLuint texture;
	GLsizei const width = 2;
	GLsizei const height = 2;
	GLsizei const layerCount = 2;
	GLsizei const mipLevelCount = 1;
	// Read you texels here. In the current example, we have 2*2*2 = 8 texels, with each texel being 4 GLubytes.
	GLubyte texels[32] = 
	{
		 // Texels for first image.
		 0,   0,   0,   255,
		 255, 0,   0,   255,
		 0,   255, 0,   255,
		 0,   0,   255, 255,
		 // Texels for second image.
		 255, 255, 255, 255,
		 255, 255,   0, 255,
		 0,   255, 255, 255,
		 255, 0,   255, 255,
	};
	glGenTextures (1,&texture);
	glBindTexture (GL_TEXTURE_2D_ARRAY,texture);
	// Allocate the storage.
	glTexStorage3D (GL_TEXTURE_2D_ARRAY, mipLevelCount, GL_RGBA8, width, height, layerCount);
	// Upload pixel data.
	// The first 0 refers to the mipmap level (level 0, since there's only 1)
	// The following 2 zeroes refers to the x and y offsets in case you only want to specify a subrectangle.
	// The final 0 refers to the layer index offset (we start from index 0 and have 2 levels).
	// Altogether you can specify a 3D box subset of the overall texture, but only one mip level at a time.
	glTexSubImage3D (GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, width, height, layerCount, GL_RGBA, GL_UNSIGNED_BYTE, texels);
	// Always set reasonable texture parameters
	glTexParameteri (GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri (GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}





