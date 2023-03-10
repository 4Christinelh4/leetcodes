#include <vector>
#include <queue>
#include <set>
#include <stdio.h>

// 9*9 grid

using namespace std;

bool visited(int r, int c, set<vector<int>> &s) {

    for (auto it = s.begin(); it != s.end(); ++it) {
        if ( (*it)[0] == r && (*it)[1] == c) {
            return true;
        }
    }

    return false;
}

// ******** number of moves from start to end ********
void bfs_1(int r_start, int c_start, int r_end, int c_end) {
    int steps = 0;
    vector<int> start = {r_start, c_start};
    queue<vector<int>> q;
    set<vector<int>> vis;

    vis.insert(start);
    q.push(start);

    vector<vector<int>> dirs = { {2, 1}, {2, -1}, {-2, -1}, {-2, 1}
    , {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};

    while (!q.empty())  {
        int sz = q.size();

        for (int i = 0; i < sz; ++i) {
            vector<int> cur_pos = q.front();
            q.pop();

            int r1 = cur_pos[0];
            int c1 = cur_pos[1];

            if (r1 == r_end && c1 == c_end) {
                printf("shortest steps = %d\n", steps);
                return;
            }

            for (int k = 0; k < 8; ++k) {
                int rn = r1 + dirs[k][0];
                int cn = c1 + dirs[k][1];

                if (rn>=0 && rn<9 && cn>=0 &&cn<9 && !visited(rn, cn, vis)) {
                    q.push({rn, cn});
                    vis.insert({rn, cn});
                }
            }
        }
        
        ++ steps;
    }
}

// ******** print all paths from start to end ********
void bfs_2(int r_start, int c_start, int r_end, int c_end) {

    vector<int> start = {r_start, c_start};

    vector<vector<vector<int>>> paths;
    queue<vector<vector<int>>> q;

    set<vector<int>> vis;
   
    q.push({start});
    vis.insert(start);

    vector<vector<int>> dirs = { {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

    while (! q.empty()) {
        vector<vector<int>> cur_path = q.front();
        q.pop();

        vector<int> last_node = cur_path[cur_path.size() -1];
        
        for (int j = 0; j < dirs.size(); j++) {

            int rn = last_node[0] + dirs[j][0];
            int cn = last_node[1] + dirs[j][1];

            if (rn >= 0 && rn < 9 && cn>= 0 && cn < 9 && !visited(rn, cn, vis)) {
                vector<vector<int>> cur_path_1(cur_path);
                cur_path_1.push_back({rn, cn});
                vis.insert({rn, cn});


                if (rn == r_end && cn == c_end) {
                    // don't push
                    printf("===========================\n");
                    for (auto it = cur_path_1.begin(); it != cur_path_1.end(); ++it) {
                        printf("{%d %d} ", (*it)[0], (*it)[1]);
                    }
                    printf("\n===========================\n");
                } else {
                    q.push(cur_path_1);
                }
            }
        }
    }
}

int main() {

    bfs_1(4, 4, 4, 8);

    bfs_2(4, 4, 4, 8);

    return 0;
}