cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)
project(cppprojecttemplate CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/buildsys")

# configure boost
set(BOOST_ROOT /opt/boost)
set(BOOST_INCLUDEDIR ${BOOST_ROOT}/include)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib)
set(Boost_NO_SYSTEM_PATHS ON)
find_package(Boost 1.56 REQUIRED)

find_package(Clang REQUIRED)    # we use clang++
find_package(Pqxx REQUIRED)     # we use libpqxx and postgres as our database
find_package(Threads REQUIRED)  # required by GTest
find_package(GTest REQUIRED)    # we use google test for unit testing

find_package(Qt5Widgets REQUIRED)    # Qt5 widgets
find_package(Doxygen)           # optional if doc target should be built
find_package(Sloccount)         # optional if stat target should be built
find_package(Graphviz)          # optional if dependencygraph should be built
find_package(Gitstats)          # optional if gitstas should be built

enable_testing()

set(CMAKE_CXX_COMPILER ${CLANG_PROGRAM})
set(PROJECT_COMPILER_FLAGS "-Wall -Werror -std=c++14 -ftemplate-backtrace-limit=0 -fPIC")

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${LIBPQXX_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/lib)
include_directories(${CMAKE_SOURCE_DIR}/src/lib)
include_directories(${CMAKE_BINARY_DIR}/src/lib)     #to find generated config files

set(PROJECT_BUILD_DIR ${CMAKE_BINARY_DIR}/build)
set(PROJECT_DOC_DIR ${PROJECT_BUILD_DIR}/doc)
set(PROJECT_GITSTATS_DIR ${PROJECT_BUILD_DIR}/gitstats)
set(PROJECT_LIB_DIR ${PROJECT_BUILD_DIR}/lib)
set(PROJECT_BIN_DIR ${PROJECT_BUILD_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})

if (DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(
        doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif(DOXYGEN_FOUND)

if(GITSTATS_FOUND)
    add_custom_target(
        gitstat
        ${GITSTATS_PROGRAM} ${CMAKE_SOURCE_DIR} ${PROJECT_GITSTATS_DIR}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating git stats"
        VERBATIM
    )
endif(GITSTATS_FOUND)

if(SLOCCOUNT_FOUND)
    add_custom_target(
        stat
        ${SLOCCOUNT_PROGRAM} src
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating sloccount stats"
        VERBATIM
    )
endif(SLOCCOUNT_FOUND)

if(GRAPHVIZ_FOUND)
    add_custom_target(
        dependencies
        COMMAND ${CMAKE_COMMAND} --graphviz=dependencies.dot ${PROJECT_SOURCE_DIR}
        WORKING_DIRECTORY ${PROJECT_BUILD_DIR}
        COMMENT "Calculating module dependencies"
        VERBATIM
    )

    add_custom_target(
        dependencygraph
        COMMAND ${GRAPHVIZ_PROGRAM} -Tsvg dependencies.dot -o dependencies.svg
        WORKING_DIRECTORY ${PROJECT_BUILD_DIR}
        COMMENT "Creating graphical module dependencies"
        VERBATIM
    )
endif(GRAPHVIZ_FOUND)

set(PROJECT_NAMESPACE ${PROJECT_NAME}) # this will be the globally used namespace
set(PROJECT_PREFIX ${PROJECT_NAME}_)
set(LIBRARY_PREFIX ${PROJECT_PREFIX})
set(TEST_PROGRAM_PREFIX tst_)
set(TEST_LIBRARY_PREFIX tst_lib_)

set(ORGANIZATION_NAME "jolo" )                              # used by QApplication
set(ORGANIZATION_DOMAIN "johanneslochmann.blogspot.com")    # used by QApplication

set(DEMO_APP_NAME ${PROJECT_PREFIX}demo)
set(CORE_LIBRARY_NAME ${LIBRARY_PREFIX}core)
set(MODEL_LIBRARY_NAME ${LIBRARY_PREFIX}model)
set(WIDGETS_LIBRARY_NAME ${LIBRARY_PREFIX}widgets)
set(APP_LIBRARY_NAME ${LIBRARY_PREFIX}app)
set(PGCONN_LIBRARY_NAME ${LIBRARY_PREFIX}pgconn)

# print configuration summary
MESSAGE(STATUS "gitstats: ${GITSTATS_PROGRAM}")
MESSAGE(STATUS "clang++ compiler: ${CLANG_PROGRAM}")

MESSAGE(STATUS "Qt5Widgets Version: " ${Qt5Widgets_VERSION_STRING})
MESSAGE(STATUS "Qt5Widgets Libraries: " ${Qt5Widgets_LIBRARIES})
MESSAGE(STATUS "Qt5Widgets Include Directories: " ${Qt5Widgets_INCLUDE_DIRS})
MESSAGE(STATUS "Qt5Widgets Definitions: " ${Qt5Widgets_DEFINITIONS})
MESSAGE(STATUS "Qt5Widgets Compile Definitions: " ${Qt5Widgets_COMPILE_DEFINITIONS})
MESSAGE(STATUS "Qt5Widgets Executable Compile Flags: " ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS})

MESSAGE(STATUS "build directory: ${PROJECT_BUILD_DIR}")
MESSAGE(STATUS "document output directory: ${PROJECT_DOC_DIR}")
MESSAGE(STATUS "library output directory: ${PROJECT_LIB_DIR}")
MESSAGE(STATUS "binary output directory: ${PROJECT_BIN_DIR}")

MESSAGE(STATUS "project name: ${PROJECT_NAME}")
MESSAGE(STATUS "project prefix: ${PROJECT_PREFIX}")
MESSAGE(STATUS "library prefix: ${LIBRARY_PREFIX}")
MESSAGE(STATUS "test program prefix: ${TEST_PROGRAM_PREFIX}")

MESSAGE(STATUS "core library: ${CORE_LIBRARY_NAME}")
MESSAGE(STATUS "model library: ${MODEL_LIBRARY_NAME}")
MESSAGE(STATUS "widgets library: ${WIDGETS_LIBRARY_NAME}")
MESSAGE(STATUS "app library: ${APP_LIBRARY_NAME}")
MESSAGE(STATUS "pgconn library: ${PGCONN_LIBRARY_NAME}")

add_subdirectory(src)
