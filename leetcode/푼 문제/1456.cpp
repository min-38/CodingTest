class Solution {
public:
    int checkIsVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return 1;
        return 0;
    }
    
    int maxVowels(string s, int k) {
        int max_vowel_cnt = 0;
        
        for (int i = 0; i < k; i++)
            max_vowel_cnt += checkIsVowel(s[i]);

        int vowel_cnt = max_vowel_cnt;
        for (int i = k; i < s.length(); i++) {
            vowel_cnt -= checkIsVowel(s[i - k]);
            vowel_cnt += checkIsVowel(s[i]);
            
            max_vowel_cnt = max(max_vowel_cnt, vowel_cnt);
        }

        return max_vowel_cnt;
    }
};