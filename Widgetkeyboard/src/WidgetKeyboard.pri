include(../common.pri)
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

WidgetKeyboard-uselib:!WidgetKeyboard-buildlib {
    LIBS += -L$$WIDGETKEYBOARD_LIBDIR -l$$WIDGETKEYBOARD_LIBNAME
} else {
    SOURCES += $$PWD/WidgetKeyboard.cpp
    HEADERS += $$PWD/WidgetKeyboard.h
    FORMS += $$PWD/WidgetKeyboard.ui
    RESOURCES += $$PWD/WidgetKeyboard.qrc
}

win32 {
    contains(TEMPLATE, lib):contains(CONFIG, shared):DEFINES += WIDGETKEYBOARD_EXPORT
    else:WidgetKeyboard-uselib:DEFINES += WIDGETKEYBOARD_IMPORT
}

