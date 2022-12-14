QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
TARGET = Procesador de imagenes
CONFIG += c++17

QMAKE_EXTRA_COMPILERS += nasm
NASMEXTRAFLAGS = -f win64
OTHER_FILES += $$NASM_SOURCES
nasm.output = ${QMAKE_FILE_BASE}.o
nasm.commands = nasm $$NASMEXTRAFLAGS -o ${QMAKE_FILE_BASE}.o ${QMAKE_FILE_NAME}
nasm.input = NASM_SOURCES

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

NASM_SOURCES = src/Filtros.asm

SOURCES += \
    src/imagen.cpp \
    src/main.cpp \
    src/MainWindow.cpp


HEADERS += \
    src/MainWindow.hpp \
    src/imagen.hpp

FORMS += \
    src/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/Filtros.asm
