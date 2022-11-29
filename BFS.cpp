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

    if(PrelimCheck(id1, id2) == false) {
        return false; 
    }

    // if the two are compatibilty, so if the scores are wihtin the threshold then we return a boolean
    if(pscore + 50 >= atrscore || pcore - 50 >= atrscore) {
        return true; 
    }
}

std::vector<std::vector<bool>> populate(){ 
    // iterate through the pref_score vector and the attr_score vector
    Graph g(id.size()); 
    vector<bool> visited;

    // Mark all the vertices as not visited
    for(int i = 0; i < visited.size(); i++){
       visited[i][j] == false; 
    }

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
        if(PrelimCheck(id1, id2) == true) {
            BFS(id[i]);
        }
        isCompatible.push_back(visited);
    }
}


BFS(int id1) { // // BFS through the graph

// Mark all the vertices as not visited
    for(int j = 0; j < visited.size(); j++) {
        visited[i][j] == false; 
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


bool PrelimCheck(int id1, int id2) {
    // checking rel_type
    if (pref[id1][0] != attr[id2][8]) {
        return false;
    }
    //checking age
    if (pref[id1][2] != attr[id2][1]) {
        return false;
    }
    //checking gender
    if (pref[id1][1] != attr[id2][0]) {
        return false;
    }
    //checking race_pref
    if (pref[id1][3] != attr[id2][2]) {
        return false;
    }
    return true;
}


 