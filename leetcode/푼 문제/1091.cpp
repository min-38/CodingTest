class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if(n == 1) return (grid[0][0] == 0) ? 1 : -1;

        vector<vector<int>> distance(n, vector<int>(n, 1e9));

        queue<pair<int, pair<int, int>>> q;
        
        distance[0][0] = 0;
        q.push({ 0, { 0, 0 } });
        
        int dx[] = {0, 0, -1, 1, -1, 1, 1, -1};
        int dy[] = {1, -1, 0, 0, -1, -1, 1, 1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int y = it.second.first;
            int x = it.second.second;

            for (int i = 0; i < 8; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n &&
                    newY >= 0 && newY < n &&
                    grid[newY][newX] == 0 &&
                    dis + 1 < distance[newY][newX]
                )
                {
                    distance[newY][newX] = dis + 1;

                    if(newY == n - 1 && newX == n - 1)
                        return distance[newY][newX] + 1;

                    q.push({ dis + 1, { newY, newX } });
                }
            }
        }
        return -1;
    }
};