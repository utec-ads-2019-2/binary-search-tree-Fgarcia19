cmake_minimum_required(VERSION 3.13)
project(BST)

set(CMAKE_CXX_STANDARD 14)

add_executable(BST main.cpp bstree.h iterator.h node.h mocker.cpp mocker.h tester.cpp tester.h)