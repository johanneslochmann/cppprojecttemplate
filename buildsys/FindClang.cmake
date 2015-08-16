#
# This module finds an installed clang++ binary
#
# CLANG_FOUND - Set to true if clang++ is found. Otherwise False or undefined
# CLANG_PROGRAM - the clang++ binary
#
FIND_PROGRAM(CLANG_PROGRAM
    clang++
)

IF (CLANG_PROGRAM)
    MESSAGE(STATUS "clang++ found: ${CLANG_PROGRAM}")
ELSE (CLANG_PROGRAM)
    MESSAGE(FATAL_ERROR "clang++ NOT found.")
ENDIF (CLANG_PROGRAM)

IF (CLANG_PROGRAM)
    SET(CLANG_FOUND TRUE)
ENDIF (CLANG_PROGRAM)
