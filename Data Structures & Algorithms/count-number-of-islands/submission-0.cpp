class Solution {
public:

    void bfs(int i, int j, vector<vector<char>>& grid, int n, int m) {

        queue<pair<int, int>> q;
        q.push({i, j});

        grid[i][j]='0';
        

        

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == '1') {

                    q.push({nr, nc});

                    grid[nr][nc]='0';

                
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    count++;
                    bfs(i, j, grid, n, m);
                }
            }
        }

        return count;
    }
};