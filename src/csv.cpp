
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
    //std::list<std::string> pref_list = {"gender_pref", "age_pref", "race_pref", "attr_pref", "sinc_pref", "intel_pref", "fun_pref", "amb_pref", "shar_pref"};
    //std::list<std::string> attrib_list = {"gender", "age", "race", "attr_attrib", "sinc_attrib", "intel_attrib", "fun_attrib", "amb_attrib", "shar_pref"};
    // Your code here!
    std::vector<std::vector<int>> vect;
    std::fstream file(filename);
    std::string line;
    getline(file, line); 
    std::vector<std::string> to_split; 
    while (getline(file, line)) {
<<<<<<< HEAD
        int counter = 0;
        std:: cout <<"print" << std::endl;
        std::istringstream ss(line);
        std::vector<int> preferences;
        while(ss) {
            std:: cout << "print 2" << std::endl;
            std::string s;
            if (!getline(ss, s, ',')) {
                break;
            }
            if (counter >= 9) {
                preferences.push_back(stoi(s));
            }
            counter++;
=======
        int counter = 0; 
        std::vector<int> result;
        std::stringstream s_stream(line); //create string stream from the string
        while(s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        counter++; 
        if (counter >= 11) {
            result.push_back(std::stoi(substr));
>>>>>>> refs/remotes/origin/main
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
