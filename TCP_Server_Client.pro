QT += core
QT -= gui
QT += network
CONFIG += c++11

TARGET = TCP_Server_Client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcp_server.cpp \
    tcp_client.cpp

HEADERS += \
    tcp_server.h \
    tcp_client.h
