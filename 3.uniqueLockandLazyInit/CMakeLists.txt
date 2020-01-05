cmake_minimum_required(VERSION 3.15)
project(uniqueLockandLazyInit)

set(CMAKE_CXX_STANDARD 11)

add_executable(uniqueLockandLazyInit main.cpp)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(uniqueLockandLazyInit Threads::Threads)