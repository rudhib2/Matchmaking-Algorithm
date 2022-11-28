#pragma once
#include <vector>
using std::vector;

class BFS::Graph {
    public:
     BFS(); 
     public vector<bool> isCompatible(int id1, int id2); // returns yes or no if the score of the ids are within the range
     public vector<vector<bool>> populate(vector<int> id); // returns a vector of booleans of with denote compatibility
     BFS(int id1); 


      // part 2 :
      //public map<int, vector<int>> compList (vector<vector<bool>>); 
      // gives a map which maps the id to the id of people that they are compabtibl with 
 


    private:
     vector<int> id; // contains the id 

     vector<vector<int>> pref; // contains the preference of each person correspoding to id 
     vector<vector<int>> attr; // contains the attribute of each person correspoding to id 
     vector<vector<bool>> compat;

     vector<int> pref_score; // contains the preference score of each person correspoding to id 
     vector<int> attr_score; // contains the attribute score of each person correspoding to id 

}