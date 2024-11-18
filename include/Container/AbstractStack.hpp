/**
 * @file AbstractStack.hpp
 * @author T. Wirtz
 * @brief Abstract template of data structure: Stack
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <../include/Container/Container.hpp>
#include <../include/Container/Node.hpp>

namespace ProjektAlpha {

    /**
     * @brief A abstract class for stack implementation.
     * 
     * @tparam T The data type of the stack elements.
     */
    template <typename T>
    class AbstractStack : public SequentialContainer<T> {

    public:
        /**
         * @brief Pushes an item to the top of the stack.
         * 
         * @param item The item to be added to the stack.
         */
        virtual void push(T item) = 0;

        /**
         * @brief Removes the top item from the stack and returns it.
         * 
         * @return T The top item of the stack.
         */
        virtual T pop() = 0;

        /**
         * @brief Prints the contents of the stack.
         */
        virtual void print() = 0;
    };
}
