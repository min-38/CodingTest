class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word;
        for (char c : s) {
            if (c == ' ') {
                if (word != "") {
                    v.push_back(word);
                    word = "";
                }       
            }
            else
                word += c;
        }

        if (word != "")
            v.push_back(word);

        string result = "";
        while (!v.empty()) {
            result += v.back();
            v.pop_back();

            if (!v.empty())
                result += " ";
        }

        return result;
    }
};