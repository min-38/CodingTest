class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sw_start = 0, sw_end = 0;
        int result = 0;
        int zero_cnt = 0;

        while (sw_end < nums.size()) {
            if (nums[sw_end] == 0)
                zero_cnt++;

            if (zero_cnt > 1) {
                while(nums[sw_start] == 1)
                    sw_start++;
                sw_start++;
                zero_cnt--;
            }
            result = max(result, sw_end - sw_start);
    
            sw_end++;
        }

        return result;
    }
};