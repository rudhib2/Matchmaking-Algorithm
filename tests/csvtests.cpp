#include <catch2/catch_test_macros.hpp>
 
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "csv.h"
 
TEST_CASE("file_to_prefvect", "[weight=1]") {
    std::vector<std::string> prefs  = file_to_prefvect("../tests/data/c5_s10_3_roster.csv");
 
    const std::vector<std::string> answer = {"gender_pref", "age_pref", "race_pref", "attr_pref", "sinc_pref", "intel_pref", "fun_pref", "amb_pref"};
   
    REQUIRE(prefs == answer);
}
 
 
TEST_CASE("file_to_attribvect", "[weight=1]") {
    std::vector<std::string> attribs  = file_to_attribvect("../tests/data/c5_s10_3_roster.csv");
 
    const std::vector<std::string> answer = {"gender", "age", "race", "attr_attrib", "sinc_attrib", "intel_attrib", "fun_attrib", "amb_attrib"};
   
    REQUIRE(attribs == answer);
}
 
TEST_CASE("file_to_ids", "[weight=1]") {
 
 
    std::vector<std::string> ids  = file_to_ids("../tests/data/c5_s10_3_roster.csv");
 
    std::vector<int> answer;
    for (int i = 1; i < 553; i++) {
        answer.push_back(i);
    }
   
    REQUIRE(ids == answer);
}
 
