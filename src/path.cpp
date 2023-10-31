#include <Eigen/Dense>

#include <limits>

#include "path.h"

using vec2 = Eigen::Vector2d;

PathUtils::Path::Path(std::vector<vec2> points)
:points_{points}
{}

double Distance(vec2 point_a, vec2 point_b){
    return (point_b - point_a).norm();
}


PathIndex PathUtils::Path::FindClosestPointIndex(vec2 point){
    double closest = std::numeric_limits<double>::max();
    int closest_index = -1;
    vec2 closest_point;

    for(int i = 0; i < points_.size(); i++){
        double distance = Distance(point, points_[i]);
        if(distance < closest){
            closest = distance;
            closest_index = i;
            closest_point = points_[i];
        }
    }

    //TODO: find fraction

    return PathIndex{closest_index, 0.0, closest_point};
}

        
vec2 PathUtils::Path::FindPointAtDistance(vec2 point, double distance){
    PathIndex start_index = FindClosestPointIndex(point);
    double distance_to_start = Distance(point, start_index.point);
    
    if(distance <= distance_to_start){
        return start_index.point;
    }

    double total_distance = distance_to_start;

    for(int i = start_index.base_node; i < points_.size(); i++){
        total_distance += Distance(point, points_[i]);
        if(total_distance >= distance){
            return points_[i];
        }
    }

    // For the case that the desired length is longer than the path
    return points_[points_.size()];
}
