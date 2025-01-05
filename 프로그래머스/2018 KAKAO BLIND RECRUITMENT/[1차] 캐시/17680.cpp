#include <string>
#include <vector>
#include <list>

using namespace std;

string makeStringLower(string str) {
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);

    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    list<string> caches;

    int runtime;
    for (string city : cities) {
        city = makeStringLower(city);
        runtime = 5;

        if(cacheSize != 0) {
            for (auto it = caches.begin(); it != caches.end(); it++)
                if (((string)*it == city)) {
                    caches.erase(it);
                    runtime = 1;
                    break;
                }

            // 신규 도시가 들어올 때
            if (runtime == 5 && caches.size() >= cacheSize)
                caches.pop_front();
            caches.push_back(city);
        }
        answer += runtime;
    }

    return answer;
}