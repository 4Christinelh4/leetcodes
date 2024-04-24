#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // for each height, get the max width
        int l = heights.size();
        stack<int> smaller;
        // for each element in heights, only need to care about the 
        // index of the smaller element closest to it. For further smaller element
        // -> don't care because the width is already restricted
        vector<int> left_close_small(l, -1);
        vector<int> right_close_small(l, l);
        smaller.push(0);
        for (int i = 1; i < l; ++i) {
            while (!smaller.empty() && heights[smaller.top()] >= heights[i]){
                smaller.pop();
            }

            if (smaller.empty()) {
                left_close_small[i] = -1;
            } else {
                left_close_small[i] = smaller.top();
            }
            smaller.push(i);
        }
        while (!smaller.empty()) {
            smaller.pop();
        }

        smaller.push(l-1);
        for (int i = l-2; i >= 0; --i) {
            while (!smaller.empty() && heights[smaller.top()] >= heights[i]) {
                smaller.pop();
            }
            if (smaller.empty()) {
                right_close_small[i] = l;
            } else {
                right_close_small[i] = smaller.top();
            }
            smaller.push(i);
        }

        int res = 0;
        for (int i = 0; i < l; ++i) {
            res = std::max(res
            , heights[i] * (right_close_small[i] - left_close_small[i]-1));
        }
        return res;
    }
};