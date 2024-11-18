/**
 * @file LinkedList.cpp
 * @author Tim Locke
 * @brief Full implementation of data structure: LinkedList
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <../include/Container/AbstractLinkedList.hpp>
#include <memory>
#include <iostream>
#include <string>

namespace ProjektAlpha {

    /**
     * @brief A list data structure that implements the AbstractLinkedList interface.
     * @tparam T The type of the elements stored in the list.
     */
    template<class T>
    class LinkedList : public AbstractLinkedList<T> {
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
         * @brief Constructs a new empty LinkedList object with default values.
         */
        LinkedList() {
            size = 0;
            head = nullptr;
            tail = nullptr;
        }
        /**
         * @brief Constructs a new LinkedList object with the given input.
         * @param item The item to be added to the LinkedList.
         */
        LinkedList(T& item) {
            size = 1;
            auto temp = std::make_shared<Node<T>>(item);
            head = temp;
            tail = temp;
        }

        /**
         * @brief Gets the size of the LinkedList.
         * @return int The size of the LinkedList.
         */
        int get_size() override {
            return size;
        }
        /**
         * @brief Gets wether the LinkedList is empty.
         * @return bool The logical value wether the LinkedList is empty.
         */
        bool is_empty() override {
            return (size == 0);
        }
        /**
         * @brief Gets the first element in the LinkedList.
         * @return T The first element in the LinkedList.
         */
        T get_first() override {
            if(!head) return NULL;
            return head->data_;
        }
        /**
         * @brief Gets the last element in the LinkedList.
         * @return T The last element in the LinkedList.
         */
        T get_back() override {
            if(!tail) return NULL;
            return tail->data_;
        }

        /**
         * @brief Adds the given item to the head of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        Nodeptr add_front(const T& item) override {
            return add_front(const_cast<T&>(item));
        }
        /**
         * @brief Adds the given item to the head of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        Nodeptr add_front(T& item) override {
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            temp->next = head;
            head = temp;
            if(tail == nullptr) {
                tail = temp;
            }
            return head;
        }
        /**
         * @brief Adds the given item to the tail of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        Nodeptr add_back(const T& item) override {
            return add_back(const_cast<T&>(item));
        }
        /**
         * @brief Adds the given item to the tail of the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        Nodeptr add_back(T& item) override {
            if(is_empty()) {
                return add_front(item);
            }
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            tail->next = temp;
            tail = temp;

            return head;
        }
        /**
         * @brief Adds the given item after a specific Node to the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @param before The Node after which the item will be inserted to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
        Nodeptr add_after(Nodeptr& before, const T& item) override {
            return add_after(before, const_cast<T&>(item));
        }
        /**
         * @brief Adds the given item after a specific Node to the LinkedList.
         * @param item The item to be added to the LinkedList.
         * @param before The Node after which the item will be inserted to the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		Nodeptr add_after(Nodeptr& before, T& item) override {
            if(before == nullptr) return head;
            size++;
            auto temp = std::make_shared<Node<T>>(item);
            temp->next = before->next;
            before->next = temp;

            return head;
        }
        /**
         * @brief Gets wether the item is contained in the LinkedList.
         * @return bool The logical value wether the item is contained in the LinkedList.
         */
        bool contains(const T& input) override {
            return contains(const_cast<T&>(input));
        }
        /**
         * @brief Gets wether the item is contained in the LinkedList.
         * @return bool The logical value wether the item is contained in the LinkedList.
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
         * @brief Removes the first item in the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		Nodeptr remove_front() override {
            if(head == nullptr) return head;
            size--;
            head = head->next;
            return head;
        }
        /**
         * @brief Removes the last item in the LinkedList.
         * @return Nodeptr The new head of the LinkedList.
         */
		Nodeptr remove_back() override {//Hopefully This Works
            auto ptr = nullptr;
            for(auto current = head->next; current != nullptr; current=current->next) {
                if(current == nullptr) return head;
                if(current->next == nullptr) {
                    tail = nullptr;
                    head = nullptr;
                    size--;
                    return head;
                }
                if(current->next->next == nullptr) {
                    current->next = nullptr;
                    tail = current;
                    size--;
                    return head;
                }
            }
            return head;
        }
        /**
         * @brief Removes the item after the specified Node in the LinkedList.
         * @param before The item after which the next element will be deleted.
         * @return Nodeptr The new head of the LinkedList.
         */
		Nodeptr remove_after(Nodeptr& before) override {
            if(before == nullptr || before->next == nullptr) return head;
            before->next = before->next->next;
            size--;
            return head;
        }

        /**
         * @brief Prints all elements in the LinkedList to the console.
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