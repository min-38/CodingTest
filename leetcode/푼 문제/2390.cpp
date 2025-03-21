class Solution {
public:
    string removeStars(string s) {
        vector<char> v;

        for (char c : s) {
            if (c == '*') {
                if (v.size() > 0)
                    v.pop_back();
            }
            else {
                v.push_back(c);
            }
        }

        string result = "";
        for (char c : v)
            result += c;
        
        return result;
    }
};