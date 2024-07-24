#include <iostream>
#include <vector>
using namespace std;

struct Node {
    vector<int> time;
    vector<int> connected;
    int min_length;
};

void deliver(vector<Node>& v, const int K, const int location, int duration, vector<bool>& visited) {
    Node* node = &v[location];
    if(node->min_length == 0 || node->min_length > duration)
        node->min_length = duration;

    for(int i = 0; i < node->connected.size(); i++)
        if(!visited[node->connected[i]])
            if(duration + node->time[i] <= K) {
                visited[node->connected[i]] = true;
                deliver(v, K, node->connected[i], duration + node->time[i], visited);
                visited[node->connected[i]] = false;
            }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<Node> v(N + 1);
    vector<bool> visited(N + 1, false);
    for(int i = 0; i < road.size(); i++) {
        v[road[i][0]].connected.push_back(road[i][1]);
        v[road[i][0]].time.push_back(road[i][2]);
        v[road[i][0]].min_length = K;

        v[road[i][1]].connected.push_back(road[i][0]);
        v[road[i][1]].time.push_back(road[i][2]);
        v[road[i][1]].min_length = K;
    }
    
    visited[1] = true;
    deliver(v, K, 1, 0, visited);
    
    for(int i = 1; i < v.size(); i++)
        if(v[i].min_length <= K)
            answer++;

    return answer;
}