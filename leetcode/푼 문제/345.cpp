class Solution {
public:
    string reverseVowels(string s) {
        vector<int> v;

        for (int i = 0; i < s.length(); i++)
            if (std::string("aeiouAEIOU").find(s[i]) != std::string::npos)
                v.push_back(i);

        for (int i = 0; i < v.size() / 2; i++) {
            char tmp = s[v[i]];
            s[v[i]] = s[v[v.size() - 1 - i]];
            s[v[v.size() - 1 - i]] = tmp;
        }

        return s;
    }
};