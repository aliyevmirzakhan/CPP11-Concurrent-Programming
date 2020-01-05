cmake_minimum_required(VERSION 3.15)
project(RaceMutex)

set(CMAKE_CXX_STANDARD 11)

add_executable(RaceMutex main.cpp)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(RaceMutex Threads::Threads)
