#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        int r = (int)sqrt(i);
        if (r * r == i)
            answer -= i;
        else
            answer += i;
    }

    return answer;
}
