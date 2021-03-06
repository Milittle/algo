//
// Created by milittle on 2019-01-31.
//

#ifndef ALGO_SINGLERINGLIST_H
#define ALGO_SINGLERINGLIST_H

#include "../SingleList/SingleList.h"

namespace algo{

    template <typename T>
    class SingleRingList {
    public:
        typedef T value_type;

        SingleRingList():head_(nullptr), size_(0){}
        ~SingleRingList(){}

        void insert_to_head(T value);
        void insert_to_tail(T value);

        SingleNode<T> * search(T value);

        SingleNode<T> * get_head(){return head_;}
        size_t size(){return size_;}

        void reverse();

    private:
        algo::SingleNode<T> * head_;
        algo::SingleNode<T> * tail_;
        size_t size_;
    };

    template <typename T>
    void SingleRingList<T>::insert_to_head(T value) {
        SingleNode<T> *node;
        node->value = value;
        if (size_ == 0){
            tail_ = node;
            head_ = node;
            tail_->next = head_;
        }else{
            tail_->next = node;
            node->next = head_;
            head_ = node;
        }

        size_++;
    }

    template <typename T>
    void SingleRingList<T>::insert_to_tail(T value){
        SingleNode<T> * node;
        node->value = value;
        if (size_ == 0){
            tail_ = node;
            head_ = node;
            tail_->next = head_;
        }else{
            tail_->next = node;
            tail_ = node;
            node->next = head_;
        }

        size_++;
    }

    template <typename T>
    SingleNode<T> * SingleRingList<T>::search(T value) {
        SingleNode<T> * node = head_;

        while (node && node != tail_){
            if (node->value == value)
                return node;
            node = node->next;
        }

        if (node == tail_ && node->value == value){
            return node;
        }else{
            return nullptr;
        }
    }

    template <typename T>
    void SingleRingList<T>::reverse() {

        if(!head_ || size_ == 1)
            return;

        SingleNode<T> * pre = head_;
        SingleNode<T> * cur = head_->next;
        SingleNode<T> * tmp;
        while(cur != head_){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        cur->next = pre;
        head_ = cur;
    }

} // namespace algo

#endif //ALGO_SINGLERINGLIST_H
