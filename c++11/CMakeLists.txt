add_executable(Initializer
        new_feature/src/Initializer.cpp)
set_target_properties(Initializer PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(newFuncDef
        new_feature/src/newFuncDef.cpp)
set_target_properties(newFuncDef PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )

add_executable(TestLambda
        new_feature/src/TestLambda.cpp)
set_target_properties(TestLambda PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )