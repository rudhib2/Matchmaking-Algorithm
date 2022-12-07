#include "BFS.h"
#include "Graph.h"
#include "csv.h"
#include "CalcScore.h"


// BFS() {
//     // setting everything to false by default 
//     for(int i = 0; i < compat.size(); i++){
//         for(int j = 0; j < compat.size(); j++) {
//             compat[i][j] == false;
//         }
//     }
// }

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

    // // Mark all the vertices as not visited
    // for(size_t i = 0; i < visited.size(); i++){
    //    visited[i] = false; 
    // }

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
    return isCompat; 
}






 