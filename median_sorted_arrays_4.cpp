
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m <= n) {
            return partition(nums1, nums2);
        } else {
            return partition(nums2, nums1);
        }
    }

    /*
     * considering the time complexity - always do binary search on the
     * shorter vector
     * @v1: the shorter vector
     */
    double partition(vector<int> &v1, vector<int> &v2) {
        int m = v1.size(), n = v2.size();
        int mid = 0;
        // if m+n = 2*k, indices should be mid and mid-1
        // if (v2[0] >= v1[m-1]) {
        //     if ((m+n)%2 == 0) {
        //         if (m == n) {
        //             return (v1[m-1] + v2[0])/2.0;
        //         } else {
        //             // m < n
        //             return (v2[mid-1-m] + v2[mid-m])/2.0;
        //         }
        //     } 
        //     // m!=n and m<n and m+n = 2k+1
        //     return v1[(m+n)/2 - m];

        // } else if (v1[0] > v2[n-1]) {
        //     if ((m+n)%2 == 0) {
        //         return (v2[mid] + v2[mid-1])/2.0;
        //     }
        //     return v2[mid];
        // }

        // partition v1 and v2 into 2 halves
        // make sure that the numbers on LHS = numbers on RHS or 
        // numbers on LHS = 1 + numbers on RHS
        // it's guaranteed that LHS contains some from v1 some from v2
        // RHS contains some from v1 some from v2
        // initially, participated from the mid of v1
        int high = m, low = 0;
        while (high >= low) {
            mid = (high + low)/2; // high = 5, low = 0: mid = 2
            int partition_v2 = (1+m+n)/2 - mid;
            int v1_left = (mid == 0)? INT_MIN: v1[mid-1];
            int v1_right = (mid == m)?INT_MAX: v1[mid];
            
            int v2_left = (partition_v2 == 0)? INT_MIN: v2[partition_v2-1];
            int v2_right = (partition_v2 == n)? INT_MAX: v2[partition_v2];

            if (v1_left <= v2_right && v2_left <= v1_right) {
                // finish partition
                if ((m+n)%2 == 0) {
                    return (std::max(v1_left, v2_left) + std::min(v1_right
                    , v2_right))/2.0;
                } else {
                    return (std::max(v1_left, v2_left));
                }
            } else if (v1_left > v2_right) {
                high = mid-1;
            } else {
                low = mid+1;
            }

        }

        return 0;
    }
};