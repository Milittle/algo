//
// Created by milittle on 2019-02-07.
//

#ifndef ALGO_BLOCKQUEUE_H
#define ALGO_BLOCKQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

namespace algo{

    template <typename T>
    class BlockQueue {
        typedef std::unique_lock<std::mutex> TLock;
        typedef std::deque<T> TQueue;

    public:

        BlockQueue(int maxCap = -1){
            _maxCap = maxCap;
        }

        ~BlockQueue(){}

        void enqueue(T value);
        T dequeue();

        bool empty();
        bool full();

    private:

        bool hasCap(){
            return _maxCap > 0;
        }

        TQueue _queue;

        int _maxCap;

        std::condition_variable _empty_cond;
        std::condition_variable _full_cond;
        std::mutex _mutex;
    };


    template <typename T>
    void BlockQueue<T>::enqueue(T value) {

        TLock lock(_mutex);

        if(true == hasCap()){
            while(_queue.size() >= _maxCap){
                _full_cond.wait(lock);
            }
        }

        _queue.push_back(value);
        _empty_cond.notify_all();
    }

    template <typename T>
    T BlockQueue<T>::dequeue() {
        TLock lock(_mutex);
        while(_queue.empty()){
            _empty_cond.wait(lock);
        }

        T tmp = *_queue.begin();
        _queue.pop_front();

        _full_cond.notify_all();

        return tmp;
    }

    template <typename T>
    bool BlockQueue<T>::empty() {
        TLock lock(_mutex);
        return _queue.empty();
    }

    template <typename T>
    bool BlockQueue<T>::full() {

        if ( false == hasCap()){
            return false;
        }

        TLock lock(_mutex);
        return _queue.size() >= _maxCap;
    }
}


#endif //ALGO_BLOCKQUEUE_H
