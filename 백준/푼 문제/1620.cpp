#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // 시간 초과 방지용 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> map1;
    unordered_map<string, string> map2;

    string s = "";
    for (int i = 0; i < N; i++) {
        cin >> s;
        
        string num = to_string(i + 1);
        map1[s] = num;
        map2[num] = s;
    }

    string result;
    for (int i = 0; i < M; i++) {
        cin >> s;

        if(isdigit(s[0]))
            result = map2[s];
        else
            result = map1[s];
        cout << result << "\n";
    }

    return 0;
}