/**
 * @file AbstractDoublyLinkedList.hpp
 * @author Tim Locke
 * @brief Abstract template of data structure: DoublyLinkedList
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
     * @brief A DoublyLinkedList data structure interface.
     * @tparam T The type of the elements stored in the DoublyLinkedList.
     */
    template<class T>
    class AbstractDoublyLinkedList : public IterableContainer<T> {
    public:
        typedef std::shared_ptr<Node<T>> Nodeptr;

        /**
         * @brief Adds the given item to the head of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        virtual Nodeptr add_front(const T& item) = 0;
        /**
         * @brief Adds the given item to the head of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        virtual Nodeptr add_front(T& item) = 0;
        /**
         * @brief Adds the given item to the tail of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        virtual Nodeptr add_back(const T& item) = 0;
        /**
         * @brief Adds the given item to the tail of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		virtual Nodeptr add_back(T& item) = 0;
        /**
         * @brief Adds the given item after a specific Node to the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @param before The Node after which the item will be inserted to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        virtual Nodeptr add_after(Nodeptr& before, const T& item) = 0;
        /**
         * @brief Adds the given item after a specific Node to the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @param before The Node after which the item will be inserted to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		virtual Nodeptr add_after(Nodeptr& before, T& item) = 0;
        /**
         * @brief Gets wether the item is contained in the DoublyLinkedList.
         * @return bool The logical value wether the item is contained in the DoublyLinkedList.
         */
        virtual bool contains(const T& input) = 0;
        /**
         * @brief Gets wether the item is contained in the DoublyLinkedList.
         * @return bool The logical value wether the item is contained in the DoublyLinkedList.
         */
		virtual bool contains(T& input) = 0;
        /**
         * @brief Removes the first item in the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		virtual Nodeptr remove_front() = 0;
        /**
         * @brief Removes the last item in the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		virtual Nodeptr remove_back() = 0;
        /**
         * @brief Removes the specified Node in the DoublyLinkedList.
         * @param toRemove The Node which will be deleted.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		virtual Nodeptr remove(Nodeptr& toRemove) = 0;
        /**
         * @brief Gets the last element in the DoublyLinkedList.
         * @return T The last element in the DoublyLinkedList.
         */
		virtual T get_back() = 0;
        /**
         * @brief Prints all elements in the DoublyLinkedList to the console.
         */
        virtual void print() = 0;
    };
}