class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max = 0;
        for (int i = 0; i < k; i++)
            max += nums[i];
        
        int tmp = max;
        for (int i = k; i < nums.size(); i++) {
            tmp -= nums[i - k];
            tmp += nums[i];
            if (tmp > max)
                max = tmp;
        }

        return max / k;
    }
};