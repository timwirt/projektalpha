/**
 * @file Stack.cpp
 * @author T. Wirtz
 * @brief Full implementation of data structure: Stack
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <../include/Container/AbstractStack.hpp>
#include <iostream>
#include <string>

namespace ProjektAlpha {

    class StackException : public std::runtime_error {
        public:
            explicit StackException(const std::string& message) : std::runtime_error(message) {}
    };

    /**
     * @brief A stack data structure that implements the AbstractStack interface
     * 
     * @tparam T The type of the elements stored in the stack
     */
    template <typename T>
    class Stack : public AbstractStack<T> {

    public:
        /**
         * @brief Construct a new Stack object with default values
         * 
         */
        Stack() {
            size = 0;
            head = nullptr;
        }

        /**
         * @brief Construct a new Stack object with a single item
         * 
         * @param item The item to be added to the stack
         */
        Stack(T& item) {
            size = 1;
            head = std::make_shared<Node<T>>(item);
        }

        /**
         * @brief Pushes an item to the top of the stack.
         * 
         * @param item The item to be added to the stack.
         */
        void push(T item) override{
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            temp->next = head;
            head = temp;
        }

        /**
         * @brief Removes the top item from the stack and returns it.
         * 
         * @return T The top item of the stack.
         */
        T pop() override {
            if(is_empty()) {
                throw StackException("Stack is empty");
            }
            size--;
            auto temp = head;
            head = head->next;
            return temp->data_;
        }

        // Override methods from Container

        /**
         * @brief Gets the size of the stack
         * 
         * @return int The size of the stack
         */
        int get_size() override {
            return size;
        }

        /**
         * @brief Checks whether the stack is empty
         * 
         * @return true if the stack is empty, false otherwise
         */
        bool is_empty() override {
            return (size == 0);
        }

        /**
         * @brief Gets the first element of the stack
         * 
         * @return T The first element of the stack
         */
        T get_first() override {
            if(is_empty()) {
                throw StackException("Stack is empty");
            }
            return head->data_;
        }

        /**
         * @brief Prints the contents of the stack.
         */
        void print() override {
            if(is_empty()) {
                std::cout << "Stack: []" << std::endl;
                return;
            }

            std::string result = "Stack: [ " + string(head->data_);
            for(auto current = head->next; current != nullptr; current=current->next) {
                result += ", " + string(current->data_);
            }

            std::cout << result << " ]" << std::endl;

        }
        
        private:
            std::shared_ptr<Node<T>> head;
            int size;

            template<typename T>
            std::string string(T& input) {
                return std::to_string(input);
            }
            std::string string(std::string& input) {
                return input;
            }
    };
}