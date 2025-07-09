class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> um;

        for (char cNum : num)
            um[cNum - '0']++;        

        for (int i = 0; i < num.length(); i++)
            if (um[i] != num[i] - '0')
                return false;

        return true;
    }
};