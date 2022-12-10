// Populate Test Cases
// Check if pref vector and attrib vector are populated correctly
// Check if pref score is being calculated from pref vector correctly
// Check if attrib score is being calculated from attrib vector correctly

//CALCULATING PREF & ATTRIB SCORES
TEST_CASE("CalcPrefScore Test 1 ~ test first 10 IDs", "[weight=1]") {
    std::cout << "test working" << std::endl;
    //std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");
    std::cout << "here" << std::endl;
        REQUIRE(pref_score[0] = 180);
        REQUIRE(pref_score[1] = 360);
        REQUIRE(pref_score[2] = 340);
        REQUIRE(pref_score[3] = 370);
        REQUIRE(pref_score[4] = 180);
        REQUIRE(pref_score[5] = 320);
        REQUIRE(pref_score[6] = 240);
        REQUIRE(pref_score[7] = 350);
        REQUIRE(pref_score[8] = 320);
        REQUIRE(pref_score[9] = 290);
}

TEST_CASE("CalcAttribScore Test 1 ~ test first 10 IDs", "[weight=1]") {
    std::cout << "test working" << std::endl;
    //std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");
    std::cout << "here" << std::endl;
        REQUIRE(attrib_score[0] = 356);
        REQUIRE(attrib_score[1] = 474);
        REQUIRE(attrib_score[2] = 114);
        REQUIRE(attrib_score[3] = 271);
        REQUIRE(attrib_score[4] = 474);
        REQUIRE(attrib_score[5] = 458);
        REQUIRE(attrib_score[6] = 509);
        REQUIRE(attrib_score[7] = 427);
        REQUIRE(attrib_score[8] = 356);
        REQUIRE(attrib_score[9] = 271);
}
