#pragma once

#if __has_include(<SDL2/SDL.h>)
#include <SDL2/SDL.h>
#define LAB7_HAS_SDL 1
#else
#define LAB7_HAS_SDL 0
struct SDL_Renderer {};
struct SDL_Color {
    unsigned char r{};
    unsigned char g{};
    unsigned char b{};
    unsigned char a{};
};
#endif

#include <cmath>

struct Point {
    float x{};
    float y{};
    SDL_Color color{255, 255, 255, 255};
    virtual ~Point() = default;
    virtual void draw(SDL_Renderer* r) const = 0;
    virtual void move(float dx, float dy) { x += dx; y += dy; }
    virtual void setColor(SDL_Color c) { color = c; }
};

struct Circle : Point {
    float radius{20.0f};

    Circle(float px, float py, float pr, SDL_Color c) {
        x = px; y = py; radius = pr; color = c;
    }

    void draw(SDL_Renderer* r) const override {
#if LAB7_HAS_SDL
        SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
        for (int w = -static_cast<int>(radius); w <= static_cast<int>(radius); ++w) {
            for (int h = -static_cast<int>(radius); h <= static_cast<int>(radius); ++h) {
                if (w * w + h * h <= radius * radius) {
                    SDL_RenderDrawPoint(r, static_cast<int>(x) + w, static_cast<int>(y) + h);
                }
            }
        }
#else
        (void)r;
#endif
    }
};

struct Ring : Circle {
    float width{6.0f};

    Ring(float px, float py, float pr, float w, SDL_Color c) : Circle(px, py, pr, c), width(w) {}

    void draw(SDL_Renderer* r) const override {
#if LAB7_HAS_SDL
        SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
        const float inner = radius - width;
        for (int w = -static_cast<int>(radius); w <= static_cast<int>(radius); ++w) {
            for (int h = -static_cast<int>(radius); h <= static_cast<int>(radius); ++h) {
                const float d2 = static_cast<float>(w * w + h * h);
                if (d2 <= radius * radius && d2 >= inner * inner) {
                    SDL_RenderDrawPoint(r, static_cast<int>(x) + w, static_cast<int>(y) + h);
                }
            }
        }
#else
        (void)r;
#endif
    }

    void resizeSector(float delta) {
        width += delta;
        if (width < 2.0f) width = 2.0f;
        if (width > radius - 1.0f) width = radius - 1.0f;
    }
};

