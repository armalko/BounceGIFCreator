//
// Created by Artem Malko on 08.11.2023.
//

#ifndef INC_2D_GRAPHICS_COMPUTER_H
#define INC_2D_GRAPHICS_COMPUTER_H
#pragma once
#include <utility>

#include "screen.h"
#include "point.h"
#include "vector.h"
#include "triange.h"
#include <sstream>
#include "geometry.h"

class Computer {
public:
    Computer() = default;

    Computer(Screen* screen, Point pos, Triangle tr, double time_speed = 1) {
        screen_ = screen;
        point_ = std::move(pos);
        tr_ = std::move(tr);
        time_speed_ = time_speed;
        screen_->DrawTriangle(tr_);
        screen_->DrawPoint(point_, tr_);
        screen_->WriteImage("image_0.png");
    }

    void ComputeStep();

    void UpdateColor();

    void ComputeNSteps(std::size_t n);

private:
    Screen* screen_ = nullptr;
    Point point_;
    Triangle tr_;
    size_t main_color_ = 0;
    double time_speed_ = 1;
    double speed_increase_ = 1.03;
    size_t counter_ = 0;
    int color_diff_const = 3;
    const Vector gravity = {0, 0.5};
};


#endif //INC_2D_GRAPHICS_COMPUTER_H
