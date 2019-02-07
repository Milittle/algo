#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "list/SingleList/SingleList.h"
#include "list/JosephP.cpp"
#include "test/sample/sample1unittest.cpp"
#include "stack/ArrayStack.h"
#include "queue/ArrayQueue.h"

int main(int argc, char ** argv) {

    testing::InitGoogleTest(&argc, argv);

    algo::ArrayQueue queue(2);

    std::cout << queue.enqueue(1) << std::endl;
    std::cout << queue.enqueue(2) << std::endl;
    std::cout << queue.enqueue(3) << std::endl;
    std::cout << queue.enqueue(4) << std::endl;

    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;


    std::cout << queue.enqueue(1) << std::endl;
    std::cout << queue.enqueue(2) << std::endl;


    return RUN_ALL_TESTS();
}