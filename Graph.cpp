# include "Graph.h"

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}
 