#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    vector<int> countX(10, 0), countY(10, 0), common;
    
    for (char c : X) countX[c - '0']++;
    for (char c : Y) countY[c - '0']++;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < min(countX[i], countY[i]); j++)
            common.push_back(i);

    if (common.empty()) return "-1";
    if (common[0] == 0 && common.size() == 1) return "0";

    sort(common.rbegin(), common.rend());
    if (common[0] == 0) return "0";

    string answer;
    for (int num : common) answer += to_string(num);

    return answer;
}
