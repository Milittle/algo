//
// Created by milittle on 2019-01-28.
//

#ifndef ALGO_DOUBLELIST_H
#define ALGO_DOUBLELIST_H

#include <cstdio>

namespace algo{
    template <typename T>
    struct DoubleNode{
        T value;
        DoubleNode * pre;
        DoubleNode * next;
    };

    template <typename T>
    class DoubleList {
    public:
        typedef T value_type;

        DoubleList():head_(nullptr), tail_(nullptr), size_(0){}
        ~DoubleList(){}

        void insert_to_head(value_type value);
        void insert_to_tail(value_type value);
        int insert_to_node(DoubleNode<value_type> * node, value_type value); // default 0 is success

        int delete_node(value_type value);

        DoubleNode<value_type> * search_by_value(value_type value);

        DoubleNode<value_type> * get_head();
        DoubleNode<value_type> * get_tail();

        void release();

        void reverse();

        size_t size(){
            return size_;
        }

    private:
        DoubleNode<value_type> * head_;
        DoubleNode<value_type> * tail_;
        size_t size_;
    };

    template <typename T>
    void DoubleList<T>::insert_to_head(value_type value) {
        DoubleNode<T> * node;
        node->value = value;
        node->pre = nullptr;
        node->next = nullptr;

        if(size_ == 0){
            head_ = node;
            tail_ = node;
        }else{
            head_->pre = node;
            node->next = head_;
            head_ = node;
        }
        size_++;
    }

    template <typename T>
    void DoubleList<T>::insert_to_tail(value_type value) {
        DoubleNode<T> * node;
        node->value = value;
        node->pre = nullptr;
        node->next = nullptr;

        if(size_ == 0){
            head_ = node;
            tail_ = node;
        }else{
            tail_->pre = node;
            node->next = tail_;
            tail_ = node;
        }
        size_++;
    }

    template <typename T>
    int DoubleList<T>::insert_to_node(algo::DoubleNode<value_type> * node, value_type value) {
        if (!node)
            return -1;

        DoubleNode<T> * insert_node;
        insert_node->value = value;
        insert_node->pre = nullptr;
        insert_node->next = nullptr;

        if (node == tail_){
            node->next = insert_node;
            insert_node->pre = node;
            tail_ = insert_node;
        }else{
            insert_node->next = node->next;
            insert_node->pre = node;
            node->next = insert_node;
        }
        size_++;

        return 0;
    }

    template <typename T>
    int DoubleList<T>::delete_node(value_type value) {

        DoubleNode<T> * del_node = search_by_value(value);

        if (!del_node)
            return -1;

        if (size_ == 1){
            if (del_node == head_){
                head_ = nullptr;
                tail_ = nullptr;
                delete del_node;
            }else{
                return -1;
            }
        }else if(del_node == tail_){
            del_node->pre->next = nullptr;
            tail_ = del_node->pre;
            delete del_node;
        }else if(del_node == head_){
            del_node->next->pre = nullptr;
            head_ = del_node->next;
            delete del_node;
        }else{
            del_node->pre->next = del_node->next;
            del_node->pre->next->pre = del_node->pre;
            delete del_node;
        }
        return 0;
    }

    template <typename T>
    DoubleNode<T> * DoubleList<T>::search_by_value(value_type value) {
       DoubleNode<T> * node = head_;
       while(node){
            if(node->value == value){
                return node;
            }
            else{
                node = node->next;
            }
       }
       return node;
    }

    template <typename T>
    DoubleNode<T> * DoubleList<T>::get_head() {
        return head_;
    }

    template <typename T>
    DoubleNode<T> * DoubleList<T>::get_tail() {
        return tail_;
    }

    template <typename T>
    void DoubleList<T>::release() {

        DoubleNode<T> * node;
        while (head_){
            node = head_->next;
            delete head_;
            head_ = node;
        }

        tail_ = nullptr;
        size_ = 0;
    }

    template <typename T>
    void DoubleList<T>::reverse(){
        DoubleNode<T> * node = head_;
        head_ = tail_;
        tail_ = node;
    }
}// namespace algo

#endif //ALGO_DOUBLELIST_H
