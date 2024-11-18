/**
 * @file DoublyLinkedList.cpp
 * @author Tim Locke
 * @brief Full implementation of data structure: DoublyLinkedList
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <../include/Container/AbstractDoublyLinkedList.hpp>
#include <memory>
#include <iostream>
#include <string>

namespace ProjektAlpha {

    /**
     * @brief A list data structure that implements the AbstractDoublyLinkedList interface.
     * @tparam T The type of the elements stored in the list.
     */
    template<class T>
    class DoublyLinkedList : public AbstractDoublyLinkedList<T> {
    private:
        int size;
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;

        template<typename T>
        std::string string(T& input) {
            return std::to_string(input);
        }
        std::string string(std::string& input) {
            return input;
        }
    public:
        /**
         * @brief Constructs a new empty DoublyLinkedList object with default values.
         */
        DoublyLinkedList() {
            size = 0;
            head = nullptr;
            tail = nullptr;
        }
        /**
         * @brief Constructs a new DoublyLinkedList object with the given input.
         * @param item The item to be added to the DoublyLinkedList.
         */
        DoublyLinkedList(T& item) {
            size = 1;
            auto temp = std::make_shared<Node<T>>(item);
            head = temp;
            tail = temp;
        }

        /**
         * @brief Gets the size of the DoublyLinkedList.
         * @return int The size of the DoublyLinkedList.
         */
        int get_size() override {
            return size;
        }
        /**
         * @brief Gets wether the DoublyLinkedList is empty.
         * @return bool The logical value wether the DoublyLinkedList is empty.
         */
        bool is_empty() override {
            return (size == 0);
        }
        /**
         * @brief Gets the first element in the DoublyLinkedList.
         * @return T The first element in the DoublyLinkedList.
         */
        T get_first() override {
            if(!head) return NULL;
            return head->data_;
        }
        /**
         * @brief Gets the last element in the DoublyLinkedList.
         * @return T The last element in the DoublyLinkedList.
         */
        T get_back() override {
            if(!tail) return NULL;
            return tail->data_;
        }

        /**
         * @brief Adds the given item to the head of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        Nodeptr add_front(const T& item) override {
            return add_front(const_cast<T&>(item));
        }
        /**
         * @brief Adds the given item to the head of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        Nodeptr add_front(T& item) override {
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            head->prev = temp;
            temp->next = head;
            head = temp;
            if(tail == nullptr) {
                tail = temp;
            }
            return head;
        }
        /**
         * @brief Adds the given item to the tail of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        Nodeptr add_back(const T& item) override {
            return add_back(const_cast<T&>(item));
        }
        /**
         * @brief Adds the given item to the tail of the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		Nodeptr add_back(T& item) override {
            if(is_empty()) {
                return add_front(item);
            }
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;

            return head;
        }
        /**
         * @brief Adds the given item after a specific Node to the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @param before The Node after which the item will be inserted to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
        Nodeptr add_after(Nodeptr& before, const T& item) override {
            return add_after(before, const_cast<T&>(item));
        }
        /**
         * @brief Adds the given item after a specific Node to the DoublyLinkedList.
         * @param item The item to be added to the DoublyLinkedList.
         * @param before The Node after which the item will be inserted to the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		Nodeptr add_after(Nodeptr& before, T& item) override {
            if(before == nullptr) return head;
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            temp->next = before->next;
            before->prev = temp;
            temp->prev = before;
            before->next = temp;

            return head;
        }
        /**
         * @brief Gets wether the item is contained in the DoublyLinkedList.
         * @return bool The logical value wether the item is contained in the DoublyLinkedList.
         */
        bool contains(const T& input) override {
            return contains(const_cast<T&>(input));
        }
        /**
         * @brief Gets wether the item is contained in the DoublyLinkedList.
         * @return bool The logical value wether the item is contained in the DoublyLinkedList.
         */
		bool contains(T& input) override {
            for(auto current = head; current != nullptr; current=current->next) {
                if(current->data_ == input) {
                    return true;
                }
            }
            return false;
        }
        /**
         * @brief Removes the first item in the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		Nodeptr remove_front() override {
            if(head == nullptr) return head;
            head = head->next;
            size--;
            return head;
        }
        /**
         * @brief Removes the last item in the DoublyLinkedList.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		Nodeptr remove_back() override {
            if(tail == nullptr) return head;
            auto previous = tail->prev.lock();
            if(previous == nullptr) return head;
            previous->next = nullptr;
            tail = previous;
            size--;
            return head;
        }
        /**
         * @brief Removes the specified Node in the DoublyLinkedList.
         * @param toRemove The Node which will be deleted.
         * @return Nodeptr The new head of the DoublyLinkedList.
         */
		Nodeptr remove(Nodeptr& toRemove) override {
            if(toRemove == nullptr) return head;
            auto previous = toRemove->prev.lock();
            if(previous == nullptr) {// toRemove is the head of the list
                remove_front();
            } else if(toRemove->next == nullptr) {// toRemove is the tail of the list
                remove_back();
            } else {// toRemove is somewhere inside the list
                size--;
                toRemove->next->prev = previous;
                previous->next = toRemove->next;
            }
            return head;
        }
		
        /**
         * @brief Prints all elements in the DoublyLinkedList to the console.
         */
        void print() override {
            if(is_empty()) {
                std::cout << "List: []" << std::endl;
                return;
            }
            std::string result = "List: [ " + string(head->data_);
            for(auto current = head->next; current != nullptr; current=current->next) {
                result += " -> " + string(current->data_);
            }
            std::cout << result << " ]" << std::endl;
        }

        //Iterator-Things for the For-Each-Loops
        class Iterator : public std::iterator<
                        std::forward_iterator_tag,   // iterator_category
                        T,                           // value_type
                        std::ptrdiff_t,              // difference_type
                        const T*,                    // pointer
                        T&                           // reference
                        >{
            std::shared_ptr<Node<T>> node;
        public:
            Iterator(std::shared_ptr<Node<T>>& node_) { node = node_; }
            Iterator& operator ++ () { node = node->next; return *this; }
            Iterator operator ++ (int) { Iterator temp = *this; ++(*this); return temp; }
            friend bool operator == (Iterator& a, Iterator& other) { return a.node == other.node; }
            friend bool operator != (Iterator& a, Iterator& other) { return a.node != other.node; }
            T operator* () const { return node->data_; }
            T operator->() { return node->data-; }
        };
        
        Iterator begin() {
            return Iterator(head);
        }
        Iterator end() {
            return (Iterator((std::shared_ptr<Node<T>>)nullptr));
        }
    };
}