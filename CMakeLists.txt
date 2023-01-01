cmake_minimum_required(VERSION 3.0.0)

project(OOPCollege3rdCourse
  LANGUAGES CXX Swift)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(practical-work1)
add_subdirectory(practical-work2)
add_subdirectory(practical-work3)
add_subdirectory(practical-work4)
add_subdirectory(practical-work5)
add_subdirectory(practical-work6)

add_subdirectory(practice)

# add_custom_target(${PROJECT_NAME})
# add_dependencies(${PROJECT_NAME}
#   PracticalWork1
#   PracticalWork2
#   PracticalWork3
#   PracticalWork4
#   PracticalWork5
#   PracticalWork6

#   Practice
# )add_custom_target(${PROJECT_NAME})
# add_dependencies(${PROJECT_NAME}
#   PracticalWork1
#   PracticalWork2
#   PracticalWork3
#   PracticalWork4
#   PracticalWork5
#   PracticalWork6

#   Practice
# )