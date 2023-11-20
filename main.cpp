#pragma once

#include <iostream>
#include "vector.h"
#include "image.h"
#include "screen.h"
#include "computer.h"

int main() {

    std::cout << "Welcome to Geometry Renderer!" << std::endl;

    Vector speed;
    std::cout << "Input starting speed vector in x y coords" << "\n";
    std::cin >> speed[0] >> speed[1];

    const int render_quality = 3;
    Screen screen = Screen(400 * render_quality, 400 * render_quality);
    RGB red = {200, 35, 35};
    Point p = Point({200 * render_quality, 200 * render_quality}, speed, 5 * render_quality, red);
    Triangle tr = {{300, 300}, {600, 900}, {900, 300}};
    screen.WriteImage("image.png");
    Computer comp = Computer(&screen, p, tr);
    comp.ComputeNSteps(2000);

    return 0;
}

