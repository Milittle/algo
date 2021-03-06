cmake_minimum_required(VERSION 3.13)
project(algo)

set(CMAKE_CXX_STANDARD 17)

# add the gtest include header files and lib files
set(GTEST_INC_DIR ${PROJECT_SOURCE_DIR}/3rdparty/gtest/include)
set(GTEST_LINK_DIR ${PROJECT_SOURCE_DIR}/3rdparty/gtest/lib)
include_directories(${GTEST_INC_DIR})
link_directories(${GTEST_LINK_DIR})
link_libraries(gtest)


add_library(SingleList SHARED src/list/SingleList/SingleList.cpp)
add_library(DoubleList SHARED src/list/DoubleList/DoubleList.cpp)
add_library(SingleRingList SHARED src/list/SingleRingList/SingleRingList.cpp)
add_library(Joseph SHARED src/list/JosephP.cpp)
add_library(sample1 src/sample/sample1.cpp)
add_library(listSample src/list/listSample.cpp)
add_library(arrayStack src/stack/ArrayStack.cpp)
add_library(listStack src/stack/ListStack.cpp)
add_library(forward_backward_based_stack src/stack/forward_backward_based_stack.cpp)
add_library(arrayQueue src/queue/ArrayQueue.cpp)
add_library(blockQueue src/queue/BlockQueue.cpp)

# the sample1unittest library
add_library(sample1unittest src/test/sample/sample1unittest.cpp)

add_executable(algo src/main.cpp)

target_link_libraries(algo
        SingleList DoubleList SingleRingList gtest sample1 sample1unittest listSample
        arrayStack listStack forward_backward_based_stack
        arrayQueue blockQueue)