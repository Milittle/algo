#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "list/SingleList/SingleList.h"
#include "list/JosephP.cpp"
#include "test/sample/sample1unittest.cpp"
#include "stack/ArrayStack.h"
#include "queue/ArrayQueue.h"
#include "sort/Sort.h"
#include "bsearch/bsearch.h"

int main(int argc, char ** argv) {

    testing::InitGoogleTest(&argc, argv);

    int a[] = {2, 5, 3, 7, 1, 4, 3, 1};

    //algo::Sort().bubble_sort(a, 8);
    //algo::Sort().insertion_sort(a, 8);
    //algo::Sort().selection_sort(a, 8);
    //algo::Sort().merge_sort(a, 8);
    algo::Sort().quick_sort(a, 8);
    for (auto i:a){
        std::cout << i << std::endl;
    }

    return RUN_ALL_TESTS();
}