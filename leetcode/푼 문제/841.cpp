class Solution {
public:
    vector<bool> visited;
    int count = 0;

    void visit(int cur_idx, vector<vector<int>>& rooms) {
        for (int key : rooms[cur_idx])
            if (!visited[key]) {
                visited[key] = true;
                count++;
                visit(key, rooms);
            }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited = vector<bool>(rooms.size(), false);
        visited[0] = true;
        count++;
        visit(0, rooms);

        return count == rooms.size() ? true : false;
    }
};