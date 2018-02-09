project (sample1)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable (sample1 sample1.h sample1.cpp)

target_link_libraries (sample1 widgettoolkit ${SDL2_LIBRARY} ${SDL2_MAIN_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${COCOA_LIBRARY})
set_property (TARGET sample1 PROPERTY CXX_STANDARD 11)
