class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> um;

        for (int num : nums)
            um[num]++;
        
        for (auto& entry : um)
            if (entry.second % 2 != 0)
                return false;

        return true;
    }
};