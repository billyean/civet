add_executable(pushbase
        src/main.cpp
        src/MyThreadPool.h
        src/MyThreadPool.cpp)

set_target_properties(pushbase PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        )