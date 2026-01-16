class Solution {
public:
    static const long long MOD = 1'000'000'007LL;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());

        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hus;

        int hSize = hFences.size();
        for (int i = 0; i < hSize; i++)
            for (int j = i + 1; j < hSize; j++)
                hus.insert(hFences[j] - hFences[i]);

        int bestLen = 0;
        int vSize = vFences.size();
        for (int i = 0; i < vSize; i++)
        {
            for (int j = i + 1; j < vSize; j++)
            {
                int len = vFences[j] - vFences[i];
                if (hus.count(len))
                    bestLen = max(bestLen, len);
            }
        }

        if (bestLen == 0)
            return -1;

        int best = (int)((1LL * bestLen * bestLen) % MOD);
        return best;
    }
};
