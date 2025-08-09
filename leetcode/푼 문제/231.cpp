class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n > 1)
        {
            int i = 1;
            while (true)
            {
                unsigned int value = pow(2, i);
                if (value == n)
                    return true;
                
                if (value > n)
                    break;

                i++;
            }
        }

        return false;
    }
};