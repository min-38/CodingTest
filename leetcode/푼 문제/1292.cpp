class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                prefix[i][j] = mat[i - 1][j - 1]
                            + prefix[i - 1][j]
                            + prefix[i][j - 1]
                            - prefix[i - 1][j - 1];

        for (int k = min(m, n); k >= 1; --k)
        {
            for (int i = 0; i + k <= m; i++)
            {
                for (int j = 0; j + k <= n; j++)
                {
                    int sum = prefix[i + k][j + k] - prefix[i][j + k] - prefix[i + k][j] + prefix[i][j];
                    if (sum <= threshold)
                        return k;
                }
            }
        }

        return 0;
    }
};