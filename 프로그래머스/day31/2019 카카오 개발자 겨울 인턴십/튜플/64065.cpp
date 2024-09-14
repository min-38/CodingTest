#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int counts[100001] = {};

void updateCounts(const string &s) {
    string numStr;
    // 인수로 받은 문자열 순회
    for(char ch : s) {
        // 현재 문자가 숫자일 때
        if(isdigit(ch)) {
            numStr += ch;
            // 현재 문자가 숫자가 아닐 때
        } else {
            if(!numStr.empty()) {
                // 계수 정렬을 하기 위해 각 숫자의 개수 저장
                counts[stoi(numStr)]++;
                numStr.clear();
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    // 집합이 담긴 문자열의 각 원소를 계수 정렬
    updateCounts(s);

    vector<pair<int, int>> freqPairs;
    for(int i = 1; i < 100000; i++)
        // 집합에 있는 원소면 (개수, 값) 형식으로 푸시
        if(counts[i] > 0)
            freqPairs.push_back({counts[i], i});

    // 각 원소의 개수를 기준으로 내림차순 정렬
    sort(freqPairs.rbegin(), freqPairs.rend());

    // 원소의 개수로 내림차순 정렬된 벡터를 순회하며 원소를 푸시
    for(const auto &p : freqPairs)
        answer.push_back(p.second);

    return answer;
}