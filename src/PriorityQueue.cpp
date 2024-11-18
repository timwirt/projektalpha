/**
 * @file PriorityQueue.cpp
 * @author E. Musa
 * @brief Full implementation of data structure: PriorityQueue
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <Container/AbstractPriorityQueue.hpp>
#include <iostream>

namespace ProjektAlpha{
    /**
     * @brief A PriorityQueue data structure that implements the AbstractPriorityQueue interface.
     * @tparam T The type of the elements stored in the PriorityQueue.
     */
    template<typename T, typename C>
    class PriorityQueue : public AbstractPriorityQueue<T, C>{
    private:
        std::shared_ptr<PriorityNode<T, C>> head;
        int size;
    public:
        /**
         * @brief Constructs a new empty PriorityQueue.
         */
        PriorityQueue(){
            size=0;
            head=nullptr;
        }
        /**
         * @brief Constructs a new PriorityQueue object with the given input.
         * @param item The item to be added to the PriorityQueue.
         * @param priority The priority given to the added item. 
         */
        PriorityQueue(T item, C priority){
            size=1;
            std::shared_ptr<PriorityNode<T, C>> current = std::make_shared<PriorityNode<T, C>> (item, priority);
            head=current;
            head->next=nullptr;
        }
        /**
         * @brief Inserts the given Item to the PriorityQueue at the right place.
         * @param item The item to be added to the PriorityQueue.
         * @param priority The priority given to the added item.
         */
        void insert(T item, C priority){
            size++;
            std::shared_ptr<PriorityNode<T, C>> current = std::make_shared<PriorityNode<T, C>> (item, priority);
            if(head==nullptr){
                head=current;
                current->next=nullptr;
                return;
            } else if(head->priority_<current->priority_){
                current->next=head;
                head=current;
            }
            else{
                std::shared_ptr<PriorityNode<T, C>> testItem;
                std::shared_ptr<PriorityNode<T, C>> temp;               
                testItem=head;
                while (testItem->next && testItem->priority_>current->priority_) {
                    temp=testItem;
                    testItem=testItem->next;
                }
                current->next=testItem;
                testItem=temp;
                testItem->next=current;
            }
        }
        /**
         * @brief Removes the head of the PriorityQueue, which is the item with the highest priority
         * @return T: The Item that was removed
         */
        T remove(){
            size--;
            if (head == nullptr) {
                size=0;
                return NULL;
            }
            head = head->next;
            return head->data_;
        }
        /**
         * @brief Gets the first item of the PriorityQueue
         * @return T: The first Item
         */
        T get_first(){
            if(head==nullptr){
                return NULL;
            }
            return head->data_;
        }
        /**
         * @brief Gets whether the PriorityQueue is empty
         * @return bool: True if empty; False if not empty
         */
        bool is_empty(){
            if(head==nullptr){
                return true;
            }
            return false;
        }
        /**
         * @brief Gets the size of the PriorityQueue
         * @return int: The size of the PriorityQueue
         */
        int get_size(){
            return size;
        }
        /**
         * @brief Prints all elements in the DoublyLinkedList.
         */
        void printQueue() {
            if (head == nullptr) {
                std::cout << "Queue is empty" << std::endl;
                return;
            }

            std::shared_ptr<PriorityNode<T, C>> currentNode = head;
            while (currentNode != nullptr) {
                std::cout << currentNode->data_ << "->";
                currentNode = currentNode->next;
            }
            std::cout << std::endl;
        }

    };
}