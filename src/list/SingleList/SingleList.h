//
// Created by milittle on 2019-01-27.
//


#ifndef ALGO_SINGLELIST_H
#define ALGO_SINGLELIST_H

#include <cstdio>

namespace algo{

    //T need to support the coping constructed func and assigning constructed func
    template <typename T>
    struct SingleNode{
        T value;
        SingleNode * next;
    };

    template <typename T>
    class SingleList{
    public:
        typedef T value_type;
        SingleList():head_(nullptr), size_(0){}
        ~SingleList(){release();}

        void insert_to_head(T value);
        void insert_to_tail(T value);
        void insert_to_node(SingleNode<T> * node, T value);

        void delete_node(T value);

        SingleNode<T> * search_by_value(T value);

        SingleNode<T> * get_head(){return head_;}

        void release();

        size_t size(){
            return size_;
        }
        void operator++(){
            size_++;
        }
        void operator--(){
            size_--;
        }

        void reverse();

    private:
        SingleNode<T> * head_;
        size_t  size_;
    };

    template<typename T>
    void SingleList<T>::insert_to_head(T value) {

        if (!head_) {
            head_ = new SingleNode<T>();
            head_->value = value;
            head_->next = nullptr;
        } else {
            SingleNode<T> *newNode = new SingleNode<T>();
            newNode->value = value;
            newNode->next = head_;
            head_ = newNode;
        }

        size_++;
    }

    template<typename T>
    void SingleList<T>::insert_to_tail(T value) {

        SingleNode<T> *node = head_;

        while (node->next) {
            node = node->next;
        }

        SingleNode<T> *newNode = new SingleNode<T>();
        newNode->value = value;
        newNode->next = nullptr;
        node->next = newNode;

        size_++;
    }

    template<typename T>
    void SingleList<T>::insert_to_node(SingleNode<T> *node, T value) {

        if (!head_ || !node)
            return;
        SingleNode<T> *node_h = head_;
        while (node_h->value != node->value) {
            node_h = node_h->next;
        }

        SingleNode<T> *newNode = new SingleNode<T>();
        newNode->value = value;
        newNode->next = node_h->next;
        node_h->next = newNode;

        size_++;
    }

    template<typename T>
    void SingleList<T>::delete_node(T value) {

        if (!head_)
            return;

        SingleNode<T> *node_h = head_;

        SingleNode<T> *node_hh;
        while (node_h && node_h->value != value) {
            node_hh = node_h;
            node_h = node_h->next;
        }

        if (node_h){
            node_hh->next = node_h->next;
            delete node_h;
            size_--;
        }
    }

    template <typename T>
    SingleNode<T> * SingleList<T>::search_by_value(T value) {
        SingleNode<T> * node = head_;

        while(node && node->value != value)
        {
            node = node->next;
        }

        return node;
    }

    template <typename T>
    void SingleList<T>::release() {

        SingleNode<T> *node;

        while (head_) {
            node = head_->next;
            delete head_;
            head_ = node;
        }

        size_ = 0;
    }

    template <typename T>
    void SingleList<T>::reverse() {

        if ( !head_ || size_ == 1)
            return;

        SingleNode<T> * pre = head_;
        SingleNode<T> * cur = head_->next;
        head_->next = nullptr;
        SingleNode<T> * tmp;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head_ = pre;
    }

}// namespace algo

#endif //ALGO_SINGLELIST_H
