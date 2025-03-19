class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int idx1 = 0, idx2 = nums.size() - 1;
        
        int result = 0;
        while (idx1 < idx2) {
            if (nums[idx1] + nums[idx2] == k) {
                idx1++;
                idx2--;
                result++;
            } else if (nums[idx1] + nums[idx2] < k) {
                idx1++;
            } else {
                idx2--;
            }
        }

        return result;
    }
};