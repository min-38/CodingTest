class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v(10, 0);
        string s = to_string(n);

        if (n == 1)
         return true;

        for (char c : s)
            v[c - '0'] += 1;

        
        int idx = 0;
        while (true)
        {
            unsigned long long num = 2;
            num <<= idx;
            ++idx;

            string s2 = to_string(num);

            if (s2.length() > s.length()) return false;
            if (s2.length() < s. length()) continue;
            
            vector<int> v2(10, 0); 
            for (char c : s2)
                v2[c - '0'] += 1;
            
            bool matched = true;
            for (int i = 0; i < 10; i++)
            {
                if (v[i] != v2[i])
                {
                    matched = false;
                    break;
                }
            }

            if (matched)
                return true;
        }

        return false;
    }
};