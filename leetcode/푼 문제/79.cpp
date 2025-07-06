class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        if (rows == 0) return false;

        cols = board[0].size();

        word_length = word.length();

        visited = vector<bool>(rows * cols, false);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i * cols + j] = true;
                    if (dfs(board, word, i, j, 1))
                        return true;
                    visited[i * cols + j] = false;
                }
            }

        return false;
    }

private:
    int rows, cols;
    int word_length;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<bool> visited;

    bool dfs(vector<vector<char>>& board, string& word, int y, int x, int widx)
    {
        if (widx == word_length)
            return true;

            
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < rows &&
                nx >= 0 && nx < cols &&
                board[ny][nx] == word[widx] &&
                !visited[ny * cols + nx])
            {
                visited[ny * cols + nx] = true;
            
                if (dfs(board, word, ny, nx, widx + 1))
                    return true;

                visited[ny * cols + nx] = false;
            }
        }
        return false;
    }
};
