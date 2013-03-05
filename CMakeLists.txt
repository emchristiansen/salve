cmake_minimum_required(VERSION 2.8)

project(salve)

################################
# GTest
################################
ADD_SUBDIRECTORY (gtest-1.6.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
include_directories(src)

# Set testSources to all source files beginning with "test".
file(GLOB testSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "test/test*")
message(STATUS "testSources = ${testSources}")
add_executable(runUnitTests ${testSources})

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)

################################
# OpenCV Unit Tests
################################
find_package(OpenCV)
if(${OpenCV_FOUND})
  message(STATUS "OpenCV found, building for OpenCV")

  # Set testSources to all source files beginning with "test".
  file(GLOB openCVTestSources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "test/opencv/test*")
  message(STATUS "openCVTestSources = ${openCVTestSources}")
  add_executable(runOpenCVUnitTests ${openCVTestSources})

  # Link test executable against gtest & gtest_main
  target_link_libraries(runOpenCVUnitTests gtest gtest_main ${OpenCV_LIBS})
  add_test(runOpenCVUnitTests runOpenCVUnitTests)  
endif(${OpenCV_FOUND})

################################
# Install
################################
# Configure "make install".
# In Linux this installs to /usr/local/include/salve/.
install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/salve/"
  DESTINATION include/salve
)