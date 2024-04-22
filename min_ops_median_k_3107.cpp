#include <vector>
#include <algorithm>

using namespace std;
/**
 * @brief this question is straightforward once you sort the array
 * we only need to compare current mid with k, and we either increase
 * numbers at left or increase numbers at right
 */
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long res = 0;
        sort(nums.begin(), nums.end());

        int idxMid = nums.size()/2;
        if (nums[idxMid] == k) {
            return 0;
        } else if (nums[idxMid] > k) {
            for (int j = idxMid; j >= 0; --j) {
                if (nums[j] <= k) {
                    break;
                }
                int diff = nums[j] - k; 
                res += diff;
            }

        } else {
            for (int j = idxMid; j < nums.size(); ++j) {
                if (nums[j] >= k) {
                    break;
                }

                int diff = k - nums[j];
                res += diff;
            }
        }

        return res;
    }
};