/**
 * @file randomString.cpp
 * @author T. Wirtz
 * @brief 
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <../include/MeasurementHelper/randomString.hpp>

namespace ProjektAlpha {
    RandomString::RandomString(int char_num) : char_num_(char_num) {}

    std::string RandomString::generate() {
        std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

        std::random_device rd;
        std::mt19937 generator(rd());

        std::shuffle(str.begin(), str.end(), generator);

        return str.substr(0, char_num_);
    }
}