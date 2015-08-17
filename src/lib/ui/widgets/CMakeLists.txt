set(LIBNAME ${WIDGETS_LIBRARY_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(MODULE_PREFIX Widgets)
set(MODULE_NAMESPACE Widgets)

configure_file(config.hxx.in config.hxx)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(HEADER_FILES
    config.hxx
    label.hxx
    statuslabel.hxx
)

set(SOURCE_FILES
    label.cxx
    statuslabel.cxx
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

set(CMAKE_AUTOMOC ON)

target_link_libraries(
    ${LIBNAME}
    ${CORE_LIBRARY_NAME}
    ${Qt5Widgets_LIBRARIES}
)
