cmake_minimum_required(VERSION 3.17)
project(civet)

set(CMAKE_CXX_STANDARD 17)
#
#add_executable(civet
#        c++11/new_feature/src/Initializer.cpp
#        c++11/new_feature/src/newFuncDef.cpp
#        c++11/new_feature/src/TestLambda.cpp
#        stl/src/dequeTest.cpp
#        stl/src/modifyingAlgorithm.cpp
#        stl/src/mutatingAlgorithm.cpp
#        stl/src/nonModifyingAlgorithm.cpp
#        stl/src/regexTest.cpp
#        stl/src/removingAlgorithm.cpp
#        stl/src/reverseVowels.cpp
#        stl/src/topKFrequent.cpp
#        stl/src/unorderedTest.cpp
#        stl/src/vector1.cpp
#        stl/src/vectorTest.cpp
#        add.c
#        bigOrLittle.cpp
#        bitCal.cpp
#        c1-1.cpp
#        size.cpp)

add_subdirectory(c++11)
add_subdirectory(stl)
add_subdirectory(pushbase)
add_subdirectory(leak)
add_subdirectory(bp)


add_executable(bigOrLittle
        bigOrLittle.cpp)
set_target_properties(bigOrLittle PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(c1-1
        c1-1.cpp)

add_executable(size
        size.cpp)