class Solution {
public:
    vector<vector<int>> rowP, colP, d1P, d2P;

    bool isMagic(int r, int c, int k)
    {
        // 타겟 값
        int target = rowP[r][c + k] - rowP[r][c];

        // 행 검증
        for (int i = r; i < r + k; i++)
        {
            int s = rowP[i][c + k] - rowP[i][c];
            if (s != target)
                return false;
        }

        // 열 검증
        for (int j = c; j < c + k; j++)
        {
            int s = colP[r + k][j] - colP[r][j];
            if (s != target)
                return false;
        }

        // 대각선 검증
        int d1 = d1P[r + k][c + k] - d1P[r][c];
        if (d1 != target)
            return false;

        int d2 = d2P[r + k][c] - d2P[r][c + k];
        if (d2 != target)
            return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 행
        rowP.assign(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                rowP[i][j + 1] = rowP[i][j] + grid[i][j];

        // 열
        colP.assign(m + 1, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                colP[i + 1][j] = colP[i][j] + grid[i][j];

        // 대각선 좌상
        d1P.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                d1P[i + 1][j + 1] = d1P[i][j] + grid[i][j];

        // 대가선 우상
        d2P.assign(m + 1, vector<int>(n + 1, 0)); // 우상
        for (int i = 0; i < m; i++)
            for (int j = n - 1; j >= 0; j--)
                d2P[i + 1][j] = d2P[i][j + 1] + grid[i][j];

        for (int k = min(m, n); k >= 1; k--)
            for (int r = 0; r + k <= m; r++)
                for (int c = 0; c + k <= n; c++)
                    if (isMagic(r, c, k))
                        return k;

        return 1;
    }
};
