class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int word1_len = word1.length();
        int word2_len = word2.length();
        
        int i = 0;
        int cnt;
        do {
            cnt = 0;

            if (i < word1_len) {
                result += word1[i];
                cnt++;
            }
                
            if (i < word2_len) {
                result += word2[i];
                cnt++;
            }
            i++;
        } while(cnt != 0);

        return result;
    }
};