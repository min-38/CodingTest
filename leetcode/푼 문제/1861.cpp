class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int x = boxGrid[0].size(); // 4
        int y = boxGrid.size(); // 2

        for (int i = 0; i < y; i++)
        {
            int p1, p2;
            p1 = x - 1;
            p2 = p1;
            
            while (p2 >= 0)
            {
                if (boxGrid[i][p2] == '*')
                {
                    p1 = p2 - 1;
                }
                else if (boxGrid[i][p2] == '#')
                {
                    swap(boxGrid[i][p1], boxGrid[i][p2]);
                    p1--;
                }
                p2--;
            }
        }
        
        vector<vector<char>> nBoxGrid(x, vector<char>(y, '.'));
        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++)
                nBoxGrid[j][y - 1 - i] = boxGrid[i][j];
        
        return nBoxGrid;
    }
};
