/**
 * @file randomString.hpp
 * @author T. Wirtz
 * @brief 
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <random>
#include <string>

namespace ProjektAlpha {
    class RandomString {
        public:
            RandomString(int char_num);
            std::string generate();
            
        private:
            int char_num_;
    };
    
}