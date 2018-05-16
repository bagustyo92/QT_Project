infile(config.pri, SOLUTIONS_LIBRARY, yes): CONFIG += WidgetKeyboard-uselib
TEMPLATE += fakelib
WIDGETKEYBOARD_LIBNAME = $$qtLibraryTarget(WidgetKeyboard-1.0)
TEMPLATE -= fakelib
WIDGETKEYBOARD_LIBDIR = $$PWD/lib
unix:WidgetKeyboard-uselib:!WidgetKeyboard-buildlib:QMAKE_RPATHDIR += $$WIDGETKEYBOARD_LIBDIR
