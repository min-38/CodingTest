#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_index_from_string(string s) {
    int index = 0;
    if(s == "date") { index = 1; }
    else if(s == "maximum") { index = 2; }
    else if(s == "remain") { index = 3; }
    else { index = 0; }
    return index;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ext_idx = get_index_from_string(ext);
    int sort_idx = get_index_from_string(sort_by);

    for(int i = 0; i < data.size(); i++) {
        if(data[i][ext_idx] < val_ext) {
            answer.push_back(data[i]);
        }
    }

    // 순차정렬
    for(int i = 0; i < answer.size(); i++) {
        for(int j = i + 1; j < answer.size(); j++) {
            if(answer[i][sort_idx] > answer[j][sort_idx]) {
                vector<int> tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }

    return answer;
}