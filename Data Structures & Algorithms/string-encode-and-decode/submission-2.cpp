class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for (string str : strs) {
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }

        cout << encoded << endl;

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            cout << "j=" << j << endl;

            while (s[j] != '#') {
                j++;
            }

            cout << s.substr(i, j-i) << endl;
            int word_length = stoi(s.substr(i, j-i));

            cout << s[j] << "||" << s[j+1] << endl;
            
            decoded.push_back(s.substr(j+1, word_length));
            i = j + word_length + 1;
        }

        return decoded;
    }
};
