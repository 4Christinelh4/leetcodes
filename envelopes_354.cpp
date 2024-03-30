#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief we can solve the problem greedyly
     * we sort the array in the ascending order of envelope[0], then in the descending order of env[1]
     * we traverse the array, since we have to make sure strictly "greater"
     * for example, we have [3, 5], [3, 4], we prefer [3, 4] because 4 makes it more possible to be contained in nother
     * envelop whose width is > 3
     * 
     * 
     * @param envelopes 
     * @return int 
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> & v1
        , const vector<int> &v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }

            return v1[0] < v2[0];
        });


        vector<int> dp;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1] );
            if (it == dp.end()) {
                dp.push_back(envelopes[i][1]);
            } else {
                dp[it - dp.begin()] = envelopes[i][1];
            }
        }

        return dp.size();

    }
};