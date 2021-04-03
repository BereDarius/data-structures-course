cmake_minimum_required(VERSION 3.17)
project(FixedCapBiMap)

set(CMAKE_CXX_STANDARD 14)

add_executable(FixedCapBiMap main.cpp ExtendedTest.cpp FixedCapBiMap.cpp FixedCapBiMapIterator.cpp ShortTest.cpp)