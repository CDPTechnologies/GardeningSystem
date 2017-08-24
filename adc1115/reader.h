#ifndef ADC1115_READER_H
#define ADC1115_READER_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>
#include <CDPSystem/Base/CDPProperty.h>
#include <humidtyreader.h>

namespace adc1115 {

class reader : public CDPComponent, humidtyReader
{
public:
    reader();
    ~reader() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;

protected:
    std::once_flag onceFlag;
    CDPProperty<std::string> adapter;
    CDPSignal<double> humidity;
    CDPProperty<int> slave_adr;
    CDPProperty<short> conf_bit;
    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;
};

} // namespace adc1115

#endif
