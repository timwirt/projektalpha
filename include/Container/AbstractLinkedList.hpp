/**
 * @file AbstractLinkedList.hpp
 * @author Tim Locke
 * @brief Abstract template of data structure: LinkedList
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <Container/Container.hpp>
#include <Container/Node.hpp>

namespace ProjektAlpha {

    /**
     * @brief A LinkedList data structure interface.
     * @tparam T The type of the elements stored in the LinkedList.
     */
    template<class T>
    class AbstractLinkedList : public IterableContainer<T> {
    public:
        typedef std::shared_ptr<Node<T>> Nodeptr;

        /**
         * @brief Adds the given item to the head of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        virtual Nodeptr add_front(const T& item) = 0;
        /**
         * @brief Adds the given item to the head of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        virtual Nodeptr add_front(T& item) = 0;
        /**
         * @brief Adds the given item to the tail of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        virtual Nodeptr add_back(const T& item) = 0;
        /**
         * @brief Adds the given item to the tail of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		virtual Nodeptr add_back(T& item) = 0;
        /**
         * @brief Adds the given item after a specific Node to the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @param before The Node after which the item will be inserted to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        virtual Nodeptr add_after(Nodeptr& before, const T& item) = 0;
        /**
         * @brief Adds the given item after a specific Node to the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @param before The Node after which the item will be inserted to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		virtual Nodeptr add_after(Nodeptr& before, T& item) = 0;
        /**
         * @brief Gets wether the item is contained in the LinkedList.
         * @return bool The logical value wether the item is contained in the LinkedList.
         */
        virtual bool contains(const T& input) = 0;
        /**
         * @brief Gets wether the item is contained in the LinkedList.
         * @return bool The logical value wether the item is contained in the LinkedList.
         */
		virtual bool contains(T& input) = 0;
        /**
         * @brief Removes the first item in the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		virtual Nodeptr remove_front() = 0;
        /**
         * @brief Removes the last item in the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		virtual Nodeptr remove_back() = 0;
        /**
         * @brief Removes the item after the specified Node in the LinkedList.
         * @param before The item after which the next element will be deleted.
         * @return Nodeptr The new head of the LinkedList.
         */
		virtual Nodeptr remove_after(Nodeptr& before) = 0;
        /**
         * @brief Gets the last element in the LinkedList.
         * @return T The last element in the LinkedList.
         */
		virtual T get_back() = 0;
        /**
         * @brief Prints all elements in the LinkedList to the console.
         */
        virtual void print() = 0;
    };
}