class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> wordKey;
        vector<vector<string>> anagrams;

        for (const string& word : strs) {
            vector<int> word_freq(26,0);

            for (char c : word) {
                word_freq[c - 'a']++;
            }
            wordKey[word_freq].push_back(word);
        }

        for (const auto& it : wordKey) {
            anagrams.push_back(it.second);
        }

        return anagrams;
    }
};
