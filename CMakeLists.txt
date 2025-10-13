cmake_minimum_required(VERSION 3.12)
project(Test)
add_executable(main main.cpp)
set_target_properties(
		main PROPERTIES
		CXX_STANDART 11
		CXX_STANDART_REQUIRED ON
)
