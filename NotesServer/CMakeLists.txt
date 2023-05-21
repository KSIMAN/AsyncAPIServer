cmake_minimum_required(VERSION 3.5)

project(NotesServer LANGUAGES CXX)

set(CMAKE_CXX_FLAGS " -std=c++17" )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.74.0 COMPONENTS asio thread thread-mt)

 include_directories(${Boost_INCLUDE_DIRS})
 add_executable(NotesServer  main.cpp server.h server.cpp databaseconnector.h databaseconnector.cpp requestprocessor.h requestprocessor.cpp logger.h logger.cpp)
 target_link_libraries(NotesServer ${Boost_LIBRARIES})

