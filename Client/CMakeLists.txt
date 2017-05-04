cmake_minimum_required(VERSION 3.7)
project(Client)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp src/M_User.cpp src/User.cpp)
add_executable(Client ${SOURCE_FILES})
set(BOOST_MANDATORY_COMPONENTS system)
set(BOOST_ROOT "C:/boost_1.62/")


find_package(Boost REQUIRED COMPONENTS system serialization)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Client ${Boost_SYSTEM_LIBRARY})
target_link_libraries(Client ${Boost_SERIALIZATION_LIBRARY})
target_link_libraries(Client ws2_32)

