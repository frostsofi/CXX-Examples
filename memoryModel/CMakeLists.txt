cmake_minimum_required(VERSION 3.12)
project(MemoryModel)

set(SOURCES main.cpp)
add_executable(memoryModel ${SOURCES})

set_target_properties(
		memoryModel PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED ON
)
