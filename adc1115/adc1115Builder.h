/**
adc1115Builder header file.
*/

#ifndef adc1115_adc1115BUILDER_H
#define adc1115_adc1115BUILDER_H

#include <CDPSystem/Application/CDPBuilder.h>

namespace adc1115 {

class adc1115Builder : public CDPBuilder
{
public:
    adc1115Builder(const char* libName,const char* timeStamp);
    CDPComponent* CreateNewComponent(const std::string& type) override;
    CDPBaseObject* CreateNewCDPOperator(const std::string& modelName,const std::string& type,const CDPPropertyBase* inputProperty) override;
};

}

#endif // adc1115_adc1115BUILDER_H
