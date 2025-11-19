cmake_minimum_required(VERSION 3.12)
project(Basic)

set(SOURCES main.cpp)
add_executable(basic ${SOURCES})

# if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
# endif()

set_target_properties(
		basic PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED ON
)
