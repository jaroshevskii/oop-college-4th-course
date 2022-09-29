project(Practice)

add_subdirectory(practical-work1)

add_custom_target(Practice)
add_dependencies(Practice
  PracticePracticalWork1
)