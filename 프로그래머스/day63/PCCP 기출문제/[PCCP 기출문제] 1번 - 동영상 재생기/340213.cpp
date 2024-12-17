#include <string>
#include <vector>

using namespace std;

int op_start_min;
int op_start_sec;
int op_end_min;
int op_end_sec;

int get_time(string time, int start) { // type 0: 분, 1: 초
    string s = "";
    for (int i = start; i <= start + 1; i++)
        s += time[i];

    return stoi(s);
}

void skip_opening(int &min, int &sec) {
    int time = min * 60 + sec;
    if(op_start_min * 60 + op_start_sec <= time && time < op_end_min * 60 + op_end_sec) {
        min = op_end_min;
        sec = op_end_sec;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    int min = get_time(pos, 0);
    int sec = get_time(pos, 3);

    int fin_min = get_time(video_len, 0);
    int fin_sec = get_time(video_len, 3);

    int fin_min_tsb = fin_min;
    int fin_sec_tsb = fin_sec - 10;
    if(fin_sec_tsb < 0) {
        fin_min_tsb -= 1;
        fin_sec_tsb = 60 + fin_sec_tsb;
    }

    op_start_min = get_time(op_start, 0);
    op_start_sec = get_time(op_start, 3);
    op_end_min = get_time(op_end, 0);
    op_end_sec = get_time(op_end, 3);

    skip_opening(min, sec);

    for (string command : commands) {
        if (command == "prev") {
            sec -= 10;

            if(sec < 0) {
                min -= 1;
                sec = 60 + sec;
                
                if (min < 0) {
                    min = 0;
                    sec = 0;
                }
            }
        } else {
            sec += 10;

            if(sec > 60) {
                min += 1;
                sec -= 60;
            }

            // 영상의 남은 시간이 10초 미만일 때
            if(fin_min_tsb < min || (fin_min_tsb == min && fin_sec_tsb < sec)) {
                min = fin_min;
                sec = fin_sec;
            }
        }

        skip_opening(min, sec);
    }

    if (min < 10) answer += '0';
    answer += to_string(min) + ':';
    if (sec < 10) answer += '0';
    answer += to_string(sec);

    return answer;
}