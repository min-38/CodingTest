#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int size = section.size();
    int idx = 0;

    while (idx < size) {
        int painted_end = section[idx] + m;
        answer++;

        while (idx < size && section[idx] < painted_end)
            idx++;
    }

    return answer;
}
