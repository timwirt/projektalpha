#include <../src/LinkedList.cpp>
#include <../src/DoublyLinkedList.cpp>
#include <iostream>

template<class T>
void debug(ProjektAlpha::LinkedList<T>& list) {
    if(!list.is_empty()) {
        std::cout << "First: " << list.get_first() << std::endl;
        std::cout << "Last: " << list.get_back() << std::endl;
        std::cout << "Size: " << list.get_size() << std::endl;
    }
    list.print();
}
template<class T>
void debug(ProjektAlpha::DoublyLinkedList<T>& list) {
    if(!list.is_empty()) {
        std::cout << "First: " << list.get_first() << std::endl;
        std::cout << "Last: " << list.get_back() << std::endl;
        std::cout << "Size: " << list.get_size() << std::endl;
    }
    list.print();
}

void test_linked_list() {
    int first = 7;
    ProjektAlpha::LinkedList<int> list = ProjektAlpha::LinkedList<int>(first);
    debug<int>(list);

    list.add_front(1);
    list.add_front(5);
    auto current = list.add_front(3);
    list.add_after(current, 42);
    list.add_back(11);

    if(list.contains(42)) {
        std::cout << "42 is in list :D" << std::endl;
    }
    debug<int>(list);

    list.remove_after(current);
    list.remove_front();
    list.remove_back();
    debug<int>(list);
}
void test_doubly_linked_list() {
    std::string test = "Hi";
    ProjektAlpha::DoublyLinkedList<std::string> list = ProjektAlpha::DoublyLinkedList<std::string>(test);
    debug<std::string>(list);

    list.add_back("World");
    auto node = list.add_front("Test:");
    list.add_front("Front");
    list.add_after(node, "mid");
    debug<std::string>(list);

    for(auto string : list) {
        std::cout << string << std::endl;
    }

    list.remove_front();
    list.remove_back();
    debug<std::string>(list);
    list.remove(node->next);
    debug<std::string>(list);
    list.remove(node->next);
    debug<std::string>(list);
    list.remove(node);
    debug<std::string>(list);
}

void test_iterators() {
    ProjektAlpha::LinkedList<std::string> list = ProjektAlpha::LinkedList<std::string>((std::string)"Hey,");
    list.add_back("Moin");
    list.add_back("Leute!");
    list.add_back("Ich!");
    list.add_back("Teste!");
    list.add_back("Die!");
    list.add_back("Liste?");
    //list.print();
    debug<std::string>(list);

    /*for(auto it = list.begin(), end = list.end(); it != end; ++it) {
        std::cout << (*it) << std::endl;
    }*/
    for(auto string : list) {
        std::cout << string << std::endl;
    }
}

int main() {
    //test_linked_list();
    test_doubly_linked_list();
    //test_iterators();
}

