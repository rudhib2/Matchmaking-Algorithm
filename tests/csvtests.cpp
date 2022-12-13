#include <catch2/catch_test_macros.hpp>

#include "../src/csv.h"
#include "../src/Kosaraju.h"
#include "../src/BFS.h"
#include "../src/Graph.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

TEST_CASE("check_if_clean", "[weight = 1]") { 
    std::vector<std::vector<int>> prefs = file_to_prefvect("../tests/CS225_matchmaking.csv");
    std::vector<std::vector<int>> attribs = file_to_attribvect("../tests/CS225_matchmaking.csv");

    for (unsigned a = 0; a < prefs.size(); a++) { 
        for (unsigned b = 0; b < prefs[a].size(); b++) {
            std::string converted = std::to_string(prefs[a][b]); 
            REQUIRE(converted != " ");  
            REQUIRE(prefs[a].size() == 8); 
        }
    }

    for (unsigned c = 0; c < attribs.size(); c++) { 
        for (unsigned d = 0; d < attribs[c].size(); d++) {
            std::string converted = std::to_string(attribs[c][d]); 
            REQUIRE(converted != " ");  
            REQUIRE(attribs[c].size() == 8); 
        }
    }
}


TEST_CASE("file_to_prefvect", "[weight=1]") {
    std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");

    for (unsigned a = 0; a < prefs.size(); a++) { 
        for (unsigned b = 2; b < prefs[a].size(); b++) {
            REQUIRE(prefs[a][b] >= 0); 
            REQUIRE(prefs[a][b] <= 10); 
        }
    }

    for(unsigned i = 0; i < prefs.size(); i++) { 
        REQUIRE(prefs[i][0] >= 0);
        REQUIRE(prefs[i][0] <= 1);
    }

    std::vector<int> last_vec_ans = {1,25,4,4,6,8,2,8};
    
    for(unsigned j = 0; j < last_vec_ans.size(); j++){ 
        REQUIRE(prefs[prefs.size() - 1][j] == last_vec_ans[j]);
    }

    std::vector<int> first_vec_ans = {0,21,2,1,1,7,7,2};
    for(unsigned j = 0; j < first_vec_ans.size(); j++){  
        REQUIRE(prefs[0][j] == first_vec_ans[j]);
    }  

    REQUIRE(prefs.size() == 544);
}


TEST_CASE("file_to_attribvect", "[weight=1]") {
    std::vector<std::vector<int>> attribs  = file_to_attribvect("../tests/CS225_matchmaking.csv");
for (unsigned a = 0; a < attribs.size(); a++) { 
        for (unsigned b = 2; b < attribs[a].size(); b++) {
            REQUIRE(attribs[a][b] >= 0); 
            REQUIRE(attribs[a][b] <= 10); 
        }
    }


for(unsigned i = 0; i < attribs.size(); i++) { 
        REQUIRE(attribs[i][0] >= 0);
        REQUIRE(attribs[i][0] <= 1);
    }

    std::vector<int> first_vec_ans = {0,21,4,6,8,8,8, 7}; 

    for(unsigned j = 0; j < first_vec_ans.size(); j++){ 
        REQUIRE(attribs[0][j] == first_vec_ans[j]);
    } 

    std::vector<int> last_vec_ans = {1,25,2,8,7,6,7,7};
    
    for(unsigned j = 0; j < last_vec_ans.size(); j++){ 
        REQUIRE(attribs[attribs.size() - 1][j] == last_vec_ans[j]);
    }

    REQUIRE(attribs.size() == 544);
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

std::vector<std::vector<int>> pref = file_to_prefvect("../tests/CS225_matchmaking.csv"); 
std::vector<std::vector<int>> attr = file_to_attribvect("../tests/CS225_matchmaking.csv"); 
std::vector<int> id = file_to_ids("../tests/CS225_matchmaking.csv");
std::vector<int> pref_score = CalcPrefScore(pref);
std::vector<int> attr_score = CalcAttribScore(attr);
Traversal trav =  Traversal();

TEST_CASE("BFS Test 1 ~ Compatible-basic", "[weight=1]") { 
        REQUIRE(pref_score[4] == 180);
        REQUIRE(attr_score[14] == 390);
        REQUIRE(trav.isCompatible(4, 14) == false);
}

TEST_CASE("BFS Test 1 ~ Not Compatible-prelim fails", "[weight=1]") {
    
        REQUIRE(pref[6][1] == 22);  //1-gender
        REQUIRE(pref[6][2] == 2);   //2-age
        REQUIRE(pref[6][0] == 0);   //0-rel_type
        REQUIRE(trav.PrelimCheck(6, 10) == false);
}

TEST_CASE("BFS Test 1 ~ Not Compatible-pass prelim fail threshold", "[weight=1]") {
   
    //A's pref:
        REQUIRE(pref[1][1] == 24);  //1-gender
        REQUIRE(pref[1][2] == 2);   //2-age
        REQUIRE(pref[1][3] == 8);   //3-race
        REQUIRE(pref[1][0] == 0);   //0-rel_type

    //B's attribs:
        REQUIRE(pref[34][0] == 0);  //0-gender
        REQUIRE(pref[34][1] == 26);   //1-age
        REQUIRE(pref[34][2] == 4);   //2-race
        REQUIRE(pref[34][7] == 9);   //8-rel_type
        REQUIRE(trav.PrelimCheck(1, 34) == false);

        REQUIRE(pref_score[1] == 360);
        REQUIRE(attr_score[34] == 370);
        REQUIRE(trav.isCompatible(1, 34) == false);
}

TEST_CASE("BFS Test 1 ~ Not Compatible-same id", "[weight=1]") {

        REQUIRE(trav.isCompatible(4, 4) == false);
}


TEST_CASE("check_Kosaraju_with_five_people", "[weight = 1]") {  
    int ans = Kosaraju(5);
    // numComponents identified in Kosaraju must be greater than 0 
    // at the least, every node is connected to itself
    REQUIRE(ans > 0); 
    // Connected Components calculated if pref score is less than attrib score: 
    // person 1 
    // person 4 
    // person 2, 3, and 5 
    REQUIRE(ans == 3); 
}


TEST_CASE("Djikstra Test 1 ~ Compatible", "[weight=1]") {
    std::vector<int> vect;
    Graph g = Graph(545); 
    std::vector<std::vector<int>> adj_matrix = trav.adjacency_matrix();
    vect = g.dijkstra(adj_matrix, 4); 
    
    REQUIRE(std::find(vect.begin(), vect.end(), 12) != vect.end());
    REQUIRE(std::find(vect.begin(), vect.end(), 40) != vect.end());
    REQUIRE(std::find(vect.begin(), vect.end(), 49) != vect.end());
    REQUIRE(std::find(vect.begin(), vect.end(), 433) != vect.end());
    REQUIRE(std::find(vect.begin(), vect.end(), 78) == vect.end());
    REQUIRE(std::find(vect.begin(), vect.end(), 8) == vect.end());
        
}


