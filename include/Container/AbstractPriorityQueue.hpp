/**
 * @file AbstractPriorityQueue.hpp
 * @author E. Musa
 * @brief Abstract template of data structure: PriorityQueue
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

//#include <Container/IterableContainer.hpp>
#include <Container/Container.hpp>
#include <Container/PriorityNode.hpp>
#include <iostream>

namespace ProjektAlpha{
    /**
     * @brief A PriorityQueue data structure interface.
     * @param T: The type of the elements stored in the PriorityQueue.
     * @param C: The type of the priority given to the elements in the PriorityQueue.
     */
    template<typename T, typename C>
    class AbstractPriorityQueue : public IterableContainer <T>{
        public:
        virtual void insert (T item, C priority) = 0;
        virtual T remove () = 0;
        virtual void printQueue()=0;
    };

}