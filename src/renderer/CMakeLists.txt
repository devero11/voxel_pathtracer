add_library(render render.cpp)
add_library(screen_tex screen_texture.cpp)

target_include_directories(render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(screen_tex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(render PUBLIC shader_tools)

target_link_libraries(screen_tex PUBLIC shader_tools)

