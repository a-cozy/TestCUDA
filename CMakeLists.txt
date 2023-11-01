cmake_minimum_required(VERSION 3.5)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
project(MyCudaProject)

# Create Main project
set(SOURCES_A
    MainA/main.cpp
)

set(HEADERS_A
    # MainA/main.h
)

add_executable(MainA
    ${SOURCES_A}
    ${HEADERS_A}
)

# Add sub project
add_subdirectory(CudaVecDouble)
target_include_directories(MainA PUBLIC CudaVecDouble)
target_link_libraries(MainA CudaVecDouble)


# Create Main project
set(SOURCES_B
    MainB/main.cpp
)

set(HEADERS_B
    # MainB/main.h
)

add_executable(MainB
    ${SOURCES_B}
    ${HEADERS_B}
)

