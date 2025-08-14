class Solution {
public:
    string largestGoodInteger(string num) {        
        vector<int> v(10, 0);
        char largest = '\0';

        for (int i = 0; i < num.length(); i++)
        {
            int idx = num[i] - '0';
            v[idx] += 1;

            if (v[idx] >= 3 && (largest == '\0' || largest < num[i]))
                largest = num[i];

            if (i > 0)
            {
                int bidx = num[i - 1] - '0';
                if (bidx != idx)
                    v[bidx] = 0;
            }
        }

        string result = "";
        if (largest != '\0')
            result = string(3, largest);

        return result;
    }
};