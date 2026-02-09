add_library(glad glad.c)

target_include_directories(window INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
