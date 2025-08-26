class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestDiag2 = -1;
        long long bestArea  = 0;

        for (const vector<int>& dimension : dimensions)
        {
            long long L = dimension[0], W = dimension[1];
            long long diag2 = L * L + W * W;
            long long area  = L * W;

            if (diag2 > bestDiag2 || (diag2 == bestDiag2 && area > bestArea))
            {
                bestDiag2 = diag2;
                bestArea  = area;
            }
        }
        return static_cast<int>(bestArea);
    }
};