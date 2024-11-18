/**
 * @file Node.hpp
 * @author E. Musa, T. Locke, T. Wirtz
 * @brief Full implementation of PriorityNode
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <memory>

namespace ProjektAlpha {

    template<class T, class C>
    class PriorityNode {
    public:
        std::shared_ptr<PriorityNode> next;
        std::weak_ptr<PriorityNode> prev;
        T data_;
        C priority_;

        PriorityNode(T& data, C& priority) {
            data_ = data;
            priority_ = priority;
            next = nullptr;
            prev = next;
        }

        typedef std::shared_ptr<PriorityNode> Nodeptr;
        typedef std::weak_ptr<PriorityNode> WeakNodeptr;
    };
}
