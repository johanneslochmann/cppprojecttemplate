set(TESTED_LIB_NAME ${MODEL_LIBRARY_NAME})
set(APPNAME ${TEST_PROGRAM_PREFIX}${TESTED_LIB_NAME})

set(CMAKE_CXX_FLAGS "${PROJECT_COMPILER_FLAGS}")

set(HEADER_FILES
)

set(SOURCE_FILES
    tst_model.cxx
)

add_executable(${APPNAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${APPNAME}
  ${TESTED_LIB_NAME}
  ${GTEST_BOTH_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
)

add_test(NAME ${APPNAME} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APPNAME})
