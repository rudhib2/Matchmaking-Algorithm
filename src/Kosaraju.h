#include <vector>
#include <list>
#include <stack>
 

std::vector<std::vector<int>> adjacency(std::vector<int> attrib_scores, std::vector<int> pref_scores);
std::vector<std::vector<int>> revadjacency(std::vector<int> attrib_scores, std::vector<int> pref_scores);
void dfs_1(int x); 
void dfs_2(int x); 
int Kosaraju(int n);
