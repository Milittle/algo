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

        SingleNode<T> * node = head_;
        SingleNode<T> * node_next = head_->next;
        SingleNode<T> * tmp;
        while(node_next != head_){
            tmp = node_next->next;
            node_next->next = node;
            node = node_next;
            node_next = tmp;
        }

        node_next->next = node;
        head_ = node_next;
    }

} // namespace algo

#endif //ALGO_SINGLERINGLIST_H
