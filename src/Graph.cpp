# include "Graph.h"
#include <list>
using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int id1) { // // BFS through the graph

// Mark all the vertices as not visited
    for(size_t j = 0; j < visited.size(); j++) {
        visited[j] = false; 
    }
    
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[id1] = true;

    id1 = queue.front();
    queue.push_back(id1);
 
    while(!queue.empty())
    {
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (size_t adjecent: adj[id1])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
 