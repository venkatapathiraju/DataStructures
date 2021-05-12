# CMakeList.txt : CMake project for DataStructures, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project ("DataStructures")

# Add source to this project's executable.
add_executable (DataStructures "DataStructures.cpp" "DataStructures.h" "StackTest.h" "QueueTest.h" "MyQueue.h" "HotDrink.h" "rvalue.h" "VariadicTempTest.h" "MyExcpetion.h" "LinkedList.h" "TreeTest.h" "Util.h" "graphtest.h" "HashTest.h" "SortTest.h" "bfsgraph.h" "matrixbfs.h" "krusalgraph.h" "recursion.h")

# TODO: Add tests and install targets if needed.
