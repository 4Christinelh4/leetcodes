#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(100, vector<int>(100, -1));
        return matching(s1, 0, m, s2, 0, n, s3, dp);
    }

    bool matching(string &s1, int i, int m, string &s2, int j, int n, string &s3
    , vector<vector<int>> &dp) {
        if (i == m) {
            // return s2 and the rest of s3 matching
            return s2.substr(j, n-j) == s3.substr(i+j, n-j);
        }

        if (j == n) {
            // return s1 and the rest of s3 matching
            return s1.substr(i, m-i) == s3.substr(i+j, m-i);
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool flag = false;
        
        if (s1[i] == s3[i+j]) {
            flag |= matching(s1, i+1, m, s2, j, n, s3, dp);
        }
        if (s2[j] == s3[i+j]) {
            flag |= matching(s1, i, m, s2, j+1, n, s3, dp);
        }
        dp[i][j] = flag;
        return flag;
    }
};