/**
 * @file Queue.cpp
 * @author E. Musa
 * @brief Full implementation of data structure: Queue
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <Container/AbstractQueue.hpp>
#include <iostream>

namespace ProjektAlpha{
    /**
     * @brief A Queue data structure that implements the AbstractQueue interface.
     * @tparam T The type of the elements stored in the Queue.
     */
    template<typename T>
        class Queue : public AbstractQueue<T>{
        private:
            std::shared_ptr<Node<T>> head;
            int size;
        public:
            /**
            * @brief Constructs a new empty Queue.
            */
            Queue(){
                size=0;
                head=nullptr;
            }
            /**
            * @brief Constructs a new Queue object with the given input.
            * @param item The item to be added to the Queue.
            */
            Queue(T item){
                size=1;
                std::shared_ptr<Node<T>> current = std::make_shared<Node<T>> (item);
                head=current;
                head->next=nullptr;
            }
            /**
            * @brief Inserts the given Item to the end of the Queue.
            * @param item The item to be added to the Queue.
            */
            void enqueue(T item){
                size++;
                std::shared_ptr<Node<T>> current = std::make_shared<Node<T>> (item);
                if(head==nullptr){
                    head=current;
                    return;
                } 
                std::shared_ptr<Node<T>> lastItem;           
                lastItem=head;
                while (lastItem->next != nullptr) {
                    lastItem=lastItem->next;
                }
                lastItem->next=current;
            }
            /**
            * @brief Removes the first item from the Queue.
            * @return T: The item to that was removed from the Queue.
            */
            T dequeue(){
                size--;
                if (head == nullptr) {
                    size=0;
                    return NULL;
                }
                head = head->next;
                return head->data_;
            }
            /**
            * @brief Gets the first item of the Queue
            * @return T: The first Item
            */ 
            T get_first(){
                if(head==nullptr){
                    return NULL;
                }
                return head->data_;
            }
            /**
             * @brief Gets whether the Queue is empty
             * @return bool: True if empty; False if not empty
             */
            bool is_empty(){
                if(head==nullptr){
                    return true;
                }
                return false;
            }
            /**
             * @brief Gets the size of the Queue
             * @return int: The size of the Queue
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
                std::shared_ptr<Node<T>> currentNode = head;
                while (currentNode != nullptr) {
                    std::cout << currentNode->data_ << "->";
                    currentNode = currentNode->next;
                }
                std::cout << std::endl;
            }
        };
}