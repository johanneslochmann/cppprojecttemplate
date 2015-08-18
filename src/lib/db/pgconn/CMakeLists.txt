set(LIBNAME ${PGCONN_LIBRARY_NAME})

set(LIBVERSION_MAJOR 1)
set(LIBVERSION_MINOR 0)
set(LIBVERSION_PATCH 0)

set(MODULE_PREFIX PgConn)
set(MODULE_NAMESPACE Pg)
set(DEFAULT_HOST_NAME localhost)
set(DEFAULT_PORT 5433)
set(DEFAULT_DATABASE_NAME testdb)
set(DEFAULT_USER_NAME testusr)
set(DEFAULT_PASSWORD ohWie5Ou)

configure_file(config.hxx.in config.hxx)

set(LIBSOVERSION ${LIBVERSION_MAJOR})
set(LIBVERSION ${LIBVERSION_MAJOR}.${LIBVERSION_MINOR}.${LIBVERSION_PATCH})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")
set(CMAKE_AUTOMOC ON)

set(HEADER_FILES
    config.hxx
    connection.hxx
    connectiondata.hxx
)

set(SOURCE_FILES
    connection.cxx
    connectiondata.cxx
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
    ${CORE_LIBRARY_NAME}
    ${LIBPQXX_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
)

#add_subdirectory(test)
