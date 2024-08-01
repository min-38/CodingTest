#include <stdio.h>

int main() {
    int answer = 0;
    int N;
    scanf("%d", &N);
    
    int startp = 1, endp = 1;

    while(startp <= N) {
        int sum = 0;
        for(int i = startp; i <= endp; i++) {
            sum += i;
        }

        if(sum > N) {
            startp++;
        } else  if(sum == N) {
            answer++;
            endp++;
        } else {
            endp++;
        }
    }

    printf("%d\n", answer);

    return 0;
}