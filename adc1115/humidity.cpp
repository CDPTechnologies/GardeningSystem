#include "humidity.h"

using namespace adc1115;

humidity::humidity()
{
}

humidity::~humidity()
{
}

void humidity::Create(const char* fullName)
{
    CDPComponent::Create(fullName);
    humidityValue.Create("humidity",this);
    Adapter.Create("Adapter",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
}

void humidity::CreateModel()
{
    CDPComponent::CreateModel();

    RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&humidity::ProcessNull, "Initial Null state");
}

void humidity::Configure(const char* componentXML)
{
    CDPComponent::Configure(componentXML);
}

void humidity::ProcessNull()
{

}
