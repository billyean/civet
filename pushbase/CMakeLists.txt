add_executable(pushbase
        src/main.cpp
        src/executors/CPUThreadPool.h
        src/executors/CPUThreadPool.cpp)

set_target_properties(pushbase PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )