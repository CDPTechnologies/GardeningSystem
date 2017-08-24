TYPE = application
PROJECTNAME = System

DEPS += gpiopinio gardencontrol \
    adc1115

HEADERS += Libraries.h
SOURCES += CDPMain.cpp

DISTFILES += \
    $$files(*.xml, true) \
    $$files(*.lic, true) \
    $$files(Application/www/*.*, true)

load(cdp)
