class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int minH = r, minW = c;
        int maxH = -1, maxW = -1;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                {
                    if (i < minH)
                        minH = i;
                    
                    if (i > maxH)
                        maxH = i;
                    
                    if (j < minW)
                        minW = j;
                    
                    if (j > maxW)
                        maxW = j;
                }

        if (maxH == -1) return 0;

        int height = maxH - minH + 1;
        int width  = maxW - minW + 1;
        return height * width;
    }
};