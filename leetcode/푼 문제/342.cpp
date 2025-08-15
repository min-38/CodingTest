class Solution {
public:
    bool isPowerOfFour(int n) {
        int x = 0;
        while (true)
        {
            if (n == pow(4, x)) return true;
            if (n < pow(4, x)) return false;
            x += 1;
        }
        return false;
    }
};
