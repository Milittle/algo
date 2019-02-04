//
// Created by milittle on 2019-02-02.
//
#include "SingleList/SingleList.h"

namespace {

    // list reverse
    void listReverse(algo::SingleList<int> * list){
        algo::SingleNode<int> * head = list->get_head();

        if (!head || list->size() == 1)
            return;

        algo::SingleNode<int> * pre = head;
        algo::SingleNode<int> * cur = head->next;
        algo::SingleNode<int> * tmp;
        head->next = nullptr;

        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head = pre;
    }

    // check the list have not Ring.
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

    //get the list mid node
    algo::SingleNode<int> * get_mid_node(algo::SingleList<int> * list){
        if (!list->get_head())
            return nullptr;

        if (list->size() == 1)
            return list->get_head();

        algo::SingleNode<int> * fast = list->get_head();
        algo::SingleNode<int> * slow = list->get_head();

        while (fast->next && slow->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
}

