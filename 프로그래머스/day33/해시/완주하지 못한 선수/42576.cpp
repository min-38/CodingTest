#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> ph; // participant를 나타낼 해시 테이블

    // 각 참가자를 해시 테이블에 추가(키: 이름, 값: 해당 이름의 명수)
    for(int i = 0; i < participant.size(); i++)
        ph[participant[i]]++;
    
    // 참가자 정보가 저장된 해시 테이블에서 완주한 선수들 제외
    for(int i = 0; i < completion.size(); i++) {
        ph[completion[i]]--;
        // 해시 테이블에 특정 이름이 0명이면 삭제
        if(ph[completion[i]] == 0)
            ph.erase(ph.find(completion[i]));
    }

    // 마지막 남은 한 선수의 이름 반환
    return ph.begin()->first;
}