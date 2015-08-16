#
# This module finds an installed gitstats binary
#
# get it from: https://github.com/hoxu/gitstats
#
# GITSTATS_FOUND - Set to true if gitstats is found. Otherwise False or undefined
# GITSTATS_PROGRAM - the gitstats binary
#
FIND_PROGRAM(GITSTATS_PROGRAM
    gitstats
)

IF (GITSTATS_PROGRAM)
    MESSAGE(STATUS "gitstats found: ${GITSTATS_PROGRAM}")
ELSE (GITSTATS_PROGRAM)
    MESSAGE(FATAL_ERROR "gitstats NOT found.")
ENDIF (GITSTATS_PROGRAM)

IF (GITSTATS_PROGRAM)
    SET(GITSTATS_FOUND TRUE)
ENDIF (GITSTATS_PROGRAM)
