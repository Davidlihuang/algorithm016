class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        //terminal condition
        if( i< 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;
        
        //process
        grid[i][j] = '0'; //标记已经访问过的

        //drill down
        DFS(grid, i-1, j);
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i, j+1);

    }

    int DFSTraverse(vector<vector<char>>& grid) {
        int numsofisland = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ++numsofisland;
                    DFS(grid, i, j);
                }
            }
        }
        return numsofisland;
    }
    int BFS(vector<vector<char>>& grid) {
        int nr = grid.size();
        if(!nr) return 0;
        int nc = grid[0].size();
        
        int num_islands = 0;
        for(int r = 0; r < nr; r++) {
            for(int c = 0; c < nc; c++) {
                 if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
    int numIslands(vector<vector<char>>& grid) {
       // return BFS(grid);
       return DFSTraverse(grid);
    }
};