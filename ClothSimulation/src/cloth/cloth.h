#pragma once
#include "global/vec2.h"
#include <vector>

class renderer;
class point;
class cloth_stick;

class cloth
{
private:
    vec2 gravity = { 0.0f, 981.0f };
    float drag = 0.01f;
    float elasticity = 10.0f;

    std::vector<point*> points;
    std::vector<cloth_stick*> sticks;

public:
    cloth();
    void init(vec2 start_pos, vec2 size, float spacing);
    void update(float deltaTime, renderer& renderer);
    void draw(renderer& renderer);
    void shutdown();
};