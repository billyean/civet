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

add_executable(Initializer
        c++11/new_feature/src/Initializer.cpp)
set_target_properties(Initializer PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(newFuncDef
        c++11/new_feature/src/newFuncDef.cpp)
set_target_properties(newFuncDef PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(TestLambda
        c++11/new_feature/src/TestLambda.cpp)
set_target_properties(TestLambda PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(dequeTest
        stl/src/dequeTest.cpp)
set_target_properties(dequeTest PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(modifyingAlgorithm
        stl/src/modifyingAlgorithm.cpp)
set_target_properties(modifyingAlgorithm PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(mutatingAlgorithm
        stl/src/mutatingAlgorithm.cpp)
set_target_properties(mutatingAlgorithm PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(nonModifyingAlgorithm
        stl/src/nonModifyingAlgorithm.cpp)
set_target_properties(nonModifyingAlgorithm PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(regexTest
        stl/src/regexTest.cpp)
set_target_properties(regexTest PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(removingAlgorithm
        stl/src/removingAlgorithm.cpp)
set_target_properties(removingAlgorithm PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(reverseVowels
        stl/src/reverseVowels.cpp)
set_target_properties(reverseVowels PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(topKFrequent
        stl/src/topKFrequent.cpp)
set_target_properties(topKFrequent PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(unorderedTest
        stl/src/unorderedTest.cpp)
set_target_properties(unorderedTest PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(vector1
        stl/src/vector1.cpp)
set_target_properties(vector1 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(vectorTest
        stl/src/vectorTest.cpp)
set_target_properties(vectorTest PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

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