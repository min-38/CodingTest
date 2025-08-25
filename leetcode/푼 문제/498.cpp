class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int x = 0, y = 0;
        int c = mat[0].size();
        int r = mat.size();

        while (result.size() < r * c)
        {
            result.push_back(mat[y][x]);

            if ((x + y) % 2 == 0) // 우상향
            {
                if (x == c - 1)
                    y++;
                else if (y == 0)
                    x++;
                else
                {
                    x++;
                    y--;
                }
            }
            else
            {
                if (y == r - 1)
                    x++;
                else if (x == 0)
                    y++;
                else
                {
                    x--;
                    y++;
                }
            }
        }
        return result;
    }
};
