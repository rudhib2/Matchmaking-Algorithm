
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

TEST_CASE("check_pref_score", "[weight = 1]") { 
    std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");
    std::vector<int> pref_score = CalcPrefScore(prefs); 

    // calculated manually through Excel
    std::vector<int> first_ten_vals = {180, 360, 340, 370, 180, 320, 240, 350, 320, 290}; 
    std::vector<int> last_ten_vals = {270, 300, 270, 230, 290, 310, 190, 250, 270, 280};


    for (int i = 0; i < 10; i++) { 
        REQUIRE(pref_score[i] == first_ten_vals[i]); 
    }

    int k = 0;
    for (unsigned j = pref_score.size() - 10; j < pref_score.size(); j++) { 
            REQUIRE(pref_score[j] == last_ten_vals[k]); 
            k++;
    }
}

TEST_CASE("check_attrib_score", "[weight = 1]") { 
    std::vector<std::vector<int>> attribs  = file_to_attribvect("../tests/CS225_matchmaking.csv");
    std::vector<int> attrib_score = CalcAttribScore(attribs); 

    // calculated manually through Excel
    std::vector<int> first_ten_vals = {370, 330, 420, 390, 330, 340, 310, 350, 370, 390};
    std::vector<int> last_ten_vals = {420, 440, 390, 420, 400, 500, 430, 350, 310, 350}; 

    REQUIRE(attrib_score.size() == 544); 
    
    for (int i = 0; i < 10; i++) { 
        REQUIRE(attrib_score[i] == first_ten_vals[i]); 
    }

     int k = 0;
    for (unsigned j = attrib_score.size() - 10; j < attrib_score.size(); j++) { 
            REQUIRE(attrib_score[j] == last_ten_vals[k]); 
            k++;
    }
}




