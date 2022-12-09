// #include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <stack> 

#include "Graph.h"
#include <algorithm>


// using namespace std;
// int n, m;


// vector <int> adj;
// vector <int> rev_adj;


// stack <int> S;
// bool visited[MAX_N];

// vector<int> component; 
// vector <int> components;


// // pass in 1D vector of everyone's attributes 
// std::vector<std::vector<int>> adjacencyMatrix(std::vector<int> attrib_scores) {
//     std::vector<std::vector<int>> adjacency(attrib_scores.size(), std::vector<int>(attrib_scores.size(), 0));   
//     for (unsigned int i = 0; i < attrib_scores.size(); i++) { 
//         for (unsigned int a = 0; a < attrib_scores.size(); a++) {
//             if (attrib_scores[i] > attrib_scores[a] && (i != a)) {
//                 adjacency[i][a] = 1; 
//                 adjacency[a][i] = 1;
//             }
//         }
//     }
//     return adjacency; 
// }

// // recursive function that performs DFS on adjacency matrix
// void dfs_1(int x) {
//   visited[x] = true;
//   for (int i = 0; i < g[x].adj.size(); i++) {
//     if (!visited[g[x].adj[i]]) { 
//         dfs_1(g[x].adj[i]);
//     }
//   }
//   S.push(x);
// }

// // recursive function that performs DFS on transposed adjacency matrix 
// void dfs_2(int x) {
//   printf("%d ", x);
//   component[x] = numComponents;
//   components[numComponents].push_back(x);
//   visited[x] = true;
//   for (int i = 0; i < g[x].rev_adj.size(); i++) {
//     if (!visited[g[x].rev_adj[i]]) { 
//         dfs_2(g[x].rev_adj[i]);
//     }
//   }
// }

// // function that finds strongly connected components
// std::vector<int> Kosaraju() {
//     int numComponents = 0; 
//     std::vector<int> popularity; 
//     for (int i = 0; i < n; i++) { 
//         if (!visited[i]) { 
//             dfs_1(i);
//         }
//     } 
//     // mark all nodes as not visited
//     for (int i = 0; i < n; i++) {
//         visited[i] = false;
//     } 
//     while (!S.empty()) {
//         // pop a vertex 
//         int v = S.top();
//         S.pop();
//         if (!visited[v]) {
//             printf("Component %d: ", numComponents);
//             dfs_2(v);
//             numComponents++;
//         }
//     }
//     popularity.push_back(numComponents); 
//     return popularity;
// }

// int mostPopular(std::vector<int> popularity) { 
//     std::vector<int> vec = Kosaraju(); 
//     // map all people's id's to their numComponents
// }

// # include "Graph.h"

// Graph::Graph(int V) {
//     this->V = V;
//     adj.resize(V);
// }
 
// void Graph::addEdge(int v, int w) {
//     adj[v].push_back(w); // Add w to v’s list.
// }
 
