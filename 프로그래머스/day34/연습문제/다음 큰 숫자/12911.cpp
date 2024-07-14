#include <string>

using namespace std;

string n_bin;

void toBinary(const int n, int& one_cnt) {
    if (n / 2 != 0)
        toBinary(n / 2, one_cnt);

    if(n % 2 == 1)
        one_cnt++;

    n_bin += to_string(n % 2);
}

int solution(int n) {
    int answer = 0;

    int one_cnt = 0;
    toBinary(n, one_cnt);

    answer = n;
    while(1) {
        answer++;
        int one_cnt2 = 0;
        toBinary(answer, one_cnt2);

        if(one_cnt == one_cnt2)
            break;
    }

    return answer;
}
