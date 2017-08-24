#include "humidtyreader.h"

namespace adc1115 {

humidtyReader::humidtyReader()
{
}
humidtyReader::~humidtyReader()
{
}
short humidtyReader::readHumidity()
{
    CDPMessage("Doesn't Support Windows");
    return 0;
}
int humidtyReader::configureHumidity(short *cnf, int asd_adr, std::string adapter)
{
    CDPMessage("Doesn't Support Windows");
    return 0;
}
int humidtyReader::closeHumidity()
{
    CDPMessage("Doesn't Support Windows");
    return 0;
}
} // namespace adc1115

