CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(CppTemplateApplication)

# To run with Clang:
# cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_CC_COMPILER=/usr/bin/clang ..

SET(CMAKE_CXX_STANDARD 17)

SET(SOURCE_FILES
    hello.cpp
)

set( UNIT_TESTS
    hello.tests.cpp
)

ADD_EXECUTABLE(CppTemplateApplication main.cpp ${SOURCE_FILES})


TARGET_INCLUDE_DIRECTORIES(CppTemplateApplication PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

TARGET_LINK_LIBRARIES(CppTemplateApplication LINK_PUBLIC
)


# Download and unpack googletest at configure time
# see https://crascit.com/2015/07/25/cmake-gtest/
# copy the CMakeLists.txt.in to build area as CMakeLists.txt
configure_file( CMakeLists.txt.in googletest-download/CMakeLists.txt )
# we need to execute the build steps at config time so that
# the tests can find the gtest libraries when they configure
execute_process( COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process( COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory( ${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build )

# these steps compile and link the unit-tests executable
enable_testing()  # gives us a make test target
add_test( all unit-tests ) # gives us a make test all target
add_executable( unit-tests test-main.cpp ${SOURCE_FILES} ${UNIT_TESTS} )
TARGET_INCLUDE_DIRECTORIES( unit-tests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries( unit-tests LINK_PUBLIC
    gtest
    gmock
)
