#ifndef __FOCUSH__
#define __FOCUSH__
#include "commons.h"

class Focus {
    public:
        std::string focus_name;        
        int focus_id;
        int test;
        std::vector<std::string> *breadth_modules;
        std::vector<std::string> *depth_modules;
        Focus();
        std::string to_string(std::vector<std::string> *input);
        friend std::ostream& operator<<(std::ostream& os, const Focus& focus);

};

#include "Focus.hpp"
#endif