CDPVERSION = 4.2
TYPE = library
PROJECTNAME = adc1115

DEPS += \

HEADERS += \
    reader.h \
    humidtyreader.h \
    adc1115.h \
    adc1115Builder.h

SOURCES += \
    reader.cpp \  
    adc1115Builder.cpp
	
linux*:SOURCES += \
    Linux/humidtyreader.cpp

win*:SOURCES += \
    Win/humidtyreader.cpp

DISTFILES += $$files(*.xml, true) \
    Templates/Models/adc1115.reader.xml \
    Templates/Models/adc1115.humidity.xml

load(cdp)
