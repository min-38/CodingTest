class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(int k = 1; k <= n; k++) {
            double a = (n / (double)k) - (((double)k - 1) / 2);
            if(a - (int)a == 0) {
                if(a > 0) {
                    answer++; 
                }
            }
        }
        return answer;
    }
}