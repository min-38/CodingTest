class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        sort(strs.begin(), strs.end());

        string fs = strs[0];
        string es = strs[strs.size() - 1];

        for (int i = 0; i < fs.length(); i++)
        {
            if (fs[i] != es[i] || i > es.length())
                break;

            result += fs[i];
        }

        return result;
    }
};