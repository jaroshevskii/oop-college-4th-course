project(Practice)

add_subdirectory(practical-work1)
add_subdirectory(practical-work2)
add_subdirectory(practical-work3)

add_custom_target(Practice)
add_dependencies(Practice
  PracticePracticalWork1
  PracticePracticalWork2
  PracticePracticalWork3
)