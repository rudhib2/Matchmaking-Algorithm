#include <vector>
#include "CalcScore.h"

void CalcPrefScore(vector<vector<int>> pref, vector<int> &pref_score){
    int pref_s = 0; 
    for(size_t i = 0; i < pref.size(); i++) {
        for (size_t j = 0; j < pref[i].size(); j++) {
            if(j >=4 && j <=8) {
                continue; 
            }
            pref_s += pref[i][j]; 
        }
        pref_s *=10; 
        pref_score.push_back(pref_s);
    }
}

void CalcAttribScore(vector<vector<int>> attrib, vector<int> &attr_score){
    int attrib_s = 0; 
    for(size_t i = 0; i < attrib.size(); i++) {
        for (size_t j = 0; j < attrib[i].size(); j++) {
            if(j >=0 && j <=2 && j != 8) {
                continue; 
            }
            attrib_s += attrib[i][j]; 
        }
        attrib_s *=10; 
        attr_score.push_back(attrib_s);
    }
}
