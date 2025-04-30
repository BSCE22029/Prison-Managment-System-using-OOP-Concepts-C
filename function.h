#ifndef PROJECT_GROUP_HHH_FUNCTION_H
#define PROJECT_GROUP_HHH_FUNCTION_H

#include "civilian.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
void writeCivilianDataToFile( Civilian civilian);
Civilian readCivilianDataFromFile();

#endif //PROJECT_GROUP_HHH_FUNCTION_H