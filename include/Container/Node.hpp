/**
 * @file Node.hpp
 * @author E. Musa, T. Locke, T. Wirtz
 * @brief Full implementation of Node
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <memory>

namespace ProjektAlpha {

    template<class T>
    class Node {
    public:
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        T data_;

        /**
         * @brief Construct a new Node object
         * 
         * @param data 
         */
        Node(T& data) {
            data_ = data;
            next = nullptr;
            prev = next;
        }

        typedef std::shared_ptr<Node> Nodeptr;
        typedef std::weak_ptr<Node> WeakNodeptr;
    };
}
//Eichendorf: ROmantik