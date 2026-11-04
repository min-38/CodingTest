#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    // a: 교환에 필요한 빈 병 수
    // b: 교환 시 받는 콜라 수
    // n: 현재 가진 빈 병 수

    while (n >= a) {
        int received = n / a * b;      // 이번에 받은 콜라
        answer += received;
        n = n % a + received;          // 교환하고 남은 병 + 새로 생긴 빈 병
    }

    return answer;
}
