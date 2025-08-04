class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        int left = 0, right = 0;

        vector<int> basket(fruits.size(), 0);
        int used_basket = 0;

        basket[fruits[left]] = 1;
        used_basket = 1;
        int cnt = 1;

        while (right != fruits.size() - 1)
        {
            right++;
            if (basket[fruits[right]] > 0)
            {
                basket[fruits[right]]++;
                cnt++;
                continue;
            }

            if (used_basket < 2)
            {
                basket[fruits[right]]++;
                used_basket++;
                cnt++;
                continue;
            }

            if (cnt > result)
                result = cnt;

            basket[fruits[right]]++;
            cnt++;

            while (true)
            {
                basket[fruits[left]] -= 1;
                cnt--;
                if (basket[fruits[left++]] == 0)
                    break;
            }
        }

        if (cnt > result)
            result = cnt;

        return result;
    }
};