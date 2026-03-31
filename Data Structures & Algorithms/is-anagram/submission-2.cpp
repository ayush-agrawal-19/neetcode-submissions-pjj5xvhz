class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> anagram;

        for (char c : s) anagram[c]++;
        for (char c : t) anagram[c]--;

        for (auto &p : anagram) {
            if (p.second != 0) {
                return false;
            }
        }

        return true;
    }
};
