//
// Created by Artem Malko on 08.11.2023.
//

#include "screen.h"

Screen::Screen(size_t width, size_t height, RGB default_) {
    image_ = new Image(width, height);
    for (size_t x = 0; x < width; ++x) {
        for (size_t y = 0; y < height; ++y) {
            image_->SetPixel(default_, y, x);
        }
    }
}

void Screen::DrawPoint(const Point& p, const Triangle& tr) {
    double rad_sq =  p.radius_ * p.radius_;
    double eps = 20;
    for (int x = p.coords_[0] - p.radius_; x < p.coords_[0] + p.radius_; ++x) {
        for (int y = p.coords_[1] - p.radius_; y < p.coords_[1] + p.radius_; ++y) {
            if (x >= 0 && y >= 0) {
                Vector v = {static_cast<double>(x), static_cast<double>(y)};
                if (!PointInsideTriangle(v, tr)) {
                    continue;
                }
                double dist_sq = ((x - p.coords_[0]) * (x - p.coords_[0])) + ((y - p.coords_[1]) * (y - p.coords_[1]));
                if (dist_sq + eps < rad_sq) {
                    image_->SetPixel(p.color_, y, x);
                } else if (dist_sq < rad_sq) {
                    image_->SetPixel({0, 0, 0}, y, x);
                }

            }
        }
    }
}

void Screen::DrawTriangle(const Triangle& tr) {
    for (int i = 0; i < 3; ++i) {
        Vector speed = tr[(i + 1) % 3] - tr[i];
        speed.Normalize();
        Vector pos = tr[i];
        while (Dist(pos, tr[(i + 1) % 3]) > 1) {
            image_->SetPixel(tr.Color(), pos[1], pos[0]);
            pos += speed;
        }
    }
}
