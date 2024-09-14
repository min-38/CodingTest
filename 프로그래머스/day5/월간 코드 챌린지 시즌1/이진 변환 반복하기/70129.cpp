#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int transforms = 0;
    int removedZeros = 0;
    // s가 "1"이 될 때까지 계속 반복
    while(s != "1") {
        transforms++;

        // '0' 개수를 세어 removedZeros에 누적
        removedZeros += count(s.begin(), s.end(), '0');

        // '1' 개수를 세고 2진수로 변환
        int oneCount = count(s.begin(), s.end(), '1');
        s = bitset<32>(oneCount).to_string();
        s = s.substr(s.find('1'));
    }

    return {transforms, removedZeros};
}