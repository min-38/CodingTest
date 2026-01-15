class Solution {
public:
    int getSeq(vector<int>& v) {
        if (v.empty()) return 1;

        int bestRun = 1;
        int curRun = 1;

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i] == v[i - 1] + 1) {
                curRun++;
            } else {
                bestRun = max(bestRun, curRun);
                curRun = 1;
            }
        }
        bestRun = max(bestRun, curRun);

        return bestRun + 1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxLen = min(getSeq(hBars), getSeq(vBars));
        return pow(maxLen, 2);
    }
};
