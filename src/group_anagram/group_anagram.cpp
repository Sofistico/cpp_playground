
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// example input ["eat", "tea", "tan", "ate", "nat", "bat"]
// expected output [["bat"],["nat","tan"],["ate","eat","tea"]]

bool is_anagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i])
            return false;
    }
    return true;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result = {};
    std::unordered_map<std::string, std::vector<std::string>> map = {};
    for (int i = 0; i < strs.size(); i++) {
        std::string s = std::string(strs[i]);
        sort(s.begin(), s.end());
        if (map.find(s) != map.end()) {
            continue;
        }
        map.insert({s, {strs[i]}});
        for (int z = i + 1; z < strs.size(); z++) {
            std::string t = strs[z];
            // if (map.find(t) != map.end())
            //     continue;
            if (is_anagram(strs[i], t)) {
                map[s].push_back(t);
            }
        }
        result.push_back(map[s]);
    }
    return result;
}

int main() {
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> expected_output = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};
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
