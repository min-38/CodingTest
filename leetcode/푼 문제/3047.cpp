class Solution {
public:
    struct Square
    {
        int x1, y1, x2, y2;
    };

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<Square> v;

        int size = bottomLeft.size();
        for (int i = 0; i < size; i++)
        {
            Square newSquare = {bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]};
            v.push_back(newSquare);
        }

        long long answer = 0;

        int vsize = v.size();
        for (int i = 0; i < vsize; i++)
        {
            Square t1 = v[i];
            for (int j = i + 1; j < vsize; j++)
            {
                Square t2 = v[j];

                int left    = max(t1.x1, t2.x1);
                int right   = min(t1.x2, t2.x2);
                int bottom  = max(t1.y1, t2.y1);
                int top     = min(t1.y2, t2.y2);

                int w = right - left;
                int h = top - bottom;

                if (w > 0 && h > 0)
                {
                    long long L = min(w, h);
                    answer = max(answer, L * L);
                }
            }
        }

        return answer;
    }
};