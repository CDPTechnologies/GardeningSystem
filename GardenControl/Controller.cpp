
#include "Controller.h"

using namespace GardenControl;

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Create(const char* fullName)
{
    CDPComponent::Create(fullName);
    Ncyle.Create("Ncyle",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)&Controller::cyleChange,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    delayTime.Create("DelayTime",this);
    waterSwitch.Create("water_switch",this);
    reqHumidity.Create("reqHumidity",this);
    isDay.Create("isDay",this);
    cyle.Create("cyle",this);
    cycleName.Create("cylceName",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    lastIrrigation.Create("lastIrrigation",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    humidity.Create("humidity",this);
    newReqHumidity.Create("newReqHumidity",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)&Controller::setNewReqHumidity,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    tempName.Create("tempName",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)&Controller::setNewValues,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
}

void Controller::CreateModel()
{
    CDPComponent::CreateModel();

    RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&Controller::ProcessNull, "Initial Null state");
    RegisterStateProcess("Water",(CDPCOMPONENT_STATEPROCESS)&Controller::ProcessWater,"");
    RegisterStateProcess("wait",(CDPCOMPONENT_STATEPROCESS)&Controller::Processwait,"");
    RegisterStateTransitionHandler("Null","Water",(CDPCOMPONENT_STATETRANSITIONHANDLER)&Controller::TransitionNullToWater,"");
    RegisterStateTransitionHandler("Water","Null",(CDPCOMPONENT_STATETRANSITIONHANDLER)&Controller::TransitionWaterToNull,"");
    RegisterStateTransitionHandler("Null","wait",(CDPCOMPONENT_STATETRANSITIONHANDLER)&Controller::TransitionNullTowait,"");
    RegisterStateTransitionHandler("wait","Water",(CDPCOMPONENT_STATETRANSITIONHANDLER)&Controller::TransitionwaitToWater,"");
    RegisterStateTransitionHandler("Water","wait",(CDPCOMPONENT_STATETRANSITIONHANDLER)&Controller::TransitionWaterTowait,"");
    RegisterMessage(CM_TEXTCOMMAND,"TO_WATER","",(CDPOBJECT_MESSAGEHANDLER)&Controller::MessageTO_WATER);
    RegisterMessage(CM_TEXTCOMMAND,"TO_WAIT","",(CDPOBJECT_MESSAGEHANDLER)&Controller::MessageTO_WAIT);
}

void Controller::Configure(const char* componentXML)
{
    CDPComponent::Configure(componentXML);
}

void Controller::ProcessNull()
{
    requestedState = "Water";
}



void Controller::ProcessWater()
{
    delayTime.Restart();

    waterSwitch = 1;

    time_t currentTime;

    time( &currentTime );

    lastIrrigation = asctime(localtime( &currentTime )); // Adds the date of the irrigation to the GUI

    requestedState = "wait";

}

bool Controller::dayTime()
{
    time_t currentTime;

    time( &currentTime );

    return ((localtime(&currentTime)->tm_hour < 20) ? 1 : 0); // Checks if the hour is in the range  x < 20 -> [X:XX - 20:00]
}

void Controller::Processwait()
{
    waterSwitch = ( delayTime.TimeElapsed() > 15.0 ) ? 0 : 1; // checks if water tank has been open for 15 seconds.

    if((humidity < reqHumidity ) && (cyle == dayTime())) { // check humidity levels against req Humidity and checks if its the right time to irrigate
        requestedState = "Water";
    }

}



bool Controller::TransitionNullToWater()
{
    if(requestedState=="Water")
        return true;
    else
        return false;
}



bool Controller::TransitionWaterToNull()
{
    if(requestedState=="Null")
        return true;
    else
        return false;
}



bool Controller::TransitionNullTowait()
{
    if(requestedState=="wait")
        return true;
    else
        return false;
}



bool Controller::TransitionwaitToWater()
{
    if(requestedState=="Water")
        return true;
    else
        return false;
}



bool Controller::TransitionWaterTowait()
{
    if(requestedState=="wait")
        return true;
    else
        return false;
}



int Controller::MessageTO_WATER(void* message)
{
    requestedState = "Water";
    return 1;

}



int Controller::MessageTO_WAIT(void* message)
{
    requestedState = "WAIT";
    return 1;

}

void Controller::setNewValues(CDPPropertyBase* pProperty)
{
    if(pProperty->GetValue() == "Citrus Tree")
    {
        reqHumidity = 50;
        cyle = 1;
    }
    else if(pProperty->GetValue() == "Cactus")
    {
        reqHumidity = 35;
        cyle = 1;
    }
    else if(pProperty->GetValue() == "Dragon tree")
    {
        reqHumidity = 65;
        cyle = 1;
    }
    else if(pProperty->GetValue() == "Cast-iron plant")
    {
        reqHumidity = 75;
        cyle = 1;
    }
    else if(pProperty->GetValue() == "Custom")
    {
        reqHumidity = 0;
        cyle = 0;
    }
}


void Controller::setNewReqHumidity(CDPPropertyBase* pProperty)
{
    reqHumidity = std::stof(pProperty->GetValue().c_str());
}


void Controller::cyleChange(CDPPropertyBase* pProperty)
{
    cyle = std::stof(pProperty->GetValue().c_str());
    cycleName = (cyle) ? "Day" : "Night";

}

