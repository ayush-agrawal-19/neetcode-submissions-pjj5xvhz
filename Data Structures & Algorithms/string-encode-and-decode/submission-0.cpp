class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (string word : strs) {
            int word_length = word.size();
            encoded_string += to_string(word_length) + '#' + word;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        string word;
        string word_length;
        int word_len;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '#') {
                word_len = stoi(word_length);
                for (int j=i+1; j<i+word_len+1; j++) {
                    word += s[j];
                }
                decoded_string.push_back(word);
                i += word_len;
                word.clear();
                word_length.clear();
                word_len = 0;
            }
            else {
                word_length += s[i];
            }
        }

        return decoded_string;

    }
};
