class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        int start = 0;

        while (idx < s.length() && start < t.length()) {
            if (s[idx] == t[start])
                idx++;
            start++;
        }

        if (idx == s.length())
            return true;
        return false;
    }
};