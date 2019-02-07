//
// Created by milittle on 2019-02-06.
//

#ifndef ALGO_ARRAYQUEUE_H
#define ALGO_ARRAYQUEUE_H

#include <cstddef>

namespace algo{

    class ArrayQueue {
    public:
        ArrayQueue(size_t n):head(0), tail(0){
            items = new int[n];
            this->n = n;
        }
        ~ArrayQueue(){
            delete items;
        }

        int enqueue(int val);
        int dequeue();

    private:
        int * items;

        size_t n;

        size_t head;
        size_t tail;
    };

    int ArrayQueue::enqueue(int val) {

        if ( head == tail){
            head = tail = 0;
        }

        if ( head != 0 && tail == n){
            for (int i = head; i < tail; ++i){
                items[i - head] = items[i];
            }
        }

        if (head == 0 && tail == n){
            int * new_items = new int[n * 1.5];

            for ( int i = head; i < tail; ++i){
                new_items[i] = items[i];
            }

            delete items;
            items = new_items;
            n = n * 1.5;
        }

        items[tail++] = val;
        return tail - head;
    }

    int ArrayQueue::dequeue() {
        if (head == tail)
            return -1;

        return items[head++];
    }
}




#endif //ALGO_ARRAYQUEUE_H
