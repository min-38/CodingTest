class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;

        int senate_length = senate.length();
        for (int i = 0; i < senate_length; i++)
            if (senate[i] == 'R')
                rq.push(i);
            else
                dq.push(i);

        while (!rq.empty() && !dq.empty()) {
            if (rq.front() < dq.front())
                rq.push(rq.front() + senate_length);
            else
                dq.push(dq.front() + senate_length);

            dq.pop();
            rq.pop();
        }

        if (!rq.empty())
            return "Radiant";
        return "Dire";
    }
};