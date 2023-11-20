//
// Created by Artem Malko on 08.11.2023.
//

#include "computer.h"

void Computer::ComputeStep() {
    UpdateColor();
    point_.speed_ += gravity;
    point_.coords_ += point_.speed_;
    auto inter = Reflect(point_, tr_);

    if (inter.has_value()) {
        point_.speed_ = *inter * speed_increase_;
    } else {
        size_t counter_radius = 1;
        if (!PointInsideTriangle(point_.coords_, tr_)) {
            std::cout << counter_ << "\n";
            point_.coords_ -= point_.speed_ * time_speed_;

            while (!inter.has_value()) {
                point_.radius_ += 10;
                inter = Reflect(point_, tr_);
                if (inter.has_value()) {
                    point_.speed_ = *inter;
                    point_.radius_ -= 10ll * counter_radius;
                    break;
                }
                ++counter_radius;
            }
        }
    }

    screen_->DrawPoint(point_, tr_);
    ++counter_;
    std::stringstream ss;
    ss << "image_" << counter_ << ".png" << "\n";
    screen_->WriteImage(ss.str());
}

void Computer::UpdateColor() {
    if (main_color_ == 0) {
        if (point_.Color().r >= 200) {
            point_.Color().r -= color_diff_const;
            point_.Color().g += color_diff_const;
            main_color_ = 1;
        } else {
            point_.Color().r += color_diff_const;
            point_.Color().b -= color_diff_const;
        }
    } else if (main_color_ == 1) {
        if (point_.Color().g >= 200) {
            point_.Color().g -= color_diff_const;
            point_.Color().b += color_diff_const;
            main_color_ = 2;
        } else {
            point_.Color().g += color_diff_const;
            point_.Color().r -= color_diff_const;
        }
    } else if (main_color_ == 2) {
        if (point_.Color().b >= 200) {
            point_.Color().b -= color_diff_const;
            point_.Color().r += color_diff_const;
            main_color_ = 0;
        } else {
            point_.Color().b += color_diff_const;
            point_.Color().g -= color_diff_const;
        }
    }
}

void Computer::ComputeNSteps(std::size_t n) {
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Completed " << i << "/" << n << " steps" << "\n";
        ComputeStep();
        if (i % 100 == 0) {
            color_diff_const++;
        }
    }
}
