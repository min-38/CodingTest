#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int Aidx = 0, Bidx = 0;
    while(Bidx < B.size()) {
        if(A[Aidx] < B[Bidx]) {
            Aidx++;
            answer++;
        }
        Bidx++;
    }

    return answer;
}