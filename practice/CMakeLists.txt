project(Practice)

add_subdirectory(practical-work1)
add_subdirectory(practical-work2)
add_subdirectory(practical-work3)
add_subdirectory(practical-work4)
add_subdirectory(practical-work5)
add_subdirectory(practical-work6)

add_custom_target(Practice)
add_dependencies(Practice
  PracticePracticalWork1
  PracticePracticalWork2
  PracticePracticalWork3
  PracticePracticalWork4
  PracticePracticalWork5
  PracticePracticalWork6
)