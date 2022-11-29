

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "csv.h"
#include <algorithm>

#include <fstream>
#include <list>

//edit the excel sheet to get rid of shar_pref and make relationship type col 9


std::vector<std::vector<int>> file_to_prefvect(const std::string & filename){
    //lists to store preferences and attributes column nmaes
    std::list<std::string> pref_list = {"gender_pref", "age_pref", "race_pref", "attr_pref", "sinc_pref", "intel_pref", "fun_pref", "amb_pref", "shar_pref"};
    //std::list<std::string> attrib_list = {"gender", "age", "race", "attr_attrib", "sinc_attrib", "intel_attrib", "fun_attrib", "amb_attrib", "shar_pref"};
    // Your code here!
    std::vector<std::vector<int>> vect;
    std::ifstream file(filename);
    while (file) {
        std::string line;
        if (!getline(file, line)) {
            break;
        }
        std::istringstream ss(line);
        std::vector<int> preferences;

        while(ss) {
            std::string s;
            if (!getline(ss, s, ',')) {
                break;
            }
            int counter = 0;
            while (counter >= 8) {
                preferences.push_back(stoi(s));
                counter++;
            }
        }
        vect.push_back(preferences);
    }
    return vect;
}

std::vector<std::vector<int>> file_to_attribvect(const std::string & filename){
    std::vector<std::vector<int>> vect;
    std::ifstream file(filename);
    while (file) {
        std::string line;
        if (!getline(file, line)) {
            break;
        }
        std::istringstream ss(line);
        std::vector<int> attributes;

        while(ss) {
            std::string s;
            if (!getline(ss, s, ',')) {
                break;
            }
            int counter = 0;
            while (1 <= counter <= 8) {
                attributes.push_back(stoi(s));
                counter++;
            }
        }
        vect.push_back(attributes);
    }
    return vect;
}


std::vector<int> file_to_ids(const std::string & filename) {
    std::vector<int> vect;
    std::ifstream file(filename);
    int counter = 0;
    while (file) {
        std::string line;
        if (!getline(file, line)) {
            break;
        }
        std::istringstream ss(line);
        while(ss) {
            std::string s;
            if (!getline(ss, s, ',')) {
                break;
            }
            while (counter == 0) {
                vect.push_back(stoi(s));
                counter++;
            }
        }
        counter = 0;
    }
    return vect;
}