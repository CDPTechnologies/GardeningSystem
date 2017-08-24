/**
GardenControlBuilder implementation.
*/

#include "Controller.h"
#include "GardenControlBuilder.h"

using namespace GardenControl;

GardenControlBuilder::GardenControlBuilder(const char* libName, const char* timeStamp)
    : CDPBuilder(libName, timeStamp)
{
}

CDPComponent* GardenControlBuilder::CreateNewComponent(const std::string& type)
{
    if (type=="GardenControl.Controller")
        return new Controller;

    return CDPBuilder::CreateNewComponent(type);
}

CDPBaseObject* GardenControlBuilder::CreateNewCDPOperator(const std::string& modelName, const std::string& type, const CDPPropertyBase* inputProperty)
{
    return CDPBuilder::CreateNewCDPOperator(modelName, type, inputProperty);
}
