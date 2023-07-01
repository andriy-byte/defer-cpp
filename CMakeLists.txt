cmake_minimum_required(VERSION 3.25)
project(defer CXX)
set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} include/defer.hpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX PUBLIC_HEADER "include/defer.hpp")
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
        )
install(TARGETS defer)
