class Solution {
public:
    bool isNonDesc(vector<int>& nums)
    {
        bool result = true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                result = false;
                break;
            }
        }
        return result;
    }

    int minimumPairRemoval(vector<int>& nums) {
        if (isNonDesc(nums)) return 0;

        int ops = 0;

        while (!isNonDesc(nums))
        {
            int bestSum = INT_MAX;
            int bestIdx = -1;

            for (int i = 1; i < (int)nums.size(); i++)
            {
                int sum = nums[i - 1] + nums[i];
                if (sum < bestSum)
                {
                    bestSum = sum;
                    bestIdx = i - 1;
                }
            }

            nums[bestIdx] = bestSum;
            nums.erase(nums.begin() + bestIdx + 1);
            ops++;
        }

        return ops;
    }
};
