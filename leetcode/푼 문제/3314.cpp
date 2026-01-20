class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num % 2 == 0)
            {
                ans[i] = -1;
                continue;
            }

            int one_cnt = 0;
            int x = num;
            while (x & 1)
            {
                one_cnt++;
                x >>= 1;
            }
            ans[i] = num - (1 << (one_cnt - 1));
        }

        return ans;
    }
};
