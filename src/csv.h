#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <set>



std::string splitstr(std::string str, std::string deli = " "); 
std::vector<std::vector<int>> file_to_prefvect(const std::string & filename);
std::vector<std::vector<int>> file_to_attribvect(const std::string & filename);
std::vector<int> file_to_ids(const std::string & filename);
std::vector<int> CalcPrefScore(std::vector<std::vector<int>> pref);
std::vector<int> CalcAttribScore(std::vector<std::vector<int>> attrib);
