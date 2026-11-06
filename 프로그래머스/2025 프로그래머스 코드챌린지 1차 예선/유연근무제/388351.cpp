#include <vector>

using namespace std;

int toMinutes(int hhmm) {
    return hhmm / 100 * 60 + hhmm % 100;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); i++) {
        int limit = toMinutes(schedules[i]) + 10;
        int day = startday;
        bool ok = true;

        for (int time : timelogs[i]) {
            bool weekday = day <= 5;
            day = day % 7 + 1;

            if (weekday && toMinutes(time) > limit) {
                ok = false;
                break;
            }
        }

        if (ok) answer++;
    }

    return answer;
}
