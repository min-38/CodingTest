class Solution {
public:
    vector<vector<int>> ps;
    int th;

    inline bool ok(int i, int j, int k) {
        int sum = ps[i + k][j + k] - ps[i][j + k] - ps[i + k][j] + ps[i][j];
        return sum <= th;
    }

    bool exists(int k, int m, int n) {
        for (int i = 0; i + k <= m; i++)
            for (int j = 0; j + k <= n; j++)
                if (ok(i, j, k))
                    return true;
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        th = threshold;

        ps.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                ps[i][j] = mat[i - 1][j - 1]
                         + ps[i - 1][j]
                         + ps[i][j - 1]
                         - ps[i - 1][j - 1];

        int lo = 0, hi = min(m, n);
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (exists(mid, m, n))
                lo = mid;
            else
                hi = mid - 1;
        }
        return lo;
    }
};