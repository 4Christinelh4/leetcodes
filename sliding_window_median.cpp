#include <vector>
#include <queue>

using namespace std;

class Solution {

    public:

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;    
        
        // max_heap.size() ==  min_heap.size() 
        // or max_heap.size() = 1 + min_heap.size()
        void rebalance() {

            if (max_heap.size() >= min_heap.size() + 2) {
                min_heap.push(max_heap.top());
                max_heap.pop();
                return;
            }

            if (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
                return;
            }
        }

        void add_num(int num) {
            if (max_heap.size() == 0) {
                max_heap.push(num);
                return;
            }

            if (num <= max_heap.top()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }

            rebalance();
        }
        
        void remove_num(int num) {

            vector<int> tmp;
            if (num <= max_heap.top()) {
                while (!max_heap.empty()) {
                    if (max_heap.top() == num) {
                        max_heap.pop();
                        break;
                    }

                    tmp.push_back(max_heap.top());
                    max_heap.pop();
                }

                for (int j = 0; j < tmp.size(); ++j) {
                    max_heap.push(tmp[j]);
                }

            } else {
                while (!min_heap.empty()) {
                    if (min_heap.top() == num) {
                        min_heap.pop();
                        break;
                    }

                    tmp.push_back(min_heap.top());
                    min_heap.pop();
                }

                for (int j = 0; j < tmp.size(); ++j) {
                    min_heap.push(tmp[j]);
                }
            }

            rebalance();
        }
        
        vector<double> medianSlidingWindow(vector<int> &nums, int k) {
            int left = 0, right = k;
            vector<double> res;

            for (int i = 0; i < k; i++) {
                add_num(nums[i]);
            }

            while (right <= nums.size()) {
                if (k%2 == 0) {
                    res.push_back(0.5*min_heap.top() + 0.5*max_heap.top());
                } else {
                    res.push_back(max_heap.top());
                }

                if (right ==  nums.size()) {
                    break;
                }

                int cur_left = nums[left];
                ++left;

                remove_num(cur_left);
                int cur_right = nums[right];
                ++right;
                add_num(cur_right);
            }

            return res;

        }

};
