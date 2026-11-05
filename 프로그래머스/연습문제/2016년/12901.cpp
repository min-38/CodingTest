#include <string>

using namespace std;

string solution(int a, int b) {
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    int total_days = b;
    for (int i = 1; i < a; i++)
        total_days += days[i];

    return week[total_days % 7];
}
