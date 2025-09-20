cmake_minimum_required(VERSION 3.16)

project(TCP_Server_Client_ LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Network)

file(GLOB SOURCES "*.cpp" , "*.h")

add_executable(TCP_Server_Client_ ${SOURCES})
target_link_libraries(TCP_Server_Client_ Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(TCP_Server_Client_ Qt${QT_VERSION_MAJOR}::Network)

include(GNUInstallDirs)
install(TARGETS TCP_Server_Client_
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
