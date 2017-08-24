#ifndef ADC1115_HUMIDITY_H
#define ADC1115_HUMIDITY_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>
#include <CDPSystem/Base/CDPProperty.h>

namespace adc1115 {

class humidity : public CDPComponent
{
public:
    humidity();
    ~humidity() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;

protected:
    CDPSignal<short> humidityValue;
    CDPProperty<std::string> Adapter;
    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;
};

} // namespace adc1115

#endif
