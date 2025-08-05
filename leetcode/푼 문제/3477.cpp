class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        int idx = 0;
        int n = fruits.size();
        
        while (idx < n)
        {
            bool placed = false;
            for (int i = 0; i < baskets.size(); i++)
            {
                if (fruits[idx] <= baskets[i])
                {
                    placed = true;
                    baskets.erase(baskets.begin() + i);
                    break;
                }
            }
            if (!placed)
                result++;
            idx++;
        }

        return result;
    }
};
