#include <string>
#include <vector>

using namespace std;

struct WantStruct {
    string item;
    int number;
    int current_number = 0;
    bool satisfied = false;
};

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    vector<WantStruct> v;
    for(int i = 0; i < want.size(); i++) {
        WantStruct ws;
        ws.item = want[i];
        ws.number = number[i];
        v.push_back(ws);
    }
    
    int cnt = 0;
    while(discount.size() - cnt >= want.size()) {
        for(int i = cnt; i < cnt + 10; i++) {
            if(i >= discount.size())
                break;
        
            string dcItem = discount[i];
            for(int j = 0; j < v.size(); j++)
                if(v[j].item == dcItem) {
                    v[j].current_number++;
                    if(v[j].current_number >= v[j].number)
                        v[j].satisfied = true;
                    break;
                }
        }
        
        int satisfied = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].satisfied)
                satisfied++;
            v[i].satisfied = false;
            v[i].current_number = 0;
        }
        
        if(satisfied == want.size())
            answer++;
        cnt++;
    }
    
    
    return answer;
}