cmake_minimum_required(VERSION 3.7)
project(test_client)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(test_client ${SOURCE_FILES})

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Client_SOURCE_DIR})

target_link_libraries(test_client ${Boost_SYSTEM_LIBRARY})
target_link_libraries(test_client ${Boost_SERIALIZATION_LIBRARY})
target_link_libraries (test_client ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
target_link_libraries (test_client "Client" )
enable_testing( )
#add_test ( ${CMAKE_CURRENT_BINARY_DIR}/ Client )

target_link_libraries(test_client ws2_32)