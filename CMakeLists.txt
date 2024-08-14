cmake_minimum_required(VERSION 3.16)

project(task3_to_do_list VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(apptask3_to_do_list
    main.cpp
)

qt_add_qml_module(apptask3_to_do_list
    URI task3_to_do_list
    VERSION 1.0
    NO_CACHEGEN
    #RESOURCE_PREFIX D:/Atomica/Repos/task3_to_do_list
    QML_FILES main.qml
    SOURCES qabstractlistmodel_data.h qabstractlistmodel_data.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptask3_to_do_list PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptask3_to_do_list
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptask3_to_do_list
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS apptask3_to_do_list
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
