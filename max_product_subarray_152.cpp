#include <vector>

using namespace std;

class Solution {
    public:
        int maxProduct(vector<int> &nums) {
            int l = nums.size();
            vector<int> maxProds(l, 0);
            maxProds[0] = nums[0];
            vector<int> minProds(l, 0);
            minProds[0] = nums[0];

            for (int i = 1; i < l; ++i) {
                if (nums[i] == 0) {
                    maxProds[i] = 0;
                    minProds[i] = 0;
                    continue;
                }

                if (i > 0 && maxProds[i-1] == 0 ) {
                    maxProds[i] = nums[i];
                    minProds[i] = nums[i];
                    continue;
                }

                maxProds[i] = std::max(nums[i]*maxProds[i-1], nums[i]*minProds[i-1]);
                maxProds[i] = std::max(nums[i], maxProds[i]);
                minProds[i] = std::min(nums[i]*maxProds[i-1], nums[i]*minProds[i-1]);
                minProds[i] = std::min(nums[i], minProds[i]);
            }

            int res  = maxProds[0];
            for (int i = 1; i < l; ++i) {
                res = max(res, maxProds[i]);
            }

            return res;
        }
};