#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool compareGenre(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

bool compareSong(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> genres_dict;
    unordered_map<string, int> play_dict;

    // 장르별 총 재생 횟수와 각 곡의 재생 횟수 저장
    for(int i = 0; i < genres.size(); i++) {
        genres_dict[genres[i]].push_back({i, plays[i]});
        play_dict[genres[i]] += plays[i];
    }

    // 총 재생 횟수가 많은 장르순으로 정렬
    vector<pair<string, int>> sorted_genres(play_dict.begin(), play_dict.end());
    sort(sorted_genres.begin(), sorted_genres.end(), compareGenre);

    // 각 장르 내에서 노래를 재생 횟수순으로 정렬해 최대 2곡까지 선택
    for(auto &genre : sorted_genres) {
        auto &songs = genres_dict[genre.first];
        sort(songs.begin(), songs.end(), compareSong);

        for(int i = 0; i < min(2, (int)songs.size()); ++i)
            answer.push_back(songs[i].first);
    }

    return answer;
}