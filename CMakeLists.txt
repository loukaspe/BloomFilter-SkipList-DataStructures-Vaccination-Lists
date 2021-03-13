cmake_minimum_required(VERSION 3.16)
project(ergasia1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ergasia1 main.cpp BitArray/BitArray.cpp BitArray/BitArray.h BloomFilter/BloomFilter.cpp BloomFilter/BloomFilter.h Helper/Helper.cpp Helper/Helper.h SkipListNode/SkipListNode.cpp SkipListNode/SkipListNode.h SkipList/SkipList.cpp SkipList/SkipList.h)