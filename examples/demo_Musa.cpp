#include <../src/Queue.cpp>
#include <../src/PriorityQueue.cpp>
#include <iostream>

void test_priorityqueue() {
    std::cout<<"Test PriorityQueue:"<<std::endl;
    ProjektAlpha::PriorityQueue<int, int> pqueue(4,1);
    std::cout<<"Test Insert:"<<std::endl;
    pqueue.insert(1,4);
    pqueue.insert(3,2);
    pqueue.insert(2,3);
    pqueue.printQueue();
    std::cout<<"Test Remove:"<<std::endl;
    pqueue.remove();
    pqueue.printQueue();
    std::cout<<"Test getFirst:"<<std::endl;
    std::cout<<pqueue.get_first()<<std::endl;
    std::cout<<"Test getSize:"<<std::endl;
    std::cout<<pqueue.get_size()<<std::endl;
    std::cout<<"Test isEmpty:"<<std::endl;
    std::cout<<pqueue.is_empty()<<std::endl;
    std::cout<<""<<std::endl;
}
    
void test_queue() {  
    std::cout<<"Test Queue:"<<std::endl;  
    ProjektAlpha::Queue<int> queue(2);
    std::cout<<"Enqueue Test:"<<std::endl;
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.printQueue();
    std::cout<<"Dequeue Test:"<<std::endl;
    queue.dequeue();
    queue.printQueue();
    std::cout<<"isEmpty Test:"<<std::endl;
    std::cout<<queue.is_empty()<<std::endl;
    std::cout<<"getFirst Test:"<<std::endl;
    std::cout<<queue.get_first()<<std::endl;
    std::cout<<"getSize Test:"<<std::endl;
    std::cout<<queue.get_size()<<std::endl;
    std::cout<<""<<std::endl;
}

int main (){
    test_queue();
    test_priorityqueue();
}