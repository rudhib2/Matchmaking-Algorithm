#include <catch2/catch_test_macros.hpp>

#include "../src/BFS.h"
#include "../src/BFS.cpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

TEST_CASE("BFS Test 1 ~ Compatible-basic", "[weight=1]") {
     
        REQUIRE(pref_score[4] = 370);
        REQUIRE(attr_score[14] = 330);
        REQUIRE(isCompatible(4, 14) = true);
}

TEST_CASE("BFS Test 1 ~ Not Compatible-prelim fails", "[weight=1]") {
    
        REQUIRE(pref[6][1] = 1);  //1-gender
        REQUIRE(pref[6][2] = 23);   //2-age
        REQUIRE(pref[6][0] = 2);   //0-rel_type
        REQUIRE(PrelimCheck(6, 10) = false);
}

TEST_CASE("BFS Test 1 ~ Not Compatible-pass prelim fail threshold", "[weight=1]") {
   
    //A's pref:
        REQUIRE(pref[1][1] = 0);  //1-gender
        REQUIRE(pref[1][2] = 21);   //2-age
        REQUIRE(pref[1][3] = 2);   //3-race
        REQUIRE(pref[1][0] = 2);   //0-rel_type

    //B's attribs:
        REQUIRE(pref[34][0] = 0);  //0-gender
        REQUIRE(pref[34][1] = 21);   //1-age
        REQUIRE(pref[34][2] = 2);   //2-race
        REQUIRE(pref[34][8] = 2);   //8-rel_type
        REQUIRE(PrelimCheck(1, 34) = true);

        REQUIRE(pref_score[1] = 180);
        REQUIRE(attr_score[34] = 360);
        REQUIRE(isCompatible(1, 34) = false);
}

TEST_CASE("BFS Test 1 ~ Not Compatible-same id", "[weight=1]") {

        REQUIRE(isCompatible(4, 4) = false);
}


// Compatible Test Cases
// Given a compatible pair – should return compatible
    // Have to pass prelim check & pass threshold check
// Given a not compatible pair – should return not compatible
    // One test case where the pair does not pass prelim check so it should just return not compatible (even if it passes threshold check)
    // One test case where the pair passes prelim check but does not pass threshold check
// Invalid input should return invalid
    // Same id passed in for both 
    // 3 ids passed in instead of 2
    // 1 id passed in instead of 2

/*
TEST CASES ~ manual work (Janani & Rudhi)
    Compatible tests
        Compatible pair
            A ~ 4
            B ~ 14
            Prelims ~
                A’s gender pref = 0
                A’s age pref = 23
                A’s race pref = 2
                A’s rel type = 1
                B’s gender, age, race, rel type = A’s prefs
            Threshold ~
                A’s score (calculated based on A’s prefs) = 9 + 6 + 6 + 9 + 7 = 37 * 10 = 370
                B’s score (calculate based on B’s attribs) = 9 + 9 + 9 + 2 + 4 = 33 * 10 = 330
                Within 100 threshold so compatible
        Not compatible pair – do not pass prelim 
            A ~ 6
            B ~ 10
            Prelims ~
                A’s gender pref = 1
                A’s age pref = 23
                A’s race pref = 2
                A’s rel type = 1
                B’s gender, age, rel type do not pass 
                Does not pass prelim check so not compatible
        Not compatible pair – pass prelim NOT threshold
            A ~ 1
            B ~ 34
            Prelims ~ 
                A’s gender pref = 0
                A’s age pref = 21
                A’s race pref = 2
                A’s rel type = 2
                B’s gender, age, race, rel type = A’s prefs
            Threshold ~
                A’s score (calculated based on A’s prefs) = 1 + 1 + 7 + 7 + 2 = 18 * 100 = 180
                B’s score (calculated based on B’s attribs) = 7 + 7 + 7 + 7 + 8 = 36 = 36 * 100 = 360
                Not within 100 threshold so not compatible
*/
 
