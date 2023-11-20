//
// Created by Artem Malko on 08.11.2023.
//

#include "geometry.h"

Vector Projection(const Vector& a, const Vector& b) {
    double scalarProduct = a[0] * b[0] + a[1] * b[1];
    double lenB = b.Len();
    return b * (scalarProduct / (lenB * lenB));
}

Vector Normal(const Vector& a) {
    return Vector(-a[1], a[0]);
}

std::optional<Vector> Intersection(const Point& point, const Vector& edgeStart, const Vector& edgeEnd) {
    Vector edgeVector = edgeEnd - edgeStart;
    Vector edgeNormal = Normal(edgeVector);
    edgeNormal.Normalize();

    Vector pointToStart = point.coords_ - edgeStart;
    Vector projection = Projection(pointToStart, edgeVector);
    Vector closestPoint = edgeStart + projection;

    double edgeLen = edgeVector.Len();
    if (projection.Len() > edgeLen) {
        closestPoint = edgeEnd;
    } else if ((edgeStart - closestPoint).Len() > edgeLen) {
        closestPoint = edgeStart;
    }

    if (Dist(closestPoint, point.coords_) <= point.radius_) {
        return edgeNormal;
    } else {
        return std::nullopt;
    }
}

std::optional<Vector> Reflect(const Point& point, const Triangle& triangle) {
    Vector reflectedSpeed;
    bool intersectionFound = false;

    for (size_t i = 0; i < 3; ++i) {
        Vector start = triangle[i];
        Vector end = triangle[(i + 1) % 3];

        auto normalOpt = Intersection(point, start, end);
        if (normalOpt) {
            Vector normal = normalOpt.value().Len() != 0 ? *normalOpt : *normalOpt * -1;
            Vector speedProjection = Projection(point.speed_, normal);
            reflectedSpeed = point.speed_ - speedProjection * 2.0;
            intersectionFound = true;
            break;
        }
    }

    if (intersectionFound) {
        return reflectedSpeed;
    } else {
        return std::nullopt;
    }
}

double CrossProduct(const Vector& a, const Vector& b) {
    return a[0] * b[1] - a[1] * b[0];
}

bool SameSide(const Vector& p1, const Vector& p2, const Vector& a, const Vector& b) {
    Vector ba = b - a;
    Vector pa = p1 - a;
    Vector pb = p2 - a;

    return CrossProduct(ba, pa) * CrossProduct(ba, pb) >= 0;
}

bool PointInsideTriangle(const Vector& p, const Triangle& triangle) {
    const Vector& a = triangle[0];
    const Vector& b = triangle[1];
    const Vector& c = triangle[2];

    bool onSameSideABandP = SameSide(p, a, b, c);
    bool onSameSideBCandP = SameSide(p, b, a, c);
    bool onSameSideCAandP = SameSide(p, c, a, b);

    return onSameSideABandP && onSameSideBCandP && onSameSideCAandP;
}
