/**
adc1115 header file. Include this file in the project to use the library.
*/
#ifndef ADC1115_ADC1115_H
#define ADC1115_ADC1115_H

#include "adc1115Builder.h"

namespace adc1115 {

/** Instantiate the adc1115Builder for this object */
adc1115Builder gadc1115Builder("adc1115", __TIMESTAMP__);

}

#endif // ADC1115_ADC1115_H
