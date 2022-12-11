
// #pragma once
// #include <vector>
// using std::vector;

// class BFS::Graph {
//     public:
//      BFS(); 
//      public vector<bool> isCompatible(int id1, int id2); // returns yes or no if the score of the ids are within the range
//      public vector<vector<bool>> populate(vector<int> id); // returns a vector of booleans which denote compatibility
//      BFS(int id1); 
//      bool PrelimCheck(int id1, int id2);

//       // part 2 :
//       //public map<int, vector<int>> compList (vector<vector<bool>>); 
//       // gives a map which maps the id to the id of people that they are compatible with 

// }

#pragma once
#include <vector>
using namespace std; 

class Traversal{ 
    public: 
     bool isCompatible(int id1, int id2); // returns yes or no if the score of the ids are within the range
     std::vector<std::vector<bool>> populate(); // returns a vector of booleans which denote compatibility
     bool PrelimCheck(int id1, int id2);
     void store_values(); 
     std::vector<std::vector<int>> adjacency_matrix();
     std::vector<int> compat_list();

    std::vector<int> id; 
    std::vector<int> pref_score; // contains the preference score of each person correspoding to id 
    std::vector<int> attr_score; // contains the attribute score of each person correspoding to id 
    std::vector<std::vector<int>> pref;
    std::vector<std::vector<int>> attr;
    std::vector<std::vector<int>> adj_matrix; 
};

