cmake_minimum_required(VERSION 2.6)

project(QtMap)

# find Qt4
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

# header files
include_directories(${PROJECT_SOURCE_DIR}/src)

# source files
aux_source_directory(${PROJECT_SOURCE_DIR}/src  SRC_FILES)

# artifact
add_executable(QtMap  ${SRC_FILES})
target_link_libraries(QtMap  ${QT_LIBRARIES})