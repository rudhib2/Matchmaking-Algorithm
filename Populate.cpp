public void setId(const std::string & filename){

}

public void setPrefVect(const std::string & filename){

}


public void setAttribVect(const std::string & filename){

}

public void CalcPrefScore(std::vector<std::vector<int>> pref){
    int pref_s = 0; 
    for(int i = 0; i < pref.size(); i++) {
        for (int j = 0; j < pref[i].size(); j++) {
            if(j >=4 && j <=8) {
                continue; 
            }
            pref_s += pref[i][j]; 
        }
        pref_s *=10; 
        pref_score.push_back(pref_s);
    }
}

public void CalcAttribScore(std::vector<std::vector<int>> attrib){
    int attrib_s = 0; 
    for(int i = 0; i < attrib.size(); i++) {
        for (int j = 0; j < attrib[i].size(); j++) {
            if(j >=0 && j <=2 && j != 8) {
                continue; 
            }
            attrib_s += attrib[i][j]; 
        }
        attrib_s *=10; 
        attrib_score.push_back(attrib_s);
    }
}
