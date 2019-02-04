//
// Created by milittle on 2019-02-02.
//
#include "SingleList/SingleList.h"

namespace {

    template <typename T>
    bool isRingList(algo::SingleList<int> * list){
        algo::SingleNode<algo::SingleList<int>::value_type> * fast = list->get_head();
        algo::SingleNode<algo::SingleList<int>::value_type> * slow = list->get_head();

        while(slow && fast){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
}

