#include "BFS.h"
#include "Graph.h"
#include "csv.h"

#include <vector>


public:

public void setId(const std::string & filename);
public void setPrefVect(const std::string & filename);
public void setAttribVect(const std::string & filename);
public void CalcPrefScore(std::vector<std::vector<int>> pref);
public void CalcAttribScore(std::vector<std::vector<int>> attrib);

     vector<int> id; // contains the id 

     vector<vector<int>> pref; // contains the preference of each person correspoding to id 
     vector<vector<int>> attr; // contains the attribute of each person correspoding to id 
     vector<vector<bool>> compat;

     vector<int> pref_score; // contains the preference score of each person correspoding to id 
     vector<int> attr_score; // contains the attribute score of each person correspoding to id 