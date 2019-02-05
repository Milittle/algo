//
// Created by milittle on 2019-02-05.
//

#include "ListStack.h"

void forward(algo::ListStack<int> * listStack1, algo::ListStack<int> * listStack2){
    if (listStack1->size() == 0)
        return;

    listStack2->push(listStack1->pop());
}


void backward(algo::ListStack<int> * listStack1, algo::ListStack<int> * listStack2){
    if (listStack2->size() == 0)
        return;

    listStack1->push(listStack2->pop());
}
