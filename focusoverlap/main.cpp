#include <iostream>
#include <fstream>
#include "Focus.h"
#include "commons.h"

std::map<std::string, int> *name_to_id = new std::map<std::string, int>;
void init_map() {
    name_to_id->insert(std::pair<std::string, int>("Communications & Networking", COMMS));
    name_to_id->insert(std::pair<std::string, int>("Embedded Computing", MBED));
    name_to_id->insert(std::pair<std::string, int>("Intelligent Systems", INTEL));
    name_to_id->insert(std::pair<std::string, int>("Interactive Digital Media", DIGI));
    name_to_id->insert(std::pair<std::string, int>("Large-Scale Computing", LARGE));
    name_to_id->insert(std::pair<std::string, int>("System-On-A-Chip Design", SOC));
    name_to_id->insert(std::pair<std::string, int>("Internet of Things", IOT));
    
}

void get_overlapping_modules(Focus* one, Focus* two) {
    std::cout   << "Comparing: " << std::endl
                << one->focus_name << ", "
                << two->focus_name << std::endl
                << std::string(10, '*') << std::endl;
    for (auto & i : *(one->breadth_modules)) {
        for (auto & j : *(two->breadth_modules)) {
            if (!i.compare(j)) {
                std::cout << "Breadth:" << std::string(15, '>') + " "<< i << std::endl;
            }
        }
    }

    for (auto & i : *(one->depth_modules)) {
        for (auto & j : *(two->depth_modules)) {
            if (!i.compare(j)) {
                std::cout << "Depth:" << std::string(15, '>') + " "<< i << std::endl;
            }
        }
    }

    for (auto & i : *(one->depth_modules)) {
        for (auto & j : *(two->breadth_modules)) {
            if (!i.compare(j)) {
                std::cout << "BD:" << std::string(15, '>') + " "<< i << std::endl;
            }
        }
    }

    for (auto & i : *(two->depth_modules)) {
        for (auto & j : *(one->breadth_modules)) {
            if (!i.compare(j)) {
                std::cout << "DB:" << std::string(15, '>') + " "<< i << std::endl;
            }
        }
    }
}

int main() {
    std::ifstream MyInfo("/home/kaiwen98/Coding/info.txt");
    std::string text;

    std::regex module_regex(MOD_REGEXP);
    std::regex focus_regex(FOCUS_REGEXP);
    std::regex breadth_regex(BREADTH_REGEXP, std::regex_constants::ECMAScript | std::regex_constants::icase);
    std::regex depth_regex(DEPTH_REGEXP, std::regex_constants::ECMAScript | std::regex_constants::icase);
    bool is_breadth = true;
    int index = -1;
    std::vector<Focus *> list_of_focii;
    std::vector<Focus *>::iterator it = list_of_focii.begin();


    for (int i = 0; i < 7 ; i++) {
        list_of_focii.push_back(new Focus());
    }
    std::cout << list_of_focii.size() << std::endl;
    Focus *temp_focus = list_of_focii.at(0);

    init_map();

    while (getline(MyInfo, text)) { 
        
        if (!text.length()) continue;
        if (index > 6) break;
        else if (std::regex_search(text, breadth_regex)) {
            is_breadth = true;
        }

        else if (std::regex_search(text, depth_regex)) {
            is_breadth = false;
        }

        else if (std::regex_search(text, module_regex)) {
            if (is_breadth) {
                temp_focus->breadth_modules->push_back(text);
            } else {
                temp_focus->depth_modules->push_back(text);
            }
        }

        else if (std::regex_search(text, focus_regex)) {
            index++;    
            temp_focus = list_of_focii.at(index);
            temp_focus->focus_id = name_to_id->at(text);
            temp_focus->focus_name = text;
        }
    }
    std::cout << *(list_of_focii.at(6)) << std::endl;
    std::cout << "done" << std::endl;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7 && j != i; j++) {
            get_overlapping_modules(
                (list_of_focii.at(i)),
                (list_of_focii.at(j))
            );
        }
    }

}