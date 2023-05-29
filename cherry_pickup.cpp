/*
    Leetcode 741

    To go to [n-1, n-1], then go back to [0, 0], this can be treat as 2 paths start from [0, 0] to [n-1, n-1]
    we also have r1+c1 = r2+c2: [0, 0] -> [0, 1] OR [1, 0], sum = 1, 
    [0, 1] -> [1, 1] or [0, 2], sum = 2, ... r1+c1 = steps = r2+c2, and finally sum of steps will be 2*n-2
    we want to use a recursive way to know the max cherry, however, we will also use a memo to record the 
    max cherry when the status is [r1, c1], [r2, c2]
    finally, we want to know the max cherry at the initial status: [0, 0], [0, 0]

    to make sure none of the path takes throns or goes out of the grid, we can return a very small number in that cases
    when [r1, c1] goes to [n-1, n-1], [r2, c2] is on [n-1, n-1] to. 

    it's obvious that dp[r1][c1][r2] = grid[n-1][n-1]
 */
#include <vector>
#include <iostream>

using namespace std;

bool check(int i, int n) {
    return i < 0 || i >= n;
}

int _pick_cherry(int r1, int c1, int r2, int n, vector<vector<vector<int> > > &dp
, vector<vector<int> > &grid) {
    int c2 = r1+c1-r2;

    if (check(r1, n) || check(r2, n) || check(c1, n) || check(c2, n)) {
        return -1e7;
    }

    if (dp[r1][c1][r2] != -1e7) {
        return dp[r1][c1][r2];
    }

    if (r1 == n-1 && c1 == n-1) {
        dp[r1][c1][r2] = grid[n-1][n-1];
        return grid[n-1][n-1];
    }

    int res = 0;

    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
        return -1e7;
    }

    if (r1 == r2 && c1 == c2) {
        if (grid[r1][c1] == 1) {
            res ++;
        }
    } else {
        res += grid[r1][c1];
        res += grid[r2][c2];
    }

    int opt1 = _pick_cherry(r1+1, c1, r2+1, n, dp, grid); // both move down
    int opt2 = _pick_cherry(r1+1, c1, r2, n, dp, grid); // one down, one right
    int opt3 = _pick_cherry(r1, c1+1, r2, n, dp, grid); // both right
    int opt4 = _pick_cherry(r1, c1+1, r2+1, n, dp, grid); // one right, one down

    dp[r1][c1][r2] = res + max(max(opt1, opt2), max(opt3, opt4));
    return dp[r1][c1][r2];
}

int cherryPickup(vector<vector<int> > & grid) {
    int n = grid.size();
    vector<vector<vector<int> > > dp(n, vector<vector<int>> (n, vector<int> (n, -1e7)));

    _pick_cherry(0, 0, 0, n, dp, grid);
    return max(0,dp[0][0][0]);
}

