#pragma once
#include <vector>
using std::vector;

class Traversal{ 
     bool isCompatible(int id1, int id2); // returns yes or no if the score of the ids are within the range
     std::vector<std::vector<bool>> populate(); // returns a vector of booleans which denote compatibility
     bool PrelimCheck(int id1, int id2);
     void store_values(); 

    std::vector<int> id; 
    std::vector<int> pref_score; // contains the preference score of each person correspoding to id 
    std::vector<int> attr_score; // contains the attribute score of each person correspoding to id 
    std::vector<std::vector<int>> pref;
    std::vector<std::vector<int>> attr;
};