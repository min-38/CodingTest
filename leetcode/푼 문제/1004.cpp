class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int wstart = 0, wend = 0;
        
        int zero_cnt = 0;
        int consecutive = 0;
        while (wend < nums.size()) {
            if(nums[wend] == 1)
                consecutive++;
            else
                zero_cnt++; 
            
            if (zero_cnt <= k) {
                result = max(result, consecutive + zero_cnt);
            } else {
                if (nums[wstart] == 1)
                    consecutive--;
                else
                    zero_cnt--;
                wstart++;
            }
            wend++;
        }

        return result;
    }
};