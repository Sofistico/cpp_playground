// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
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

bool isAnagramMap(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    map<const char, int> frequency;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        frequency[s[i]]++;
    }
    for (int i = 0; i < size; i++) {
        char c = t[i];
        if (frequency.find(c) != frequency.end()) {
            frequency[c]--;
        } else {
            return false;
        }
    }
    for (auto a : frequency) {
        if (a.second != 0) {
            return false;
        }
    }
    return true;
}


int main() {
    return 0;
}