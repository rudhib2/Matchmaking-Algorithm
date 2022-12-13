#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <stack> 
#include "Kosaraju.h"
#include <algorithm>
#include "csv.h"

 bool visited[544];  
 std::vector <int> components[544];
 std::stack<int> S;
 int component[544];
 int numComponents;
 std::vector<std::vector<int>> adj(544, std::vector<int>(544, 0)); 
 std::vector<std::vector<int>> revadj(544, std::vector<int>(544, 0)); 
 
std::vector<std::vector<int>> adjacency(std::vector<int> attrib_scores, std::vector<int> pref_scores) {
    for (unsigned int i = 0; i < attrib_scores.size(); i++) { 
        for (unsigned int a = 0; a < attrib_scores.size(); a++) {
            if (attrib_scores[i] < pref_scores[a] && (i != a)) {
                adj[i].push_back(a); 
            }
        }
    }
    return adj; 
}

std::vector<std::vector<int>> revadjacency(std::vector<int> attrib_scores, std::vector<int> pref_scores) { 
    for (unsigned int i = 0; i < attrib_scores.size(); i++) { 
        for (unsigned int a = 0; a < attrib_scores.size(); a++) {
            if (attrib_scores[i] < pref_scores[a] && (i != a)) {
                revadj[a].push_back(i); 
            }
        }
    }
    return revadj; 
}


// recursive function that performs DFS on adjacency matrix

void dfs_1(int x) {
  std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");
  std::vector<int> pref_score = CalcPrefScore(prefs); 
  std::vector<std::vector<int>> attribs  = file_to_attribvect("../tests/CS225_matchmaking.csv");
  std::vector<int> attrib_score = CalcAttribScore(attribs); 
  std::vector<std::vector<int>> adj = adjacency(attrib_score, pref_score); 
  visited[x] = true;
  for (unsigned i = 0; i < adj[x].size(); i++) {
    if (!visited[adj[x][i]]) { 
        dfs_1(adj[x][i]);
    }
  }
  S.push(x);
}

// recursive function that performs DFS on transposed adjacency matrix 
void dfs_2(int x) {
  std::vector<std::vector<int>> prefs  = file_to_prefvect("../tests/CS225_matchmaking.csv");
  std::vector<int> pref_score = CalcPrefScore(prefs); 
  std::vector<std::vector<int>> attribs  = file_to_attribvect("../tests/CS225_matchmaking.csv");
  std::vector<int> attrib_score = CalcAttribScore(attribs); 
  std::vector<std::vector<int>> revadj = adjacency(attrib_score, pref_score);
  component[x] = numComponents;
  components[numComponents].push_back(x);
  visited[x] = true;
  for (unsigned i = 0; i < revadj[x].size(); i++) {
    if (!visited[revadj[x][i]]) { 
        dfs_2(revadj[x][i]);
    }
  }
}

// function that finds strongly connected components
int Kosaraju(int n) {
    numComponents = 0; 
    for (int i = 0; i < n; i++) { 
        if (!visited[i]) { 
            dfs_1(i);
        }
    } 
    // mark all nodes as not visited
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    } 
    while (!S.empty()) {
        // pop a vertex 
        int v = S.top();
        S.pop();
        if (!visited[v]) {
            dfs_2(v);
            numComponents++;
        }
    }
    return numComponents; 
}



 
