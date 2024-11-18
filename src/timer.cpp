/**
 * @file timer.cpp
 * @author T. Wirtz
 * @brief 
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <../include/MeasurementHelper/timer.hpp>

namespace ProjektAlpha {

    Timer::Timer() {
    }

    void Timer::start() {
    start_zeitpunkt = std::chrono::high_resolution_clock::now();
    }

    void Timer::stop() {
    stop_zeitpunkt = std::chrono::high_resolution_clock::now();
    }

    int Timer::get_microseconds() {
    return std::chrono::duration_cast<std::chrono::microseconds>(stop_zeitpunkt - start_zeitpunkt).count();
    }

    int Timer::get_milliseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop_zeitpunkt - start_zeitpunkt).count();
    }

    int Timer::get_seconds() {
    return std::chrono::duration_cast<std::chrono::seconds>(stop_zeitpunkt - start_zeitpunkt).count();
    }

    int Timer::get_minutes() {
    return std::chrono::duration_cast<std::chrono::minutes>(stop_zeitpunkt - start_zeitpunkt).count();
    }

    int Timer::get_nanoseconds() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop_zeitpunkt - start_zeitpunkt).count();
    }

}
