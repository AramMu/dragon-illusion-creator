TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

    LIBS += c:\\opencv_3_1_0\\x86\\mingw\\lib\\libopencv_world310.dll.a
    INCLUDEPATH +=c:\\opencv_3_1_0\\include

CONFIG(release, debug|release) {
    DEFINES += "NDEBUG"
}

SOURCES += main.cpp \
    edgedetector.cpp \
    segment.cpp \
    calc.cpp \
    utility.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    edgedetector.h \
    segment.h \
    calc.h \
    utility.h

