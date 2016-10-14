set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
set (CPP_FILES instruction.cpp cortex.cpp)
add_executable(cortex main.cpp ${CPP_FILES})
