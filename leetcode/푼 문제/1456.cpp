class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowel_cnt = 0;
        
        for (int i = 0; i < k; i++)
            max_vowel_cnt += checkIsVowel(s[i]);

        int vowel_cnt = max_vowel_cnt;
        for (int i = k; i < s.length(); i++) {
            if (checkIsVowel(s[i - k]) == 1)
                vowel_cnt--;
            if (checkIsVowel(s[i]) == 1)
                vowel_cnt++;
            
            if (vowel_cnt > max_vowel_cnt)
                max_vowel_cnt = vowel_cnt;
        }

        return max_vowel_cnt;
    }

    int checkIsVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return 1;
        return 0;
    }
};