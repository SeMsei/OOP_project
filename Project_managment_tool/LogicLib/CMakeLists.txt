cmake_minimum_required(VERSION 3.14)

project(LogicLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LogicLib STATIC
  src/db_manager.cpp
  src/employee.cpp
  src/functions.cpp
  src/personaltask.cpp
  src/project.cpp
  src/role_class.cpp
  src/task.cpp
  src/worktask.cpp

#  include/db_manager.h
#  include/employee.h
#  include/functions.h
#  include/personaltask.h
#  include/project.h
#  include/role.h
#  include/role_class.h
#  include/task.h
#  include/worktask.h
)
