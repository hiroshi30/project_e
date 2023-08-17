#include <stdbool.h>
#include <SDL.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"
#include "render2d.h"


int WINDOW_WIDTH;
int WINDOW_HEIGHT;
SDL_Window *WINDOW;
SDL_Renderer *RENDERER;
SDL_Event EVENT;
const Uint8 *KEYBOARD_STATE;
int R = 0, G = 0, B = 0, A = 255;


void Engine_init(int window_width, int window_height, char title[]) {
    SDL_Init(SDL_INIT_VIDEO);

    WINDOW = SDL_CreateWindow(title, 50, 50, window_width, window_height, SDL_WINDOW_SHOWN);
    RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    WINDOW_WIDTH = window_width;
    WINDOW_HEIGHT = window_height;
    
    KEYBOARD_STATE = SDL_GetKeyboardState(NULL);

    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void Engine_update(void) {
	SDL_RenderPresent(RENDERER);
}

bool Engine_event_status(void) {
    return SDL_PollEvent(&EVENT) != 0;
}

bool Engine_event_exit() {
    return !(EVENT.type == SDL_QUIT || KEYBOARD_STATE[SDL_SCANCODE_ESCAPE]);
}

void Engine_exit(void) {
	SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(WINDOW);
    SDL_Quit();
}


void set_color(int r, int g, int b) {
    R = r;
    G = g;
    B = b;
    SDL_SetRenderDrawColor(RENDERER, R, G, B, A);
}

void set_transparency(int a) {
    A = a;
    SDL_SetRenderDrawColor(RENDERER, R, G, B, A);
}

void fill(void) {
	SDL_RenderClear(RENDERER);
}

void draw_pixel(double x, double y) {
    SDL_RenderDrawPoint(RENDERER, x, WINDOW_HEIGHT - y);
}

void draw_circle(double x, double y, double radius) {
	for (int i = y - radius; i <= y + radius; ++i) {
		for (int j = x - radius; j <= x + radius; ++j) {
    		if ((j - x) * (j - x) + (i - y) * (i - y) <= radius * radius) {
    			draw_pixel(j, i);
    		}
    	}
    }
}

// void draw_line(double x1, double y1, double x2, double y2) {
//     SDL_RenderDrawLine(RENDERER, x1, WINDOW_HEIGHT - y1, x2, WINDOW_HEIGHT - y2);
// }

void draw_line(double x1, double y1, double x2, double y2) {
    set_color(255, 255, 255);

    if (x2 == x1) {
        if (y2 < y1) {
            y2 += y1;
            y1 = y2 - y1;
            y2 = y2 - y1;
        }
        for (int y = y1; y <= y2; ++y) {
            draw_pixel(x1, y);
        }
    } else {

        double k, b;
        k = (y2 - y1) / (x2 - x1);
        b = y1 - k * x1;

        if (x2 < x1) {
            x2 += x1;
            x1 = x2 - x1;
            x2 = x2 - x1;

            y2 += y1;
            y1 = y2 - y1;
            y2 = y2 - y1;
        }

        double _y1, _y2;
        _y2 = k * x1 + b;

        int i;
        if (y2 > y1) {
            i = 1;
        } else {
            i = -1;
        }

        for (int x = x1; x <= x2; ++x) {
            _y1 = _y2;
            _y2 = k * (x + 1) + b;
            for (int y = _y1; y != (int)_y2; y += i) {
                draw_pixel(x, y);
            }
        }
    }

    set_color(255, 0, 0);
    draw_circle(x1, y1, 5);
    draw_circle(x2, y2, 5);
}

void draw_polygon_mesh(Vector4 **triangle) {
    set_color(255, 255, 255);
    for (int i = 0; i < 2; ++i) {
        draw_line(triangle[i]->x, triangle[i]->y, triangle[i + 1]->x, triangle[i + 1]->y);
    }
    draw_line(triangle[0]->x, triangle[0]->y, triangle[2]->x, triangle[2]->y);
}

// void draw_polygon_mesh(Vector4 **triangle) {
//     double k, b;
//     int x1, x2;
//     for (int i = 0; i < 2; ++i) {
//         k = (triangle[i + 1]->y - triangle[i]->y) / (triangle[i + 1]->x - triangle[i]->x);
//         b = triangle[i]->y - k * triangle[i]->x;
//         if (triangle[i]->x < triangle[i + 1]->x) {
//             x1 = triangle[i]->x;
//             x2 = triangle[i + 1]->x;
//         } else {
//             x1 = triangle[i + 1]->x;
//             x2 = triangle[i]->x;
//         }
//         for (int x = x1; x <= x2; ++x) {
//             for (int y = k * x + b; y < k * (x + 1) + b; ++y) {
//                 SDL_RenderDrawPoint(RENDERER, x, WINDOW_HEIGHT - y);
//             }
//         }
//     }

//     k = (triangle[2]->y - triangle[0]->y) / (triangle[2]->x - triangle[0]->x);
//     b = triangle[0]->y - k * triangle[0]->x;
//     if (triangle[0]->x < triangle[2]->x) {
//         x1 = triangle[0]->x;
//         x2 = triangle[2]->x;
//     } else {
//         x1 = triangle[2]->x;
//         x2 = triangle[0]->x;
//     }
//     for (int x = x1; x <= x2; ++x) {
//         for (int y = k * x + b; y < k * (x + 1) + b; ++y) {
//             SDL_RenderDrawPoint(RENDERER, x, WINDOW_HEIGHT - (k * x + b));
//         }
//     }
// }