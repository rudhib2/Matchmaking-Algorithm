
#include "BFS.h"
#include "Graph.h"
#include "csv.h"
// #include "CalcScore.h"


Traversal::Traversal() {
    pref = file_to_prefvect("../tests/CS225_matchmaking.csv"); 
    attr = file_to_attribvect("../tests/CS225_matchmaking.csv");  
    id = file_to_ids("../tests/CS225_matchmaking.csv");
    pref_score = CalcPrefScore(pref);
    attr_score = CalcAttribScore(attr);
}

bool Traversal::PrelimCheck(int id1, int id2) {
    //checking age
    if (pref[id1][1] != attr[id2][1]) {
        return false;
    }
    //checking gender
    if (pref[id1][0] != attr[id2][0]) {
        return false;
    }
    //checking race_pref
    if (pref[id1][2] != attr[id2][2]) {
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
    Traversal(); 
    std::vector<std::vector<bool>> isCompat(544, std::vector<bool>(544, true));
    bool flag;  

    for (size_t i = 0; i < pref_score.size() - 1; i++) {
        for (size_t j = 0; j < attr_score.size() - 1; j++) {
            if(i == j) {
                isCompat[i][j] = false; 
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

std::vector<std::vector<int>> Traversal::adjacency_matrix() { 
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








 
