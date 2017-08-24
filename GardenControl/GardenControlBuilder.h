/**
GardenControlBuilder header file.
*/

#ifndef GARDENCONTROL_GARDENCONTROLBUILDER_H
#define GARDENCONTROL_GARDENCONTROLBUILDER_H

#include <CDPSystem/Application/CDPBuilder.h>

namespace GardenControl {

class GardenControlBuilder : public CDPBuilder
{
public:
    GardenControlBuilder(const char* libName,const char* timeStamp);
    CDPComponent* CreateNewComponent(const std::string& type) override;
    CDPBaseObject* CreateNewCDPOperator(const std::string& modelName,const std::string& type,const CDPPropertyBase* inputProperty) override;
};

}

#endif // GARDENCONTROL_GARDENCONTROLBUILDER_H
