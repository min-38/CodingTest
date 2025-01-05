#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> combi; // 주문의 조합 - 조합의 빈도

// 실제 주문의 조합을 구하는 함수
void combination(string src, string dst, int depth) {
    if(dst.size() == depth)
        combi[dst]++;
    else
        for(int i = 0; i < src.length(); i++)
            combination(src.substr(i + 1), dst + src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 주문을 오름차순으로 정렬
    for(string &order : orders)
        sort(order.begin(), order.end());

    for(int len : course) {
        for(string order : orders)
            // course 길이별 조합 생성
            combination(order, "", len);
        
        // 각 주문의 빈도수를 순회하면서 가장 많으 빈도수를 maxOrder에 저장
        int maxOrder = 0;
        for (auto it: combi)
            maxOrder = max(maxOrder, it.second);
        
        // 주문 횟수가 2회 이상이면서, 가장 많이 주문된 구성은 answer에 추가
        for(auto it : combi)
            if(maxOrder >= 2 && it.second == maxOrder)
                answer.push_back(it.first);
        
        combi.clear();
    }
    for(string &order : orders) {
        
        for(int c : course) {
            if(order.length() < c)
                continue;
            combination(order, "", c);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}