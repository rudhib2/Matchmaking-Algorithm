
// #include "BFS.h"

// BFS() {
//     // setting everything to false by default 
//     for(int i = 0; i < compat.size(); i++){
//         for(int j = 0; j < compat.size(); j++) {
//             compat[i][j] == false;
//         }
//     }
// }

// bool isCompatible(int id1, int id2) {
//     // it takes the preference score of id1 and attribute score of id2 
//     int pscore = pref_score[id1];
//     int atrscore = attr_Score[id2];

//     if(PrelimCheck(id1, id2) == false) {
//         return false; 
//     }

//     // if the two are compatibilty, so if the scores are wihtin the threshold then we return a boolean
//     if(pscore + 50 >= atrscore || pcore - 50 >= atrscore) {
//         return true; 
//     }
// }

// std::vector<std::vector<bool>> populate(){ 
//     // iterate through the pref_score vector and the attr_score vector
//     Graph g(id.size()); 
//     vector<bool> visited;

//     // Mark all the vertices as not visited
//     for(int i = 0; i < visited.size(); i++){
//        visited[i][j] == false; 
//     }

//     for (int i = 0; i < pref_score.size(); i++) {
//         for (int j = 0; j < attr_score.size(); j++) {
//             if(i == j) {
//                 continue; 
//             }
//             boolean flag = isCompatible([id[i],id[j]]);

//             // after getting the boolean, if it is true, we add an edge 
//             if (flag == true) {
//                 g.addEdge(id[j],id[i]);
//             }
//         }
//         if(PrelimCheck(id1, id2) == true) {
//             BFS(id[i]);
//         }
//         isCompatible.push_back(visited);
//     }
// }


// BFS(int id1) { // // BFS through the graph

// // Mark all the vertices as not visited
//     for(int j = 0; j < visited.size(); j++) {
//         visited[i][j] == false; 
//     }
    
 
//     // Create a queue for BFS
//     list<int> queue;
 
//     // Mark the current node as visited and enqueue it
//     visited[id1] = true;

//     id1 = queue.front();
//     queue.push_back(id1);
 
//     while(!queue.empty())
//     {
//         queue.pop_front();
 
//         // Get all adjacent vertices of the dequeued
//         // vertex s. If a adjacent has not been visited,
//         // then mark it visited and enqueue it
//         for (auto adjecent: adj[id1])
//         {
//             if (!visited[adjecent])
//             {
//                 visited[adjecent] = true;
//                 queue.push_back(adjecent);
//             }
//         }
//     }
// }


// //PrelimCheck is the function that checks for "absolute traits" (rel_type, age, gender, race_pref). 
// // If any of these don't match we straight away say that the two people are incompatible

// bool PrelimCheck(int id1, int id2) {
//     // checking rel_type
//     if (pref[id1][0] != attr[id2][8]) {
//         return false;
//     }
//     //checking age
//     if (pref[id1][2] != attr[id2][1]) {
//         return false;
//     }
//     //checking gender
//     if (pref[id1][1] != attr[id2][0]) {
//         return false;
//     }
//     //checking race_pref
//     if (pref[id1][3] != attr[id2][2]) {
//         return false;
//     }
//     return true;
// }
#include "BFS.h"
#include "Graph.h"
#include "csv.h"
// #include "CalcScore.h"


void Traversal::store_values() {
    pref = file_to_prefvect("../tests/CS225_matchmaking.csv"); 
    attr = file_to_attribvect("../tests/CS225_matchmaking.csv"); 
    id = file_to_ids("../tests/CS225_matchmaking.csv");
    CalcPrefScore(pref, pref_score);
    CalcAttribScore(attr, attr_score);
}

bool Traversal::PrelimCheck(int id1, int id2) {
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


bool Traversal::isCompatible(int id1, int id2) {
    // it takes the preference score of id1 and attribute score of id2 
    int pscore = pref_score[id1];
    int atrscore = attr_score[id2];

    if(PrelimCheck(id1, id2) == false) {
        return false; 
    }

    // if the two are compatibilty, so if the scores are wihtin the threshold then we return a boolean
    if(pscore + 50 >= atrscore || pscore - 50 >= atrscore) {
        return true; 
    }
    return false; 
}

//PrelimCheck is the function that checks for "absolute traits" (rel_type, age, gender, race_pref). 
// If any of these don't match we straight away say that the two people are incompatible


std::vector<std::vector<bool>> Traversal::populate(){ 
    // iterate through the pref_score vector and the attr_score vector
    Graph g(id.size()); 
    store_values(); 
    std::vector<std::vector<bool>> isCompat;
    bool flag;  

    for (size_t i = 0; i < pref_score.size(); i++) {
        for (size_t j = 0; j < attr_score.size(); j++) {
            if(i == j) {
                continue; 
            }
            flag = isCompatible(i,j);

            // after getting the boolean, if it is true, we add an edge 
            if (flag == true) {
                g.addEdge(id[i],id[j]);
            }
        }
        if(flag == true) {
            g.BFS(id[i]);    
        }
        isCompat.push_back(g.visited);
    }

    for(size_t i = 0; i < isCompat.size(); i++) {
        for(size_t j = 0; j < isCompat[i].size(); j++) {
            std::cout << isCompat[i][j] << std::endl;
        }
    }
    return isCompat; 
}

std::vector<std::vector<int>> Traversal::adjacency_matrix(){ 
    // if there exists an edge between the two vertices then the attribute score will be held in that position in the matrix
    // otherwise there will be -1; 
    std::vector<std::vector<bool>> temp = populate(); 

    for(size_t i =  0; i < temp.size(); i++) {
        for(size_t j = 0; j < temp[i].size(); j++) {
            if(temp[i][j] == false) {
                adj_matrix[i][j] = -1; 
            } else {
                adj_matrix[i][j] = attr_score[3];
            }
        }
    }
    return adj_matrix; 
}

std::vector<int> Traversal::compat_list(){
    Graph g(id.size());  
    std::vector<std::vector<bool>> isCompat;
    bool flag;  
    std::vector<int> tmp; 

    for (size_t i = 0; i < pref_score.size(); i++) {
        for (size_t j = 0; j < attr_score.size(); j++) {
            if(i == j) {
                continue; 
            }
            flag = isCompatible(i,j);

            // after getting the boolean, if it is true, we add an edge 
            if (flag == true) {
                g.addEdge(id[i],id[j]);
            }
        }
        if(flag == true) {
             tmp = g.dijkstra(adj_matrix, i);
        }
    }

    // to_return now contains the distance of each person from the root node for that graph
    // we need to return a list of the top 3 people that have the shortest distance from the root 
    
    std::vector<int> temp_id; 
    temp_id.resize(id.size());
    for(size_t i = 0; i < id.size(); i++) {
        temp_id[i] = id[i]; 
    }

    // using bubble sort for sorting 
    for(size_t i = 0; i < id.size() - 1; i++) {
        for(size_t j = 0; j < id.size() - 1; j++) {
            if(tmp[j] > tmp[j+1]) {
                size_t temp = tmp[j];
                tmp[j] = tmp[j+1];
                tmp[j+1] = temp; 

                size_t temp1 = temp_id[j];
                temp_id[j] = temp_id[j+1];
                temp_id[j+1] = temp; 
            }
        }
    }
     
    std::vector<int> to_return; 
    for(size_t i = 0; i < 3; i++) {
        to_return.push_back(id[i]);
    }
    return to_return;
}








 