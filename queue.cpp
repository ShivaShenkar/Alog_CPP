//fikhman2005@gmail.com
#include "queue.hpp"
#include <iostream>


Queue::Queue(int maxSize) {
    this->CurrSize = 0;
    this->front = 0;
    this->qArr= new int[maxSize];
    this->maxSize = maxSize;
}
Queue::~Queue() {
    delete[] qArr;
}
void Queue::enqueue(int value) {
    qArr[(front+CurrSize)%maxSize] = value;
    CurrSize++;
}
int Queue::dequeue(){
    if(CurrSize == 0) {
        throw std::out_of_range("Queue is empty");
    }
    int pop = qArr[front];
    front = (front+1)%maxSize;
    CurrSize--;
    return pop;
}
bool Queue::isEmpty() {
    return CurrSize == 0;
}