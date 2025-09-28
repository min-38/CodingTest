#include <string>
#include <vector>
#include <sstream>

using namespace std;

string replaceSharps(string melody)
{
    string result = "";
    for (int i = 0; i < melody.length(); ++i)
    {
        if (i + 1 < melody.length() && melody[i+1] == '#')
        {
            switch (melody[i])
            {
                case 'C': result += 'H'; break;
                case 'D': result += 'I'; break;
                case 'F': result += 'J'; break;
                case 'G': result += 'K'; break;
                case 'A': result += 'L'; break;
            }
            i++;
        }
        else
        {
            result += melody[i];
        }
    }
    return result;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    int max_duration = -1;

    m = replaceSharps(m);
    
    for (const string& musicinfo : musicinfos)
    {
        stringstream ss(musicinfo);
        string startTime, endTime, title, melody;

        getline(ss, startTime, ',');
        getline(ss, endTime, ',');
        getline(ss, title, ',');
        getline(ss, melody, ',');
        
        int start_min = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
        int end_min = stoi(endTime.substr(0, 2)) * 60 + stoi(endTime.substr(3, 2));
        int duration = end_min - start_min;

        string replaced_melody = replaceSharps(melody);

        if (replaced_melody.empty())
            continue;

        string full_melody = "";
        for (int j = 0; j < duration; j++)
            full_melody += replaced_melody[j % replaced_melody.length()];
        
        if (full_melody.find(m) != string::npos)
        {
            if (duration > max_duration)
            {
                max_duration = duration;
                answer = title;
            }
        }
    }

    return answer;
}