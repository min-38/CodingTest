#include <algorithm>
#include <string>

using namespace std;

long long solution(long long n) {
    // 숫자를 문자열로 변환
    string str = to_string(n);

    // 역순으로 정렬
    sort(str.rbegin(), str.rend());
    return stoll(str);
}