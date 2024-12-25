#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n);
    
    // 작업별 완료까지 남은 일수 계산
    for(int i = 0; i < n; ++i)
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);

    int count = 0; // 배포할 작업의 수
    int max_day = days_left[0]; // 현재 배포할 작업 중 가장 늦게 배포할 작업의 가능일

    for(int i = 0; i < n; ++i) {
        if(days_left[i] <= max_day) { // 배포 가능일이 가장 늦은 배포일보다 빠르면
            count++;
        } else { // 배포 가능일이 가장 늦은 배포일보다 느리면
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count); // 마지막으로 카운트된 작업들을 함께 배포
    return answer;
}