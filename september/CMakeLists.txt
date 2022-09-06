project(September)

add_subdirectory(06)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  September06
)