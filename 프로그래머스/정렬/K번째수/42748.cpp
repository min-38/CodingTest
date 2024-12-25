#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subArray;

    for(const auto &cmd : commands) {
        // array에서 각 cmd에 해당하는 영역만 subArray로 복사 후 정렬
        subArray.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
        sort(subArray.begin(), subArray.end());

        // subArray에서 k번째 answer에 추가
        answer.push_back(subArray[cmd[2] - 1]);
    }

    return answer;
}