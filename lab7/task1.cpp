#include <iostream>
#include <vector>
#include "shapes.h"

int main() {
#if !LAB7_HAS_SDL
    std::cout << "SDL2 не установлен. Установите SDL2 для графического запуска task1.\n";
    return 0;
#else
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL init error\n";
        return 1;
    }
    SDL_Window* win = SDL_CreateWindow("Lab7 Task1", 100, 100, 800, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!win || !ren) return 1;

    Circle c1(120, 160, 35, {255, 50, 50, 255});
    Ring r1(500, 260, 60, 10, {50, 180, 255, 255});
    std::vector<Point*> objs = {&c1, &r1};

    bool run = true;
    SDL_Event e;
    while (run) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = false;
        }
        c1.move(0.25f, 0.0f);
        if (c1.x > 830.0f) c1.x = -30.0f;
        r1.move(-0.18f, 0.0f);
        if (r1.x < -80.0f) r1.x = 860.0f;

        SDL_SetRenderDrawColor(ren, 10, 10, 18, 255);
        SDL_RenderClear(ren);
        for (const Point* p : objs) p->draw(ren);
        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
#endif
}

