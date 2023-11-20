//
// Created by Artem Malko on 08.11.2023.
//

#ifndef INC_2D_GRAPHICS_GEOMETRY_H
#define INC_2D_GRAPHICS_GEOMETRY_H

#include <optional>
#include <algorithm>
#include "vector.h"
#include "point.h"
#include "triange.h"

Vector Projection(const Vector& a, const Vector& b);

Vector Normal(const Vector& a);

std::optional<Vector> Intersection(const Point& point, const Vector& edgeStart, const Vector& edgeEnd);

std::optional<Vector> Reflect(const Point& point, const Triangle& triangle);

double CrossProduct(const Vector& a, const Vector& b);

bool SameSide(const Vector& p1, const Vector& p2, const Vector& a, const Vector& b);

bool PointInsideTriangle(const Vector& p, const Triangle& triangle);

#endif //INC_2D_GRAPHICS_GEOMETRY_H
