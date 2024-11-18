/**
 * @file zeitmesser.hpp
 * @author T. Wirtz
 * @brief 
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __ZEITMESSER_HPP__
#define __ZEITMESSER_HPP__

#include <vector>
#include <chrono>


namespace ProjektAlpha {
  class Timer {
    public:
        Timer();
        void start();
        void stop();
        int get_microseconds();
        int get_milliseconds();
        int get_nanoseconds();
        int get_seconds();
        int get_minutes();
    private:
        // Unter der Haube wird std::chrono verwendet.
        // Hier werden die Typen alternativ benannt.
        typedef std::chrono::high_resolution_clock highres_clock;
        typedef std::chrono::time_point<highres_clock> Zeitpunkt;
        typedef std::chrono::duration<int, std::ratio<1>> Dauer;
    
    // Start- und Stopzeitpunkt wird entsprechend gesichert.
    Zeitpunkt start_zeitpunkt;
    Zeitpunkt stop_zeitpunkt;
    };

}
#endif
