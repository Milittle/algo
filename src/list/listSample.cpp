//
// Created by milittle on 2019-02-02.
//
#include "SingleList/SingleList.h"

namespace {

    // list reverse
    template <typename T>
    algo::SingleNode<T> * listReverse(algo::SingleList<T> * list){
        algo::SingleNode<T> * head = list->get_head();

        if (!head || list->size() == 1)
            return head;

        algo::SingleNode<T> * pre = head;
        algo::SingleNode<T> * cur = head->next;
        algo::SingleNode<T> * tmp;
        head->next = nullptr;

        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head = pre;
        
        return head;
    }

    // check the list have not Ring.
    bool isRingList(algo::SingleList<int> * list){
        algo::SingleNode<algo::SingleList<int>::value_type> * fast = list->get_head();
        algo::SingleNode<algo::SingleList<int>::value_type> * slow = list->get_head();

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }

    //merge the two ordered list
    algo::SingleList<int> * mergeList(algo::SingleList<int> * list1, algo::SingleList<int> * list2){
        typedef int value_type;
        algo::SingleList<int> * l;
        algo::SingleNode<int> * head = l->get_head();

        algo::SingleNode<int> * head1 = list1->get_head();
        algo::SingleNode<int> * head2 = list2->get_head();

        while(head1 || head2){
            if (head1 && head2){
                if (head1->value < head2->value){
                    head = head1;
                    head1 = head1->next;
                    l++;
                }else{
                    head = head2;
                    head2 = head2->next;
                    l++;
                }
            }else if (head1 && !head2){
                head = head1;
                l++;
                break;
            }else if (head2 && !head1){
                head = head2;
                l++;
                break;
            }
        }

        return l;
    }

    //delete the counts backwards 'n'
    void delete_n_node(algo::SingleList<int> * list, size_t n){
        listReverse(list); // reverse the list
        if ( list->size() > n ){
            algo::SingleNode<int> * pre = list->get_head();
            algo::SingleNode<int> * cur;
            for (size_t i = 1; i < n - 1; ++i){
                pre = pre->next;
            }

            // begin delete the cur node
            cur = pre->next;

            pre->next = pre->next->next;

            list--;

            delete cur;
        }
    }

    // get the list mid node
    // odd number, return the mid node
    // even number, return the last one
    algo::SingleNode<int> * get_mid_node(algo::SingleList<int> * list){

        algo::SingleNode<int> * fast = list->get_head();
        algo::SingleNode<int> * slow = list->get_head();

        while (fast && fast->next) { // fast ptr ans slow ptr condition
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
}

