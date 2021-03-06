set(LIBNAME ${APP_LIBRARY_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(MODULE_PREFIX App)
set(MODULE_NAMESPACE App)

configure_file(config.hxx.in config.hxx)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")
set(CMAKE_AUTOMOC ON)

set(HEADER_FILES
    config.hxx
    app.hxx
    action.hxx
    databaseaction.hxx
    actionforavailabledatabase.hxx
    actionforunavailabledatabase.hxx
    settings.hxx
)

set(SOURCE_FILES
    app.cxx
    action.cxx
    databaseaction.cxx
    actionforavailabledatabase.cxx
    actionforunavailabledatabase.cxx
    settings.cxx
)

add_library(${LIBNAME}
    SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

set_target_properties(${LIBNAME}
    PROPERTIES
    VERSION ${LIBVERSION}
    SOVERSION ${LIBSOVERSION}
)

target_link_libraries(
    ${LIBNAME}
    ${PGCONN_LIBRARY_NAME}
    ${Qt5Widgets_LIBRARIES}
)
