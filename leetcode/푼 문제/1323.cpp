class Solution {
public:
    int maximum69Number (int num) {
        int result = 0;
        string str_num = to_string(num);

        for (int i = 0; i < str_num.length(); i++)
            if (str_num[i] == '6')
            {
                str_num[i] = '9';
                break;
            }

        result = stoi(str_num);
        return result;
    }
};