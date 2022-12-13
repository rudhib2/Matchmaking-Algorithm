
#pragma once 

#include <iostream>
#include <vector>
#include <list>

using namespace std; 
 
class Graph
{
public:
    // Pointer to an array containing adjacency lists
    std::vector<std::list<int>> adj;  
    int V;// No. of vertices
    Graph(int V);  // Constructor
    // function to add an edge to graph
    std::vector<bool> visited;
    void addEdge(int v, int w);   
    void BFS(int id1);  
    std::vector<int> dijkstra(std::vector<std::vector<int>>, int);
    int minDistance(vector<int>, vector<bool>); 

    std::vector<int> dist;
    std::vector<int> sptSet;   
};
