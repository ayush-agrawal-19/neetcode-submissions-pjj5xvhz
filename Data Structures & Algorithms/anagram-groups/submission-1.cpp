class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        map<vector<int>, vector<string>> characters;

        for (string word : strs) {
            vector<int> letterCount(26, 0);

            for (char c : word) {
                letterCount[c - 'a']++;
            }

            characters[letterCount].push_back(word);
        }

        for (auto [key, value] : characters) {
            answer.push_back(value);
        }

        return answer;
    }
};
