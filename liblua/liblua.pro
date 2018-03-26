#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T17:33:16
#
#-------------------------------------------------

QT       -= gui

TARGET = liblua
TEMPLATE = lib

DEFINES += LIBLUA_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        liblua.cpp \
    src/lapi.c \
    src/lauxlib.c \
    src/lbaselib.c \
    src/lbitlib.c \
    src/lcode.c \
    src/lcorolib.c \
    src/lctype.c \
    src/ldblib.c \
    src/ldebug.c \
    src/ldo.c \
    src/ldump.c \
    src/lfunc.c \
    src/lgc.c \
    src/linit.c \
    src/liolib.c \
    src/llex.c \
    src/lmathlib.c \
    src/lmem.c \
    src/loadlib.c \
    src/lobject.c \
    src/lopcodes.c \
    src/loslib.c \
    src/lparser.c \
    src/lstate.c \
    src/lstring.c \
    src/lstrlib.c \
    src/ltable.c \
    src/ltablib.c \
    src/ltm.c \
    src/lundump.c \
    src/lutf8lib.c \
    src/lvm.c \
    src/lzio.c

HEADERS += \
        liblua.h \
        liblua_global.h \ 
    src/lapi.h \
    src/lauxlib.h \
    src/lcode.h \
    src/lctype.h \
    src/ldebug.h \
    src/ldo.h \
    src/lfunc.h \
    src/lgc.h \
    src/llex.h \
    src/llimits.h \
    src/lmem.h \
    src/lobject.h \
    src/lopcodes.h \
    src/lparser.h \
    src/lprefix.h \
    src/lstate.h \
    src/lstring.h \
    src/ltable.h \
    src/ltm.h \
    src/lua.h \
    src/lua.hpp \
    src/luaconf.h \
    src/lualib.h \
    src/lundump.h \
    src/lvm.h \
    src/lzio.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
