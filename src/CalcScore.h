#include "BFS.h"
#include "Graph.h"
#include "csv.h"

#include <vector>

void CalcPrefScore(std::vector<std::vector<int>>, std::vector<int>);
void CalcAttribScore(std::vector<std::vector<int>>, std::vector<int>);
std::vector<std::vector<bool>> compat;