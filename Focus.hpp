#ifndef __FOCUSHPP__
#define __FOCUSHPP__
#include "Focus.h"

Focus::Focus() {
    test = 3;
    breadth_modules = new std::vector<std::string>();
    depth_modules = new std::vector<std::string>();
}

std::string to_string(std::vector<std::string> *input) {
    std::string output = ""; 
    std::cout << input -> size() << std::endl;
    for (std::vector<std::string>::const_iterator i = input->begin(); i != input->end(); ++i) {
        output.append(*i + "\n");
        std::cout << *i << std::endl;
    }
    return output;
}

std::ostream& operator<<(std::ostream& os, const Focus& focus) {
    return os << "Focus: " << focus.focus_id << std::endl 
                << "Breadth: " << std::endl << to_string(focus.breadth_modules) << std::endl
                << "Depth: " << std::endl << to_string(focus.depth_modules) << std::endl;
}

#endif