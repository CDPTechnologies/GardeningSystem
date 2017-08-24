/**
GardenControl header file. Include this file in the project to use the library.
*/
#ifndef GARDENCONTROL_GARDENCONTROL_H
#define GARDENCONTROL_GARDENCONTROL_H

#include "GardenControlBuilder.h"

namespace GardenControl {

/** Instantiate the GardenControlBuilder for this object */
GardenControlBuilder gGardenControlBuilder("GardenControl", __TIMESTAMP__);

}

#endif // GARDENCONTROL_GARDENCONTROL_H
