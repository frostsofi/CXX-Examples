cmake_minimum_required(VERSION 3.12)
project(Basic)

set(SOURCES main.cpp)
add_executable(main ${SOURCES})

set_target_properties(
		main PROPERTIES
		CXX_STANDART 11
		CXX_STANDART_REQUIRED ON
)
