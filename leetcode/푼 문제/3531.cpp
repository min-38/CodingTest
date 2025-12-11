class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        std::unordered_map<int, pair<int, int>> row_data;
        std::unordered_map<int, pair<int, int>> col_data;

        for (auto& building : buildings)
        {
            int x = building[0];
            int y = building[1];

            // row_data에 x 키에 데이터가 없으면 초기화
            if (row_data.find(x) == row_data.end())
                row_data[x] = { numeric_limits<int>::max(), numeric_limits<int>::min() };

            // col_data에 y 키에 데이터가 없으면 초기화
            if (col_data.find(y) == col_data.end())
                col_data[y] = { numeric_limits<int>::max(), numeric_limits<int>::min() };

            row_data[x].first = min(row_data[x].first, y);
            row_data[x].second = max(row_data[x].second, y);

            col_data[y].first = min(col_data[y].first, x);
            col_data[y].second = max(col_data[y].second, x);
        }

        int answer = 0;

        for (auto& building : buildings)
        {
            int x = building[0];
            int y = building[1];

            if (row_data[x].first < y && y < row_data[x].second
                    && col_data[y].first < x && x < col_data[y].second)
                answer++;
        }

        return answer;
    }
};