#ifndef GARDENCONTROL_CONTROLLER_H
#define GARDENCONTROL_CONTROLLER_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>
#include <CDPSystem/Base/CDPProperty.h>
#include <OSAPI/Timer/CDPParameterTimer.h>

namespace GardenControl {

class Controller : public CDPComponent
{
public:
    Controller();
    ~Controller() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;
    void ProcessWater();
    void Processwait();
    bool TransitionNullToWater();
    bool TransitionWaterToNull();
    bool TransitionNullTowait();
    bool TransitionwaitToWater();
    bool TransitionWaterTowait();
    int MessageTO_WATER(void* message);
    int MessageTO_WAIT(void* message);

protected:
    void setNewValues(CDPPropertyBase* pProperty);
    void setNewReqHumidity(CDPPropertyBase* pProperty);
    void cyleChange(CDPPropertyBase* pProperty);
    bool isDayy();
    CDPProperty<bool> Ncyle;
    CDPParameterTimer DelayTime;
    CDPSignal<bool> water_switch;
    CDPSignal<double> reqHumidity;
    CDPSignal<bool> isDay;
    CDPSignal<bool> cyle;
    CDPProperty<std::string> cycleName;
    CDPProperty<std::string> lastIrrigation;
    CDPSignal<double> humidity;
    CDPProperty<double> newReqHumidity;
    CDPProperty<std::string> tempName;
    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;
};

} // namespace GardenControl

#endif
