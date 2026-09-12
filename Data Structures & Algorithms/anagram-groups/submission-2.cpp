class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        map<vector<int>, vector<string>> anagrams;

        for (string word : strs) {
            vector<int> letterCount(26, 0);

            for (char c : word) {
                letterCount[c - 'a']++;
            }

            anagrams[letterCount].push_back(word);
        }

        for (auto it : anagrams) {
            answer.push_back(it.second);
        }

        return answer;
    }
};
