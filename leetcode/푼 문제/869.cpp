class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n == 0) return false;

        string target = to_string(n);
        sort(target.begin(), target.end());
        const size_t L = target.size();

        for (unsigned long long x = 1ULL; ; x <<= 1) {
            string s = to_string(x);
            if (s.size() > L) return false;
            if (s.size() == L) {
                sort(s.begin(), s.end());
                if (s == target) return true;
            }
        }
    }
};