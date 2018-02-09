project (sample2)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable (sample2 sample2.cpp)

target_link_libraries (sample2 widgettoolkit ${SDL2_LIBRARY} ${SDL2_MAIN_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${COCOA_LIBRARY})
set_property(TARGET sample2 PROPERTY CXX_STANDARD 11)
