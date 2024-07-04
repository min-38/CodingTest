#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Insert(vector<int>& answer, int value) {
    bool exist = false;
    for(int i = 0; i < answer.size(); i++)
        if(answer[i] == value) {
            exist = true;
            break;
        }
    
    if(!exist)
        answer.push_back(value);
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    
    int cursor = 1;
    while(cursor < s.length() - 1) {
        vector<int> elmnts;

        if(s[cursor] == '{') {
            string tmp = "";
            while(s[cursor] != '}') {
                cursor++; // 커서 1 증가
                if(s[cursor] == ',' || s[cursor] == '}') {
                    elmnts.push_back(stoi(tmp));
                    tmp = "";
                    continue;
                }
                tmp += s[cursor];
            }
            v.push_back(elmnts);
        }
        cursor++;
    }

    int cnt = 1;
    while(cnt <= v.size()) {
        for(int i = 0; i < v.size(); i++)
            if(v[i].size() == cnt)
                for(int j = 0; j < cnt; j++)
                    Insert(answer, v[i][j]);
        cnt++;
    }
    return answer;
}