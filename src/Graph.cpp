// # include "Graph.h"
# include "Graph.h"
#include "BFS.h"
#include <list>
using namespace std;

// Graph::Graph(int V) {
//     this->V = V;
//     adj.resize(V);
// }
 
// void Graph::addEdge(int v, int w) {
//     adj[v].push_back(w); // Add w to v’s list.
// }
 
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

    int Graph::minDistance(vector<int> dist, vector<bool> sptSet) {
        Traversal t; 
        Graph g(t.id.size());
        // Initialize min value
        int min = 0; 
        int min_index = 0;
 
        for (size_t v = 0; v < t.id.size(); v++) {
            if (sptSet[v] == false && dist[v] <= min){
                min = dist.at(V);
                min_index = v; 
            }
        }
        return min_index;
    }


std::vector<int> Graph::dijkstra(std::vector<std::vector<int>> adj_matrix, int root) {
    std::vector<int> dist;  
    Traversal t; 
    dist.resize(t.id.size());
    // The output array.  
    // dist[i] will hold the shortest distance from src to i
 
    std::vector<bool> sptSet; 
    // sptSet[i] will be true if vertex i is
    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized
 
    // Initialize all distances as -1 and stpSet[] as
    // false
    for (size_t i = 0; i < t.id.size(); i++) {
        dist[i] = -1; 
        sptSet[i] = false; 
    }
 
    // Distance of source vertex from itself is always 0
    dist[root] = 0;
    // Find shortest path for all vertices
    for (size_t count = 0; count < t.id.size() - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (size_t v = 0; v < t.id.size(); v++)
 
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && adj_matrix[u][v] && dist[u] != -1 && dist[u] + adj_matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_matrix[u][v];
            }
        }
        return dist; 
}
