/**
adc1115Builder implementation.
*/

#include "reader.h"
#include "adc1115Builder.h"

using namespace adc1115;

adc1115Builder::adc1115Builder(const char* libName, const char* timeStamp)
    : CDPBuilder(libName, timeStamp)
{
}

CDPComponent* adc1115Builder::CreateNewComponent(const std::string& type)
{
    if (type=="adc1115.reader")
        return new reader;
    
    return CDPBuilder::CreateNewComponent(type);
}

CDPBaseObject* adc1115Builder::CreateNewCDPOperator(const std::string& modelName, const std::string& type, const CDPPropertyBase* inputProperty)
{
    return CDPBuilder::CreateNewCDPOperator(modelName, type, inputProperty);
}
