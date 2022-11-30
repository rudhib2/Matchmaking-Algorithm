
using namespace std;
#include iostream
#include <vector>
#include <list>

 
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
    void addEdge(int v, int w); 
  
};