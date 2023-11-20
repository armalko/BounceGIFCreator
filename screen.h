//
// Created by Artem Malko on 08.11.2023.
//

#ifndef INC_2D_GRAPHICS_SCREEN_H
#define INC_2D_GRAPHICS_SCREEN_H
#include "image.h"
#include "point.h"
#include "triange.h"
#include "iostream"
#include "geometry.h"

class Screen {
public:
    Screen() = default;

    Screen(size_t width, size_t height, RGB default_ = {255, 255, 255});

    void WriteImage(const std::string& path) const {
        image_->Write(path);
    }

    void DrawPoint(const Point& p, const Triangle& tr);

    void DrawTriangle(const Triangle& tr);

    ~Screen() {
        delete image_;
    }

private:
    Image* image_ = nullptr;
};


#endif //INC_2D_GRAPHICS_SCREEN_H
