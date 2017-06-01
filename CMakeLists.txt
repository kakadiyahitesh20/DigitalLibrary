cmake_minimum_required(VERSION 3.7)
project(DigitalLibrary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/DigitalLibrary.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        Client/.idea/Client.iml
        Client/.idea/misc.xml
        Client/.idea/modules.xml
        Client/.idea/vcs.xml
        Client/.idea/workspace.xml
        Client/cmake-build-debug/Client_automoc.cpp
        Client/cmake-build-release/Client.cbp
        Client/cmake-build-release/cmake_install.cmake
        Client/cmake-build-release/CMakeCache.txt
        Client/cmake-build-release/Makefile
        Client/include/User.h
        Client/src/User.cpp
        Client/CMakeLists.txt
        Client/main.cpp)

add_executable(DigitalLibrary ${SOURCE_FILES})