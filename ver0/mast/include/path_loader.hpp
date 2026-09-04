#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>




// pathのyamlファイル入力

#include "geometry_msgs/msg/pose2_d.hpp"
#include "yaml-cpp/yaml.h"




namespace path_loader{


    inline constexpr std::array<std::string_view, 5> path_files_name = {
        "start_to_bucket",
        "bucket_to_flag",
        "bucket_to_start",
        "start_to_flag",
        "flag_to_start"
    };


    struct Path{
        std::string name;
        std::vector<geometry_msgs::msg::Pose2D> poses;
    };

    inline Path load_path(const std::string &path_directory, std::string_view path_name)
    {
        const std::string file_path = path_directory + std::string(path_name) + ".yaml";
        const YAML::Node root = YAML::LoadFile(file_path);

        if (!root["path"] || !root["path"].IsSequence()) {
            throw std::runtime_error("Invalid path sequence in " + file_path);
        }

        Path path;
        path.name = std::string(path_name);

        for (const YAML::Node & node : root["path"]) {
            if (!node["x"] || !node["y"] || !node["yaw"]) {
                throw std::runtime_error("Missing x, y, or yaw in " + file_path);
            }

            geometry_msgs::msg::Pose2D pose;
            pose.x = node["x"].as<double>();
            pose.y = node["y"].as<double>();
            pose.theta = node["yaw"].as<double>();

            if (
                !std::isfinite(pose.x) ||
                !std::isfinite(pose.y) ||
                !std::isfinite(pose.theta))
            {
                throw std::runtime_error("Non-finite pose in " + file_path);
            }
            path.poses.push_back(pose);
        }

        if (path.poses.empty()) {
            throw std::runtime_error("Path is empty: " + file_path);
        }

        return path;
    }

    inline std::array<Path, path_files_name.size()> load_paths(const std::string &path_directory)
    {
        std::array<Path, path_files_name.size()> paths;

        for(size_t i = 0; i < path_files_name.size(); i++){
            paths[i] = load_path(path_directory, path_files_name[i]);
        }
        
        return paths;
    }


    inline uint32_t find_path_index(std::string_view name){

        for(uint32_t i = 0; i < path_files_name.size(); i++){
            if(name == path_files_name[i]){
                return i;
            }
        }
        return path_files_name.size();
    }

}




