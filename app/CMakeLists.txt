cmake_minimum_required(VERSION 3.19)
project(LabSimulator LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()

set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

set(CMAKE_AUTORCC ON)

include_directories(include)

qt_add_executable(LabSimulator
    src/main.cpp
    src/mainwindow.cpp
    src/exercise3.cpp
    include/mainwindow.h
    include/exercise3.h
    ui/mainwindow.ui
    resources.qrc
)

target_link_libraries(LabSimulator
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Charts
)

add_custom_command(TARGET LabSimulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/data/zadanie1"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/data/zadanie2"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/data/zadanie3"
)

install(TARGETS LabSimulator
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET LabSimulator
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})