/**
 * @file Container.hpp
 * @author E. Musa, T. Locke, T. Wirtz
 * @brief Abstract templates of all used data structure containers
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

namespace ProjektAlpha {

    /**
     * @brief A generic container class
     * 
     * @tparam T The type of the elements in the container
     */
    template<typename T>
    class Container {
        public:
            /**
             * @brief Gets the size of the container
             * 
             * @return int The size of the container
             */
            virtual int get_size() = 0;

            /**
             * @brief Checks whether the container is empty
             * 
             * @return true if the container is empty, false otherwise
             */
            virtual bool is_empty() = 0;

            /**
             * @brief Gets the first element of the container
             * 
             * @return T The first element of the container
             */
            virtual T get_first() = 0;
    };

    /**
     * @brief A generic sequential container class
     * 
     * @tparam T The type of the elements in the container
     */
    template<typename T>
    class SequentialContainer : public Container<T> {
    };

    /**
     * @brief A generic iterable container class
     * 
     * @tparam T The type of the elements in the container
     */
    template<class T>
    class IterableContainer : public Container<T> {
    };

    /**
     * @brief A generic associative container class
     * 
     * @tparam T The type of the elements in the container
     */
    template<class T>
    class AssociativeContainer : public IterableContainer<T> {
        public:
            /**
             * @brief Checks whether the container contains the specified item
             * 
             * @param item The item to check for
             * @return true if the container contains the item, false otherwise
             */
            virtual bool contains(T& item) = 0;
    };
}