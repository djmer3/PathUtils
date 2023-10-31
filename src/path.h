#pragma once

#include <vector>
#include <eigen3/Eigen/Dense>

using vec2 = Eigen::Vector2d;

struct PathIndex{
    int base_node;
    double fraction_to_next_node;
    vec2 point;
};

namespace PathUtils{
    class Path{
    private:
        std::vector<vec2> points_;

        PathIndex FindClosestPointIndex(vec2 point);

    public:
        Path(std::vector<vec2> points);
        vec2 FindPointAtDistance(vec2 point, double distance);

    };
}