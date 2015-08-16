#
# This module finds an installed graphviz binary
#
# GRAPHVIZ_FOUND - Set to true if "dot" from the graphviz package is found. Otherwise False or undefined
# GRAPHVIZ_PROGRAM - the graphviz binary
#
FIND_PROGRAM(GRAPHVIZ_PROGRAM
    dot
)

IF (GRAPHVIZ_PROGRAM)
    MESSAGE(STATUS "dot found: ${SLOCCOUNT_PROGRAM}")
ELSE (GRAPHVIZ_PROGRAM)
    MESSAGE(FATAL_ERROR "dot NOT found.")
ENDIF (GRAPHVIZ_PROGRAM)

IF (GRAPHVIZ_PROGRAM)
    SET(GRAPHVIZ_FOUND TRUE)
ENDIF (GRAPHVIZ_PROGRAM)
