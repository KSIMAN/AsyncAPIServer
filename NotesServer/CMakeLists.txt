cmake_minimum_required(VERSION 3.5)

project(NotesServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE( Boost 1.40 COMPONENTS asio REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE( NotesServer main.cpp server.h server.cpp)

TARGET_LINK_LIBRARIES( NotesServer LINK_PUBLIC ${Boost_LIBRARIES} )
#add_executable(NotesServer main.cpp server.h server.cpp)
