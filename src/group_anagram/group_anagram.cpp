
#include <iostream>
#include <unordered_map>
#include <vector>

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::string> map = {};
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto vec = groupAnagrams(strs);
    for (auto i : vec) {
        for (auto z : i) {
            std::cout << z;
        }
        std::cout << std::endl;
    }
    return 0;
}
