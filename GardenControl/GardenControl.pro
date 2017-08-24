CDPVERSION = 4.2
TYPE = library
PROJECTNAME = GardenControl

DEPS += \

HEADERS += \
    gardencontrol.h \
    GardenControlBuilder.h \
    Controller.h

SOURCES += \
    GardenControlBuilder.cpp \
    Controller.cpp

DISTFILES += $$files(*.xml, true) \
    Templates/Models/GardenControl.Controller.xml

load(cdp)
