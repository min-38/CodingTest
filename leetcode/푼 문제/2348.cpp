class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;

        int zero = 0;
        size_t size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                result += (long long)zero * (zero + 1) / 2;
                zero = 0;
            } else {
                zero++;
            }
        }

        result += (long long)zero * (zero + 1) / 2;

        return result;
    }
};