cmake_minimum_required(VERSION 3.14)

project(JsonSerializer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library(${PROJECT_NAME} SHARED
  jsonserializer.cpp
  jsonserializer.hpp
  json.hpp
)

#set(public_headers jsonserializer.hpp)
