cmake_minimum_required(VERSION 3.7)
project(ClientMain)

set(CMAKE_CXX_STANDARD 11)
set(BOOST_MANDATORY_COMPONENTS system)
set(BOOST_ROOT "C:/boost/include/boost-1_63")

find_package(Boost REQUIRED COMPONENTS system serialization)

set(SOURCE_FILES main.cpp src/M_Book.cpp src/M_User.cpp src/User.cpp )
add_executable(ClientMain ${SOURCE_FILES})

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(ClientMain ${Boost_SYSTEM_LIBRARY})
target_link_libraries(ClientMain ${Boost_SERIALIZATION_LIBRARY})


target_link_libraries(ClientMain ws2_32)

