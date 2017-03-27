# QT Modules
QT += qml quick serialport widgets

# Target
TARGET = dashboard
TEMPLATE = app

# Extra Configs
DEFINES += TIMER_FREQ
CONFIG(release, debug|release) {
       DEFINES += QT_NO_DEBUG_OUTPUT
}

# Extra Configs
#DEFINES += NETWORK_MODE
DEFINES += SERIAL_MODE

# Sources and Headers
SOURCE_FOLDER = src
HEADER_FOLDER = src/include

INCLUDEPATH += $$HEADER_FOLDER
HEADERS += $$HEADER_FOLDER/serial.h \
    $$HEADER_FOLDER/protocol.h \
    $$HEADER_FOLDER/airLink.h \
    $$HEADER_FOLDER/fontName.h

SOURCES += $$SOURCE_FOLDER/main.cpp \
    $$SOURCE_FOLDER/serial.cpp \
    $$SOURCE_FOLDER/protocol.cpp \
    $$SOURCE_FOLDER/airLink.cpp \

# Qml Files
QML_FOLDER = qml/content
FONT_FOLDER = fonts/
OTHER_FILES += qml/mainViewer.qml \
    $$QML_FOLDER/*.qml \
    $$QML_FOLDER/qmldir \
    $$FONT_FOLDER/*

# Resources
RESOURCES += \
    show005.qrc
QMAKE_RESOURCE_FLAGS += -no-compress

# Objects Pathes
DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

DISTFILES += \
    qml/turnImage.qml

