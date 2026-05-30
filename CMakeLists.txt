cmake_minimum_required(VERSION 3.19)
project(LabSimulator LANGUAGES CXX)

# 1. Dodajemy moduły Qt (pamiętaj o Charts!)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()

set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

# 2. Informujemy CMake, gdzie szukać plików nagłówkowych (.h)
include_directories(include)

# 3. Definiujemy pliki źródłowe z uwzględnieniem nowej struktury
qt_add_executable(LabSimulator
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    ui/mainwindow.ui
)

# 4. Linkowanie bibliotek
target_link_libraries(LabSimulator
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Charts
)

# 5. Skrypt tworzący strukturę folderów na dane CSV w folderze budowania (opcjonalne, ale wygodne)
add_custom_command(TARGET LabSimulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/data/zadanie1"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/data/zadanie2"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/data/zadanie3"
)

# Reszta pozostaje bez zmian (instrukcje instalacji i deploy)
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