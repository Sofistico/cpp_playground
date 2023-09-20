
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// example input ["eat", "tea", "tan", "ate", "nat", "bat"]
// expected output [["bat"],["nat","tan"],["ate","eat","tea"]]

// Function to generate a hash for a string
std::string generateHash(const std::string& str) {
    std::vector<int> count(26, 0); // Assuming lowercase English letters
    for (char c : str) {
        count[c - 'a']++;
    }
    std::string hash(count.begin(), count.end());
    return hash;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;

    for (auto w : strs) {
        std::string str = w;
        sort(str.begin(), str.end());
        map[str].push_back(w);
    }
    std::vector<std::vector<std::string>> result;
    for (auto pair : map) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    // GODS!
    std::ifstream file;
    file.open("god-forsaken-text-file.txt", std::ios::in);
    std::vector<std::string> strs;
    if(file.is_open()){
        std::string str;
        while (std::getline(file, str, ','))
        {
            strs.emplace_back(str);
        }
    }
    
    std::vector<std::vector<std::string>> expected_output = {{"nat","tan"}};
    auto vec = groupAnagrams(strs);
    const char* res = vec == expected_output ? "equal" : "not equal";
    std::cout << res << std::endl;
    for (auto s : vec) {
        for (auto x : s) {
            std::cout << x << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
