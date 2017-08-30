#include "reader.h"

using namespace adc1115;

reader::reader()
{
    slave_adr.SetValue("0x48");
    adapter.SetValue("/dev/i2c-1");
    conf_bit.SetValue("17635");
}

reader::~reader()
{
}

void reader::Create(const char* fullName)
{
    CDPComponent::Create(fullName);
    adapter.Create("adapter",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    humidity.Create("humidity",this);
    slave_adr.Create("slave_adr",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    conf_bit.Create("conf_bit",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
}

void reader::CreateModel()
{
    CDPComponent::CreateModel();

    RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&reader::ProcessNull, "Initial Null state");
}

void reader::Configure(const char* componentXML)
{
    CDPComponent::Configure(componentXML);
}

void reader::ProcessNull()
{

    short conf = std::stoi(conf_bit.GetValue().c_str());
    int adr = std::stoi(slave_adr.GetValue());
    std::string adapterr = adapter.ToStdString();

    std::call_once(onceFlag, [&] {
        configureHumidity(&conf,adr,adapterr);
    });

    humidity = ((double)this->readHumidity())/(330);

}
