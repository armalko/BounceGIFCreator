//
// Created by Artem Malko on 08.11.2023.
//

#ifndef INC_2D_GRAPHICS_TRIANGE_H
#define INC_2D_GRAPHICS_TRIANGE_H

#include <utility>

#include "vector.h"
#include "array"
#include "image.h"

class Triangle {
public:
    Triangle() = default;

    Triangle(Vector v1, Vector v2, Vector v3) {
        data_ = {std::move(v1), std::move(v2), std::move(v3)};
    }

    Vector& operator[](std::size_t ind) {
        return data_[ind];
    }

    Vector operator[](std::size_t ind) const {
        return data_[ind];
    }

    [[nodiscard]] RGB Color() const {
        return color;
    }

    RGB& Color() {
        return color;
    }


private:
    std::array<Vector, 3> data_;
    RGB color = {0, 0, 0};
};


#endif //INC_2D_GRAPHICS_TRIANGE_H
