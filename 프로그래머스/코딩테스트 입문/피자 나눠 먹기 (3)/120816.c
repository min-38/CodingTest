#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int slice, int n) {
    int answer = 0;
    
    int a = n / slice;
    int b = n % slice;
    
    answer = b > 0 ? a + 1 : a;

    return answer;
}