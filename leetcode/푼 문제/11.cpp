class Solution {
public:
    int maxArea(vector<int>& height) {
        int idx1 = 0, idx2 = height.size() - 1;
        int result = 0;
        while (idx1 < idx2) {
            int tmp = min(height[idx1], height[idx2]) * (idx2 - idx1);
            result = max(result, tmp);

            if (height[idx1] < height[idx2])
                idx1++;
            else
                idx2--; 
        }

        return result;
    }
};