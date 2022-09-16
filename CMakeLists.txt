cmake_minimum_required(VERSION 3.0.0)

project(OOPCollege3rdCourse)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(practical-work2)
add_subdirectory(practical-work3)
add_subdirectory(practical-work4)

add_custom_target(OOPCollege3rdCourse)
add_dependencies(OOPCollege3rdCourse
  PracticalWork2
  PracticalWork3
  PracticalWork4
)