#
# This module finds an installed libpqxx library
#
# LIBPQXX_FOUND - Set to true if libpqxx and headers are found. Otherwise False or undefined.
# LIBPQXX_INCLUDE_DIR - Where libpqxx Header files are located
# LIBPQXX_LIBRARIES - libqxx libraries
#
FIND_PATH(LIBPQXX_INCLUDE_DIR
    pqxx/connection.hxx
    HINTS /opt/pqxx/
    PATH_SUFFIXES "include"
)

FIND_LIBRARY(LIBPQXX_LIBRARIES
    SHARED pqxx
    HINTS /opt/pqxx/lib
)

IF (LIBPQXX_INCLUDE_DIR)
    MESSAGE(STATUS "libpqxx include files found in: ${LIBPQXX_INCLUDE_DIR}")
ELSE (LIBPQXX_INCLUDE_DIR)
    MESSAGE(FATAL_ERROR "libpqxx include files NOT found.")
ENDIF (LIBPQXX_INCLUDE_DIR)

IF (LIBPQXX_LIBRARIES)
    MESSAGE(STATUS "libpqxx library files found in: ${LIBPQXX_LIBRARIES}")
ELSE (LIBPQXX_LIBRARIES)
    MESSAGE(FATAL_ERROR "libpqxx library files NOT found.")
ENDIF (LIBPQXX_LIBRARIES)

IF (LIBPQXX_INCLUDE_DIR AND LIBPQXX_LIBRARIES)
    SET(LIBPQXX_FOUND TRUE)
ENDIF (LIBPQXX_INCLUDE_DIR AND LIBPQXX_LIBRARIES)
