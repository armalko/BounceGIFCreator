//
// Created by Artem Malko on 08.11.2023.
//

#ifndef INC_2D_GRAPHICS_POINT_H
#define INC_2D_GRAPHICS_POINT_H

#include <cstddef>
#include <utility>
#include "vector.h"
#include "image.h"

class Point {
public:
    Point() = default;

    Point(Vector coords, Vector speed, double radius, const RGB& rgb) :
        coords_(std::move(coords)), speed_(std::move(speed)), radius_(radius), color_(rgb){
    }

    [[nodiscard]] RGB Color() const {
        return color_;
    }

    RGB& Color() {
        return color_;
    }


    Vector coords_ = {0, 0};
    Vector speed_ = {0, 0};
    double radius_ = 1;
    RGB color_ = RGB();
};



#endif //INC_2D_GRAPHICS_POINT_H
