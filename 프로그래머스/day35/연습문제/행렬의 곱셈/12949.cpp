#include <string>
#include <vector>

using namespace std;

int calculate(vector<int> row, vector<int> column) {
    int result = 0;
    for(int i = 0; i < row.size(); i++)
        result += row[i] * column[i];
    return result;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
        
    for(int i = 0; i < arr1.size(); i++) {
        vector<int> sub_answer;

        int column_idx = 0;
        while(column_idx < arr2[0].size()) {
            vector<int> column;
            for(int j = 0; j < arr2.size(); j++)
                column.push_back(arr2[j][column_idx]);

            sub_answer.push_back(calculate(arr1[i], column));
            column_idx++;
        }
        answer.push_back(sub_answer);
    }
    return answer;
}