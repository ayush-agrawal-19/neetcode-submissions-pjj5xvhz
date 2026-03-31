class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_substring = 0;

        for (int i=0; i<s.size(); i++) {
            unordered_set<char> unique_char;
            for (int j=i; j<s.size(); j++) {
                auto it = unique_char.find(s[j]);
                if (it == unique_char.end()) {
                    unique_char.insert(s[j]);
                    if (unique_char.size() > longest_substring) {
                        longest_substring = unique_char.size();
                    }
                }
                else {
                    break;
                }
            }
        }

        return longest_substring;
    }
};
