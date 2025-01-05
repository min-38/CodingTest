#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int bc = 0; // bandage_continuity, 붕대 연속으로 감은 횟수
    int ch = health; // 현재 체력

    int t = bandage[0]; // 시전 시간
    int x = bandage[1]; // 초당 회복량
    int y = bandage[2]; // 추가 회복량
    int a_count = 0; // 공격 받은 횟수
    
    for(int time = 1; time <= attacks[attacks.size() - 1][0]; time++) {
        if(time == attacks[a_count][0]) {
            ch -= attacks[a_count][1]; // 공격 
            bc = 0; // 연속 회복 성공 시간 0으로 초기화
            a_count++; // 다음 공격 대기
        } else if(ch < health) { // 회복
            int heal = x; // 회복
            if(++bc >= t) { // 회복 연속 성공시
                heal += y; // 추가 회복량 추가
                bc = 0; // 회복 연속 횟수 0으로 초기화
            }
            ch += heal;
            if(health - ch < 0) {
                ch += health - ch;
            }
        }
        if(ch <= 0) {
            break;
        }
    }
    answer = ch > 0 ? ch : -1;

    return answer;
}