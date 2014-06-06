cmake_minimum_required(VERSION 2.6)

project(QtMap)

# find Qt4
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

# header files
include_directories(${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_BINARY_DIR})

# source files
aux_source_directory(${PROJECT_SOURCE_DIR}/src  SRC_FILES)

# Qt4 related command
QT4_WRAP_UI(QtMap_UIC_FILES  ${PROJECT_SOURCE_DIR}/ui/statecityinput.ui
                             ${PROJECT_SOURCE_DIR}/ui/sort.ui)
QT4_WRAP_CPP(QtMap_MOC_FILES  ${PROJECT_SOURCE_DIR}/src/sample_dialog.h
                              ${PROJECT_SOURCE_DIR}/src/statecityinput_dialog.h
                              ${PROJECT_SOURCE_DIR}/src/sort_dialog.h
                              ${PROJECT_SOURCE_DIR}/src/sample_mainwindow.h
                              ${PROJECT_SOURCE_DIR}/src/spreadsheet.h)         
QT4_ADD_RESOURCES(QtMap_RES_FILES  ${PROJECT_SOURCE_DIR}/res/qtmap.qrc)

# artifact
add_executable(QtMap  ${SRC_FILES}
                      ${QtMap_MOC_FILES}
                      ${QtMap_UIC_FILES}
                      ${QtMap_RES_FILES})
target_link_libraries(QtMap  ${QT_LIBRARIES})