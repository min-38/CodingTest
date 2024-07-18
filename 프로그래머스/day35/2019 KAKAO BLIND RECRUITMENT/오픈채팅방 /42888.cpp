#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct User {
    string uid;
    string action;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;

    unordered_map<string, string> hm;
    vector<User> v;

    for(string s : record) {
        vector<string> r(3, "");
        
        int idx = 0;
        for(char c : s) {
            if(c == ' ') {
                idx++;
                continue;
            }
            r[idx] += c;
        }

        if (r[0] == "Enter" || r[0] == "Change")
            hm[r[1]] = r[2];

        if (r[0] == "Enter" || r[0] == "Leave") {
            User user;
            user.action = r[0];
            user.uid = r[1];
            v.push_back(user);
        }
    }

    for(int i = 0; i < v.size(); i++) {
        User user = v[i];

        if(user.action == "Enter")
            answer.push_back(hm[user.uid] + "님이 들어왔습니다.");
        else
            answer.push_back(hm[user.uid] + "님이 나갔습니다.");
    }

    return answer;
}