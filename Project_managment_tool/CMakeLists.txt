cmake_minimum_required(VERSION 3.20)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(LogicLib)
add_subdirectory(JsonSerializer)


file(GLOB_RECURSE SRC "SourceFiles/*.cpp")

link_directories("JsonSerializer")
link_directories("LogicLib")

add_executable(Project_managment_tool ${SRC})

message("${PROJECT_SOURCE_DIR}")

install(TARGETS Project_managment_tool
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries(${PROJECT_NAME} JsonSerializer)
target_link_libraries(Project_managment_tool LogicLib)



