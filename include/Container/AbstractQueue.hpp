/**
 * @file AbstractQueue.hpp
 * @author E. Musa
 * @brief Abstract template of data structure: Queue
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <Container/Container.hpp>
#include <Container/Node.hpp>
#include <iostream>

namespace ProjektAlpha{
    /**
     * @brief A PriorityQueue data structure interface.
     * @param T: The type of the elements stored in the PriorityQueue.
     */
    template<typename T>
    class AbstractQueue : public SequentialContainer <T>{
        public:
        virtual void enqueue (T item) = 0;
        virtual T dequeue () = 0;
        virtual void printQueue()=0;
    };
}