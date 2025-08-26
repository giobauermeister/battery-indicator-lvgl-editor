# This basic file is used to compile the runtime for the Editor preview.
# It is also intended for you to customize it for your own target/project.

# Only set project if this is the top-level CMakeLists.txt
# NOTE: ESP-IDF components must NOT call project()/cmake_minimum_required
if(NOT DEFINED IDF_PATH)
  if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.10)
    # can be customized
    project(LVGLProject)
    set(IS_TOP_LEVEL TRUE)
  else()
    set(IS_TOP_LEVEL FALSE)
  endif()
endif()

# This includes the generated list of .c files
include(${CMAKE_CURRENT_LIST_DIR}/file_list_gen.cmake)

if(DEFINED IDF_PATH)
    # === ESP-IDF Support ===
    idf_component_register(
        SRCS ${PROJECT_SOURCES}
        INCLUDE_DIRS "."
        REQUIRES lvgl
    )

    target_compile_definitions(${COMPONENT_LIB} PUBLIC
        LV_LVGL_H_INCLUDE_SIMPLE
        LV_CONF_INCLUDE_SIMPLE
    )
else()
    # === Plain CMake / Simulator Support ===
    add_library(lib-ui ${PROJECT_SOURCES})
    target_compile_definitions(lib-ui PUBLIC LV_LVGL_H_INCLUDE_SIMPLE)

    target_include_directories(lib-ui PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/lvgl
    )
endif()

# You may use this check to add configuration when compiling for the Editor
# preview, or for your target.
if (LV_EDITOR_PREVIEW)
    # things for the Preview
else ()
    # things for your target
    # set your include directories here, don't forget LVGL!
endif ()

if (IS_TOP_LEVEL)
  # Do something when this is your top level cmakelists.txt
else()
  # Do something else if it's not your top level cmakelists.txt
endif()
