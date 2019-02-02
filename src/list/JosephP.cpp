//
// Created by milittle on 2019-02-01.
//

#include <iostream>
using namespace std;

template <typename T>
struct _LinkNode {
    T value;
    struct _LinkNode* next;
};

typedef _LinkNode<int> LinkNode;
typedef _LinkNode<int> *LinkNodePtr;

LinkNodePtr createCycle(int total) {
    int index = 1;
    LinkNodePtr head = NULL, curr = NULL, prev = NULL;
    head = (LinkNodePtr) malloc(sizeof(LinkNode));
    head->value = index;
    prev = head;

    while (--total > 0) {
        curr = (LinkNodePtr) malloc(sizeof(LinkNode));
        curr->value = ++index;
        prev->next = curr;
        prev = curr;
    }
    curr->next = head;
    return head;
}

void run(int total, int tag) {
    LinkNodePtr node = createCycle(total);
    LinkNodePtr prev = NULL;
    int start = 1;
    int index = start;
    while (node && node->next) {
        if (index == tag) {
            printf("\n%d", node->value);
            if (tag == start) {
                prev = node->next;
                node->next = NULL;
                node = prev;
            } else {
                prev->next = node->next;
                node->next = NULL;
                node = prev->next;
            }
            index = start;
        } else {
            prev = node;
            node = node->next;
            index++;
        }
    }
}

