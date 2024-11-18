/**
 * @file AbstractOrderedSet.hpp
 * @author Tim Locke
 * @brief Abstract template of data structure: OrderedSet
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <Container/Container.hpp>

namespace ProjektAlpha {

    /**
     * @brief An OrderedSet data structure interface.
     * @tparam T The type of the elements stored in the OrderedSet.
     */
    template<class T>
    class AbstractOrderedSet : public AssociativeContainer<T> {

        virtual void add(T& item) = 0;
        virtual void remove(T& item) = 0;
        virtual bool contains(T& item) = 0;
        virtual T get_min() = 0;
        virtual T get_max() = 0;
    };
}