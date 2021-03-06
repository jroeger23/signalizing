# Works with 3.11 and tested through 3.16
cmake_minimum_required(VERSION 3.11...3.16)

# Project name and a few useful settings. Other commands can pick up the results
project(modern
    VERSION 0.1
    DESCRIPTION "My humble signal processing library"
    LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
	add_subdirectory(docs)
    else()
	message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

# The compiled library code is here
add_subdirectory(src)

# Testing
find_library(CATCH2_LIB catch2)
if (CATCH2_LIB)
  include(CTest)
  include(Catch)
  add_subdirectory(tests)
elseif (EXISTS ${PROJECT_SOURCE_DIR}/third_party/Catch2)
  add_subdirectory(third_party/Catch2)
  include(third_party/Catch2/contrib/Catch.cmake)
  add_subdirectory(tests)
else()
  message("Catch2 not found, disable tests. (global or third_party/Catch2")
endif()
