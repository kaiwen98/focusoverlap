#ifndef __COMMONSH__
#define __COMMONSH__

#include <vector>
#include <map>
#include <regex>
#define COMMS 0
#define MBED 1
#define INTEL 2
#define DIGI 3
#define LARGE 4
#define SOC 5
#define IOT 6

std::string FOCUS_REGEXP = "(\\w+\\s+)";
std::string MOD_REGEXP = "(\\w){2}(\\d){4}(.)+";
std::string BREADTH_REGEXP = "BREADTH";
std::string DEPTH_REGEXP = "DEPTH";

#endif