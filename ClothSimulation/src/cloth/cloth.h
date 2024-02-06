#pragma once
#include "global/vec2.h"
#include <vector>

class renderer;
struct point;
struct cloth_stick;
struct mouse;

class cloth
{
private:
    vec2 gravity = { 0.0f, 981.0f };
    float drag = 0.01f;
    float elasticity = 10.f;

    std::vector<point*> points;
    std::vector<cloth_stick*> sticks;

public:
    cloth();
    void init(vec2 start_pos, vec2 size, float spacing);
    void update(float deltaTime, renderer& renderer, mouse& mouse);
    void draw(renderer& renderer);
    void shutdown();
};