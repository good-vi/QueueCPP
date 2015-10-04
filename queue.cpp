#include "queue.h"
#include <iostream>  //cerr stream

Queue::Queue(int initiatingItem)
{
    first = new (QueueItem);
    first->nextAdr = 0;
    last  = first;           //Because one item
    first->value = initiatingItem;
    size = 1;
}

void Queue::enqueue(int value){
    QueueItem *newTmpLast = new(QueueItem);
    newTmpLast->nextAdr = 0;
    newTmpLast->value   = value;

    last->nextAdr = newTmpLast;
    last = newTmpLast;
    size++;
}

int Queue::dequeue(void){
    if(size == 0){
        std::cerr << "dequeue Empty Queue";
        return 1;
    }
    int tmpVal = first->value;
    QueueItem *tmpPointerToFirst = first; // записываем адрес головы
    first=first->nextAdr;             // изменяем адрес головы
    delete tmpPointerToFirst;                 // Delete old First Item
    size--;

    return tmpVal;
}
