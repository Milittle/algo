//
// Created by milittle on 2019-02-05.
//

#ifndef ALGO_ARRAYSTACK_H
#define ALGO_ARRAYSTACK_H

#include <cstddef>

namespace algo{

    template <typename T>
    class ArrayStack {
        typedef T value_type;
    public:
        ArrayStack(size_t n){
            val = new value_type[n];
            this->n = n;
            this->count = 0;
        }
        ~ArrayStack(){
            delete val;
        }

        size_t push(value_type value);
        value_type pop();

        size_t size(){
            return count;
        }
    private:
        value_type * val;
        size_t count; //the element count
        size_t n; // the array size
    };

    template <typename T>
    size_t ArrayStack<T>::push(T value) {
        if (count == n)
        {
            T * new_val = new T[n * 1.5];

            for(int i = 0; i < n; ++i){
                new_val[i] = val[i];
            }
            n = n * 1.5;

            delete val;
            val = new_val;
        }
        val[count] = value;
        return ++count;
    }

    template <typename T>
    T ArrayStack<T>::pop() {
        if (count == 0)
            return T(-1);

        return val[--count];
    }
}

#endif //ALGO_ARRAYSTACK_H
