class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 1;

        while (end < nums.size()) {
            if (nums[start] != 0) {
                start++;
                end = start + 1;
                continue;
            }
            
            if (nums[end] != 0) {
                nums[start++] = nums[end];
                nums[end] = 0;
            }
            end++;
        }
    }
};