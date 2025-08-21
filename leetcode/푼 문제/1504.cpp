class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int result = 0;
        int r = mat.size();
        int c = mat[0].size();
        vector<int> h(c, 0);

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
                h[j] = mat[i][j] ? h[j] + 1 : 0;

            for(int j = 0; j < c; j++)
            {
                int mn = h[j];
                for(int k = j; k >= 0 && mn > 0; k--)
                {
                    mn = min(mn, h[k]);
                    result += mn;
                }
            }
        }
        return result;
    }
};