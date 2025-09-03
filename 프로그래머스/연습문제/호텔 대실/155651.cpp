#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    
    for (vector<string> vs : book_time)
    {
        string str_begin_h = vs[0].substr(0, 2);
        string str_begin_m = vs[0].substr(3, 5);
        pq.push(make_pair(stoi(str_begin_h) * 60 + stoi(str_begin_m), 1));
        
        string str_end_h = vs[1].substr(0, 2);
        string str_end_m = vs[1].substr(3, 5);
        pq.push(make_pair(stoi(str_end_h) * 60 + stoi(str_end_m) + 10, -1));
    }
    
    int room = 0;
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        room += t.second;
        if (answer < room)
            answer = room;
    }
    
    return answer;
}