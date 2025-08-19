class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;

        int zero = 0;
        size_t size = nums.size();
        vector<int> v(size + 1, 0);

        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                if (zero > 0) {
                    int cnt = zero;
                    for (int j = 1; j <= zero; j++)
                    {
                        result += cnt;
                        cnt--;
                    }
                }
                zero = 0;
            } else {
                zero++;
            }
        }

        if (zero > 0)
        {
            int cnt = zero;
            for (int j = 1; j <= zero; j++)
            {
                result += cnt;
                cnt--;
            }
        }

        return result;
    }
};