
#include <iostream>
#include <vector>
#include <list>
#pragma once 

using namespace std; 
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;// No. of vertices
    // Pointer to an array containing adjacency lists
    std::vector<std::list<int>> adj;  
public:
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