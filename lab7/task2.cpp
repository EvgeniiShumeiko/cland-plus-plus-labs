#include <iostream>
#include "shapes.h"

int main() {
#if !LAB7_HAS_SDL
    std::cout << "SDL2 не установлен. Установите SDL2 для графического запуска task2.\n";
    return 0;
#else
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
    SDL_Window* win = SDL_CreateWindow("Lab7 Task2", 120, 120, 800, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!win || !ren) return 1;

    Ring ring(390, 240, 90, 14, {220, 220, 30, 255});

    bool run = true;
    SDL_Event e;
    while (run) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = false;
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) ring.resizeSector(+2.0f);
                if (e.key.keysym.sym == SDLK_DOWN) ring.resizeSector(-2.0f);
                if (e.key.keysym.sym == SDLK_1) ring.setColor({240, 80, 80, 255});
                if (e.key.keysym.sym == SDLK_2) ring.setColor({80, 240, 120, 255});
                if (e.key.keysym.sym == SDLK_3) ring.setColor({90, 140, 255, 255});
            }
        }

        SDL_SetRenderDrawColor(ren, 12, 12, 12, 255);
        SDL_RenderClear(ren);
        ring.draw(ren);
        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
#endif
}

