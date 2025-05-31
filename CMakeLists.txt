cmake_minimum_required(VERSION 3.16)

project(MyuPrototype VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appMyuPrototype
    main.cpp
)

set_source_files_properties(Frontend/Style.qml
    PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(appMyuPrototype
    URI MyuPrototype
    VERSION 1.0
    QML_FILES

        SOURCES
        SOURCES Backend/asiofunctions.h
        SOURCES Backend/asiofunctions.cpp
        SOURCES Backend/maincontroller.h Backend/maincontroller.cpp
        QML_FILES Frontend/Style.qml
        QML_FILES
        QML_FILES
        QML_FILES
        RESOURCES resources.qrc
        QML_FILES
        SOURCES Backend/asiothread.h Backend/asiothread.cpp
        SOURCES Backend/config.cpp
        SOURCES
        QML_FILES
        QML_FILES
        QML_FILES
        QML_FILES
        QML_FILES Frontend/Components/Metronome.qml
        QML_FILES
        QML_FILES Frontend/Pages/FreePlay.qml
        QML_FILES Frontend/Components/ToolBarButton.qml
        QML_FILES
        QML_FILES Frontend/Windows/MainWindow.qml
        QML_FILES Frontend/Windows/MainWindowFooter.qml
        QML_FILES Frontend/Windows/MainWindowHeader.qml
        QML_FILES Frontend/Windows/SettingsWindow.qml
        SOURCES
        SOURCES Backend/Audio/wavfile.h Backend/Audio/wavfile.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMyuPrototype PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMyuPrototype
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMyuPrototype
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appMyuPrototype
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_subdirectory(ASIO)
target_link_libraries(appMyuPrototype PUBLIC ASIO)
target_include_directories(appMyuPrototype PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/ASIO"
                          )


set(QML_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Backend
)

# Add includepaths
target_include_directories(appMyuPrototype PRIVATE
    ${QML_INCLUDES}
)

target_link_libraries(appMyuPrototype PRIVATE Qt6::Multimedia)
