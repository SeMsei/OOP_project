cmake_minimum_required(VERSION 3.20)

project(Project_managment_tool LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_NO_WARN_NEW_VERSIONS 1)

find_package(Boost REQUIRED)
message(STATUS "Boost version: ${Boost_VERSION}")
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)
include_directories(SYSTEM ${OPENSSL_INCLUDE_DIRS})


file(GLOB_RECURSE SRC "*.cpp" "lib_include/*.h" "lib_include/*.hpp")

link_directories("libs/JsonSerializer")
link_directories("libs/LogicLib")

add_executable(Project_managment_tool ${SRC})

message("${PROJECT_SOURCE_DIR}")

install(TARGETS Project_managment_tool
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries(${PROJECT_NAME} JsonSerializer)
target_link_libraries(Project_managment_tool LogicLib)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(Project_managment_tool OpenSSL::SSL)



