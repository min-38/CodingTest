#include <string>
#include <vector>
#include <map>

using namespace std;

void split(string arr[], string s) {
    int index = 0; 

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c == ' ') {
            index++;
            continue;
        }
        arr[index] += c;
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, vector<string>> um;
    map<string, int> um2;

    for(string id : id_list) {
        vector<string> v;
        um.insert(make_pair(id, v));

        um2.insert(make_pair(id, 0));
    }

    for(string s : report) {
        string arr[2] = {"", };
        
        split(arr, s);

        bool isAlreadyReported = false;
        vector<string> *v = &um[arr[0]];
        for(string s2 : *v)
            if(s2 == arr[1])
                isAlreadyReported = true;
        
        if(!isAlreadyReported) {
            v->push_back(arr[1]);
            um2[arr[1]]++;
        }
    }
    
    for(string s : id_list) {
        vector<string> *v = &um[s];
        int banned = 0;
        
        for(string s2 : *v) {
            if(um2[s2] >= k)
                banned++;
        }
        answer.push_back(banned);
    }

    return answer;
}