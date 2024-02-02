#include <iostream>
#include <vector>
using namespace std;

void DFS(int number, int jarisu);
static vector<vector <int> > A;
static vector<bool> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);


}

void DFS(int number, int jarisu) {
    if(jarisu == N) {
        if(isPrime(number)) {
            cout << number << endl;
        }
        return;
    }
    for(int i = 1; i < 10; i++) {
        if (i % 2 == 0) { // 짝수이면 더는 탐색할 필요가 없음
            continue;
        }
        if(isPrime(number * 10 + i)) { // 소수이면 재귀로 자릿수를 늘림
            DFS(number * 10 + i, jarisu + 1);
        }
    }
}