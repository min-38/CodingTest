#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> v;
    int i, j, k;
    for(int index = 0; index < commands.size(); index++) {
        i = commands[index][0];
        j = commands[index][1];
        k = commands[index][2];
        
        v.clear();
        for(int index2 = i - 1; index2 < j; index2++) {
            v.push_back(array[index2]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[k - 1]);
    }
    return answer;
}