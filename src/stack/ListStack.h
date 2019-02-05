//
// Created by milittle on 2019-02-05.
//

#ifndef ALGO_LISTSTACK_H
#define ALGO_LISTSTACK_H

#include <cstddef>

namespace algo{

    template <typename T>
    struct ListNode{
        T value;
        ListNode * next;
    };

    template <typename T>
    class ListStack {

        typedef T value_type;
    public:
        ListStack():head_(nullptr), size_(0){}
        ~ListStack(){}

        size_t push(value_type value); // no limitation
        value_type pop();

        size_t size(){
            return size_;
        }

    private:
        ListNode<value_type> * head_;
        size_t size_;
    };

    template <typename T>
    size_t ListStack<T>::push(value_type value) {
        ListNode<T> * node = new ListNode<T>();
        node->value = value;

        node->next = head_;
        head_ = node;
        return ++size_;
    }

    template <typename T>
    T ListStack<T>::pop() {
        if ( size_ == 0)
            return T();

        T val = head_->value;

        ListNode<T> * node = head_;

        head_ = head_->next;

        delete node;

        return val;
    }
}



#endif //ALGO_LISTSTACK_H
