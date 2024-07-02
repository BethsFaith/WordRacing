cmake_minimum_required(VERSION 3.25)
project(ForeignRacing)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "D:/CPlusPlus/libs/Qt/qt6/install-debug-mingw")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (QT_QUICK_CONTROLS_IGNORE_CUSTOMIZATION_WARNINGS TRUE)

find_package(Qt6 COMPONENTS REQUIRED
        Core Gui Quick Qml
        )

add_executable(ForeignRacing src/main.cpp)

qt_add_qml_module(ForeignRacing
        VERSION 1.0
        URI AppModule
        RESOURCE_PREFIX /
        SOURCES
        src/Storage.cpp
        src/data/Const.hpp
        src/data/Type.hpp
        src/data/Serializable.cpp
        src/data/Dictionary.cpp
        src/data/Word.cpp
        src/data/Language.cpp
        QML_FILES
        src/ui/main.qml
        src/ui/start_menu.qml
        src/ui/learning_menu.qml
        src/ui/dictionary.qml
        src/ui/learning/help.qml
        src/ui/learning/new_words.qml
        src/ui/learning/repeat.qml
        )

target_link_libraries(ForeignRacing PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::Qml
        )

#target_include_directories(ForeignRacing PUBLIC
#        src
#        src/sessions
#        src/data
#        src/images
#        src/ui
#        src/ui/providers
#        )

#qt_add_resources(ForeignRacing "rsrc"
#        PREFIX "/"
#        FILES
#        ./rsrc/games/map.png
#        ./rsrc/games/d4.png
#        ./rsrc/games/d6.png
#        ./rsrc/games/d8.png
#        ./rsrc/games/d9.png
#        ./rsrc/games/d12.png
#        ./rsrc/games/d20.png
#        )

message(STATUS ${QML2_IMPORT_PATH})

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif()
    endif()
    if(EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
    add_custom_command(TARGET ForeignRacing POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ForeignRacing> $<TARGET_FILE_DIR:ForeignRacing>
            COMMAND_EXPAND_LISTS
            )
    add_custom_command(TARGET ForeignRacing POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory ${QT_INSTALL_PATH}/qml $<TARGET_FILE_DIR:ForeignRacing>/qml
            COMMAND_EXPAND_LISTS
            )
endif()