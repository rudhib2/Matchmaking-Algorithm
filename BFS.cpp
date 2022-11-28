#include "BFS.h"

BFS() {
    // setting everything to false by default 
    for(int i = 0; i < compat.size(); i++){
        for(int j = 0; j < compat.size(); j++) {
            compat[i][j] == false; 
        }
    }
}

bool isCompatible(int id1, int id2) {
    // it takes the preference score of id1 and attribute score of id2 
    int pscore = pref_score[id1];
    int atrscore = attr_Score[id2];

    // if the two are compatibilty, so if the scores are wihtin the threshold then we return a boolean
    if(pscore + 100 >= atrscore || pcore - 100 >= atrscore) {
        return true; 
    }
}

std::vector<std::vector<bool>> populate(){ 
    // iterate through the pref_score vector and the attr_score vector
    Graph g(id.size()); 

    for (int i = 0; i < pref_score.size(); i++) {
        for (int j = 0; j < attr_score.size(); j++) {
            if(i == j) {
                continue; 
            }
            boolean flag = isCompatible([id[i],id[j]]);

            // after getting the boolean, if it is true, we add an edge 
            if (flag == true) {
                g.addEdge(id[j],id[i]);
            }
        }
        BFS(id[i]); 
    }
}


BFS(int id1) { // // BFS through the graph

// Mark all the vertices as not visited
    vector<bool> visited;
    for(int i = 0; i < visited.size(); i++){
        for(int j = 0; j < visited.size(); j++) {
            visited[i][j] == false; 
        }
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
        for (auto adjecent: adj[id1])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

// complete adding all the edges 
// BFS through the graph
// according to the graph BFS we need to populate our vector 


 