
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <string> 

#include "csv.h"
#include <algorithm>

#include <fstream>
#include <list>


std::vector<std::vector<int>> file_to_prefvect(const std::string & filename){
    //lists to store preferences and attributes column nmaes
    //std::list<std::string> pref_list = {"gender_pref", "age_pref", "race_pref", "attr_pref", "sinc_pref", "intel_pref", "fun_pref", "amb_pref", "shar_pref"};
    //std::list<std::string> attrib_list = {"gender", "age", "race", "attr_attrib", "sinc_attrib", "intel_attrib", "fun_attrib", "amb_attrib", "shar_pref"};
    // Your code here!
    std::vector<std::vector<int>> vect;
    std::fstream file(filename);
    int counter = 0;
    std::string line;
    getline(file, line); 
    std::vector<std::string> to_split; 
    while (getline(file, line)) {
        int counter = 0; 
        std::vector<int> result;
        std::stringstream s_stream(line); //create string stream from the string
        while(s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        counter++; 
        if (counter >= 11) {
            result.push_back(std::stoi(substr));
        }
        } 
        vect.push_back(result);  
    }
    return vect;
}

std::vector<std::vector<int>> file_to_attribvect(const std::string & filename){
    std::vector<std::vector<int>> vect;
    std::fstream file(filename);
    int counter = 0;
    std::string line;
    getline(file, line); 
    std::vector<std::string> to_split; 
    while (getline(file, line)) {
        int counter = 0; 
        std::vector<int> result;
        std::stringstream s_stream(line); //create string stream from the string
        while(s_stream.good()) {
            std::string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            counter++; 
            if (counter > 1 && counter < 10) {
                result.push_back(std::stoi(substr));
            }
        }
        vect.push_back(result);
    }
    return vect;
}



std::vector<int> file_to_ids(const std::string & filename) {
    std::vector<int> vect;
    std::fstream file(filename);
    int counter = 0;
    std::string line;
    getline(file, line); 
    while (getline(file, line)) {
        std::istringstream ss(line);
        while(ss) {
            std::string s;
            if (!getline(ss, s, ',')) {
                break;
            }
            while (counter == 0) {
                vect.push_back(std::stoi(s));
                counter++;
            }
        }
        counter = 0;
    }
    return vect;
}


std::vector<int> CalcPrefScore(std::vector<std::vector<int>> pref){
    std::vector<int> pref_score; 
    int pref_s = 0;
    for(unsigned i = 0; i < pref.size(); i++) {
        pref_s = 0; 
        for (unsigned j = 3; j < pref[i].size(); j++) {
            pref_s += pref[i][j];
        }
        pref_s *=10; 
        pref_score.push_back(pref_s);
    }
    return pref_score; 
}

std::vector<int> CalcAttribScore(std::vector<std::vector<int>> attrib){
    std::vector<int> attrib_score; 
    int attrib_s = 0; 
    for(unsigned i = 0; i < attrib.size(); i++) {
        attrib_s = 0; 
        for (unsigned j = 3; j < attrib[i].size(); j++) {
            attrib_s += attrib[i][j]; 
        }
        attrib_s *= 10; 
        attrib_score.push_back(attrib_s);
    }
    return attrib_score; 
}
