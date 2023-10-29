add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE
    path.cpp
  PUBLIC
    path.h
  )

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

