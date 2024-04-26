#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

// the ways to get the word "byte"
class Solution {
    public: 
        map<int, char> m;
        vector<vector<vector<int>>> results;
        
        void get_byte(vector<vector<char>> &grid) {
            m[0] = 'b';
            m[1] = 'y';
            m[2] = 't';
            m[3] = 'e';

            int row = grid.size(), col = grid[0].size();

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == 'b') {
                        vector<vector<int>> cur_start;
                        cur_start.push_back({i, j});

                        dfs(grid, i, j, row, col, 1, cur_start);
                    }
                }
            }


            for (const vector<vector<int>> p: results) {
                for (const vector<int> coord: p) {
                    cout << "(" << coord[0] << ", " << coord[1] << ") -> ";
                }
                cout << endl;
            }
        }

        void dfs(vector<vector<char>> &grid, int curX, int curY
            , int row, int col, int idx, vector<vector<int>> &path) {
            if (idx == 4) {
                vector<vector<int>> copy_path(path);
                results.push_back(copy_path);
                return;
            }

            if (curX < 0 || curX >= row || curY < 0 || curY >= col) {
                return;
            }

            // |x - curX| + |y - curY| == 3
            vector<vector<int>> dirs {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {0, 3}, {0, -3}, {3, 0}, {-3, 0}
            , {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
            for (const vector<int> d: dirs) {
                int newX = curX+d[0], newY = curY+d[1];
                // cout << "------> " << idx << endl; 
                // cout << "newX " << newX << " newY " << newY << endl;
                if (newX >= 0 && newX < row && newY >= 0 && newY < col && m[idx] == grid[newX][newY]) {
                    path.push_back({newX, newY});
                    dfs(grid, newX, newY, row, col, 1+idx, path); // 2
                    path.pop_back();
                }
            }
        }
};

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<char>> g;
    string l;
    for (int k =0; k < row; ++k) {
        cin >> l;
        vector<char> cur;
        istringstream iss(l);

        string tok;
        while (std::getline(iss, tok, ',')) {
            cur.push_back(tok[0]);
        }
        g.push_back(cur);
    }

    Solution s;
    s.get_byte(g);
    return 0;
}