#include <catch2/catch_test_macros.hpp>

#include "../src/csv.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>


TEST_CASE("file_to_prefvect", "[weight=1]") {
    std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");

    for (unsigned a = 2; a < prefs.size(); a++) { 
        for (unsigned b = 0; b < prefs[a].size(); b++) {
            REQUIRE(prefs[a][b] >= 0); 
            REQUIRE(prefs[a][b] <= 10); 
        }
    }

    for(unsigned i = 0; i < prefs[0].size(); i++) { 
        REQUIRE(prefs[0][i] >= 0);
        REQUIRE(prefs[0][i] <= 1);
    }

    // std::vector<int> first_vec_ans = {0,21,2,1,1,7,7,2};
    // for(unsigned j = 0; j < first_vec_ans.size(); j++){ 
    //     REQUIRE(prefs[0][j] == first_vec_ans[j]);
    // } 

    // std::vector<int> last_vec_ans = {1,25,2,8,7,6,7,7}; 
    // for(unsigned j = 0; j < last_vec_ans.size(); j++){ 
    //     REQUIRE(prefs[prefs.size()][j] == last_vec_ans[j]);
    // } 

    // REQUIRE(prefs.size() == 545);
}


TEST_CASE("file_to_attribvect", "[weight=1]") {
    std::vector<std::vector<int>> attribs  = file_to_attribvect("../tests/CS225_matchmaking.csv");
    for (unsigned a = 2; a < attribs.size(); a++) { 
        for (unsigned b = 0; b < attribs[a].size(); b++) {
            REQUIRE(attribs[a][b] > -1); 
            REQUIRE(attribs[a][b] <= 10); 
        }
    }


    for(unsigned i = 0; i < attribs[0].size(); i++) { 
        REQUIRE(attribs[0][i] >= 0);
        REQUIRE(attribs[0][i] <= 1);
    }

    // std::vector<int> first_vec_ans = {0,21,4,6,8,8,8,7}; 

    // for(unsigned j = 0; j < first_vec_ans.size(); j++){ 
    //     REQUIRE(attribs[0][j] == first_vec_ans[j]);
    // } 

    // std::vector<int> last_vec_ans = {1,25,4,4,6,8,2,8};
    
    // for(unsigned j = 0; j < last_vec_ans.size(); j++){ 
    //     REQUIRE(attribs[attribs.size()]][j] == last_vec_ans[j]);
    // }

    // REQUIRE(attribs.size() == 545);
}

TEST_CASE("file_to_ids", "[weight=1]") {


    std::vector<int> ids  = file_to_ids("../tests/CS225_matchmaking.csv");

    std::vector<int> answer; 
    for (int i = 1; i < 28; i++) { 
        answer.push_back(i); 
    }
    for(int a = 29; a < 58; a++) { 
        answer.push_back(a); 
    }
    for(int a = 60; a < 118; a++) { 
        answer.push_back(a); 
    }
    for(int a = 119; a < 136; a++) { 
        answer.push_back(a); 
    }
    for(int a = 137; a < 339; a++) { 
        answer.push_back(a); 
    }
    for(int a = 341; a < 346; a++) { 
        answer.push_back(a); 
    }
    for(int a = 347; a < 553; a++) { 
        answer.push_back(a); 
    }
    
    for (unsigned j = 0; j < answer.size(); j++) { 
        REQUIRE(ids[j] == answer[j]);
    }
    
}



