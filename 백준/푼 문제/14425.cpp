#include <iostream>
#include <map>

using namespace std;

int main() {
    int result = 0;
    map<string, int> m;

    int N, M;
    cin >> N >> M;

    string s = "";
    for(int i = 0; i < N; i++) {
        cin >> s;
        m[s]++;
    }

    for(int i = 0; i < M; i++) {
        cin >> s;
        if(m[s] > 0)
            result++;
    }
    
    printf("%d\n", result);

    return 0;
}