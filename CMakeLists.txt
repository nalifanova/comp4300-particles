cmake_minimum_required(VERSION 3.28)
project(Particles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-reorder")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(include)
include_directories(assets)

add_executable(${PROJECT_NAME}
    main.cpp
    include/Application.hpp
    include/ParticleSystem.hpp
    src/Application.cpp
    src/ParticleSystem.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

file(GLOB fonts ${CMAKE_SOURCE_DIR}/assets/fonts/*.otf)
file(COPY ${fonts} DESTINATION ${CMAKE_BINARY_DIR}/bin/assets/fonts)
