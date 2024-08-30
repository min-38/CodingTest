#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> um;

void combination(string src, string dst, int depth) {
    if(dst.size() == depth)
        um[dst]++;
    else
        for(int i = 0; i < src.length(); i++)
            combination(src.substr(i + 1), dst + src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(string &order : orders) {
        sort(order.begin(), order.end());
        for(int c : course) {
            if(order.length() < c)
                continue;
            combination(order, "", c);
        }
    }

    for(int c : course) {
        vector<string> tmp;
        int max = 0;
        for (const auto &pair : um) {
            if(pair.second < 2)
                continue;

            if(pair.first.length() == c) {
                if(pair.second > max) {
                    tmp.clear();
                    tmp.push_back(pair.first);
                    max = pair.second;
                } else if(pair.second == max) {
                    tmp.push_back(pair.first);
                }
            }
        }

        answer.insert(answer.end(), tmp.begin(), tmp.end());
    }

    sort(answer.begin(), answer.end());
    return answer;
}