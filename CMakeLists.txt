cmake_minimum_required(VERSION 3.15)
project(RaycasterAttempt VERSION 1 LANGUAGES CXX)

find_package(SDL3 REQUIRED)

add_executable(RaycasterAttempt
    src/UserSideSDL3/main.cpp
    src/LoadUserSettings.cpp
    src/RaycasterRenderer.cpp
    src/player.cpp
)

target_include_directories(RaycasterAttempt PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(RaycasterAttempt PRIVATE SDL3::SDL3)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU"  OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(RaycasterAttempt PRIVATE
        -O2
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(RaycasterAttempt PRIVATE
        /O2
    )
endif()

