//
// Created by Artem Malko on 08.11.2023.
//

#ifndef INC_2D_GRAPHICS_VECTOR_H
#define INC_2D_GRAPHICS_VECTOR_H
#include <cstddef>
#include <cmath>
#include "iostream"

class Vector {
public:
    Vector() = default;

    Vector(double x, double y) : x_(x), y_(y) {
    }

    Vector(const Vector& other) {
        x_ = other.x_;
        y_ = other.y_;
    }

    Vector(Vector&& other) noexcept {
        x_ = other.x_;
        y_ = other.y_;
        other.x_ = 0;
        other.y_ = 0;
    }

    Vector& operator=(Vector&& other) noexcept {
        x_ = other.x_;
        y_ = other.y_;
        other.x_ = 0;
        other.y_ = 0;
        return *this;
    }


    Vector& operator=(const Vector& other) = default;

    double& operator[](std::size_t ind) {
        if (ind == 0) {
            return x_;
        } else {
            return y_;
        }
    }

    double operator[](std::size_t ind) const {
        if (ind == 0) {
            return x_;
        } else {
            return y_;
        }
    }

    [[nodiscard]] double Len() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    void Normalize() {
        double len = Len();
        x_ /= len;
        y_ /= len;
    }

    void operator+=(const Vector& other) {
        x_ += other.x_;
        y_ += other.y_;
    }

    void operator-=(const Vector& other) {
        x_ -= other.x_;
        y_ -= other.y_;
    }

    void operator*=(double t) {
        x_ *= t;
        y_ *= t;
    }

    friend Vector operator+(const Vector& rhs, const Vector& lhs) {
        Vector tmp = rhs;
        tmp += lhs;
        return tmp;
    }

    friend Vector operator-(const Vector& rhs, const Vector& lhs) {
        Vector tmp = rhs;
        tmp -= lhs;
        return tmp;
    }

    friend Vector operator*(const Vector& rhs, double t) {
        Vector tmp = rhs;
        tmp *= t;
        return tmp;
    }



private:
    double x_ = 0;
    double y_ = 0;
};

double Dist(const Vector& v1, const Vector& v2) {
    return (v1 - v2).Len();
}

#endif //INC_2D_GRAPHICS_VECTOR_H
