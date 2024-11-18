/**
 * @file AbstractHashMap.hpp
 * @author T. Wirtz
 * @brief Abstract template of data structure: HashMap
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
    * @brief The AbstractHashMap class template.
    *
    * @tparam T The type of the elements that the HashMap can store.
    */
    template <typename T>
    class AbstractHashMap : public AssociativeContainer<T> {
        public:
        /**
        * @brief Adds an element to the HashMap.
        *
        * @param item The element to add.
        */
        virtual void add(T& item) = 0;

        /**
         * @brief Removes an element from the HashMap.
         * 
         * @param item The element to remove.
         */
        virtual void remove(T& item) = 0;

        /**
         * @brief Prints the contents of the HashMap to the console.
         */
        virtual void print() = 0;
    };
}