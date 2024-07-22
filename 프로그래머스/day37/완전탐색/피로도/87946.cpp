#include <string>
#include <vector>

using namespace std;

struct Node {
    int k; // 남은 피로도
    vector<bool> done; // 완료한 던전
    int done_cnt = 0; // 완료한 던전 개수
};

void run(int max, const vector<vector<int>>& dungeons, Node node, int& answer) {
    if(node.done_cnt < dungeons.size())
        for(int i = 0; i < dungeons.size(); i++) {
            if(node.done[i])// 이미 완료한 던전
                continue;

            if(dungeons[i][0] <= node.k)
                if(node.k - dungeons[i][1] > 0) {
                    Node newNode;
                    newNode.k = node.k - dungeons[i][1];
                    newNode.done = node.done;
                    newNode.done[i] = true;
                    newNode.done_cnt = node.done_cnt + 1;

                    run(max, dungeons, newNode, answer);
                }
        }

    if(node.done_cnt > answer)
        answer = node.done_cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    Node node;
    node.k = k;
    node.done = vector<bool>(dungeons.size(), false);
    
    run(k, dungeons, node, answer);

    return answer;
}