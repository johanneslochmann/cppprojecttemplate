#
# This module finds an installed sloccount binary
#
# SLOCCOUNT_FOUND - Set to true if sloccount is found. Otherwise False or undefined
# SLOCCOUNT_PROGRAM - the sloccount binary
#
FIND_PROGRAM(SLOCCOUNT_PROGRAM
    sloccount
)

IF (SLOCCOUNT_PROGRAM)
    MESSAGE(STATUS "sloccount found: ${SLOCCOUNT_PROGRAM}")
ELSE (SLOCCOUNT_PROGRAM)
    MESSAGE(FATAL_ERROR "sloccount NOT found.")
ENDIF (SLOCCOUNT_PROGRAM)

IF (SLOCCOUNT_PROGRAM)
    SET(SLOCCOUNT_FOUND TRUE)
ENDIF (SLOCCOUNT_PROGRAM)
