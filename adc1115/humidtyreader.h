#ifndef ADC1115_HUMIDTYREADER_H
#define ADC1115_HUMIDTYREADER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>    // read/write usleep
#include <stdlib.h>    // exit function
#include <inttypes.h>  // uint8_t, etc
#include <mutex>


#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>
#include <CDPSystem/Base/CDPProperty.h>


namespace adc1115 {

class humidtyReader
{
public:
    humidtyReader();
    ~humidtyReader();
    int fd;
    short readHumidity();
    int configureHumidity(short *cnf, int asd_adr, std::string adapter);
    int closeHumidity();


};

} // namespace adc1115

#endif // ADC1115_HUMIDTYREADER_H
