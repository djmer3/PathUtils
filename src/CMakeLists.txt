# include(FetchContent)
# FetchContent_Declare(
#   Eigen
#   GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
#   GIT_TAG master
#   GIT_SHALLOW TRUE
#   GIT_PROGRESS TRUE)
# set(EIGEN_BUILD_DOC OFF)
# # note: To disable eigen tests,
# # you should put this code in a add_subdirectory to avoid to change
# # BUILD_TESTING for your own project too since variables are directory
# # scoped
# set(BUILD_TESTING OFF)
# set(EIGEN_BUILD_PKGCONFIG OFF)
# set( OFF)
# FetchContent_MakeAvailable(Eigen)

include(FetchContent)
FetchContent_Declare(
      Eigen
      GIT_REPOSITORY    https://gitlab.com/libeigen/eigen.git
      GIT_TAG           master
    )
FetchContent_MakeAvailable(Eigen)



add_library(${PROJECT_NAME}
  path.cpp
  path.h
)
 
# target_sources(${PROJECT_NAME}
#   PRIVATE Eigen3::Eigen
#   PRIVATE path.cpp
#   PUBLIC  path.h
# )
target_link_libraries(${PROJECT_NAME} 
  PRIVATE 
    Eigen3::Eigen)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)