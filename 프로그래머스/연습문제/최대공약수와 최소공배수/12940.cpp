#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);

    int a = n;
    int b = m;
    while (true)
    {
        int r = a % b;
        if (r == 0)
        {
            answer[0] = b;
            break;
        }

        a = b;
        b = r;
    }

    answer[1] = n / answer[0] * m;

    return answer;
}
