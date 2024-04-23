#include <vector>
#include <set>
#include <iostream>

// O(n^2) solution
using namespace std;

int get_amount_bigger_inside(int bigger_nums, set<int> &nums_outside, int smaller_number) {
    // cout << "nums bigger than " << smaller_number << " is " << bigger_nums << endl;
    // cout << "inside the set (out range) " << distance(nums_outside.lower_bound(smaller_number), nums_outside.end()) << endl;
    return bigger_nums - distance(nums_outside.lower_bound(smaller_number), nums_outside.end());
}

// v.size() = n, elements from 1 to n
int longest_subsequence(vector<int> &v) {
    int n = v.size();
    int left = 0, right = n -1;
    int res = 2;

    set<int> outside;
    // left = right: result = 1
    // left + 1 = right: result = 2
    while (left < right) {
        // remove all numbers between left pointer and right pointer that are > right or > left
        if (v[left] < v[right]) {
            int bigger_than_left = n - v[left];
            // calculate how many elements in [0, left), (right, n) are bigger than v[left]
            // the number in [0, left), (right, n) that is bigger than v[left] and closest to v[left];
            // get_amount_bigger_inside(bigger_than_left, outside, v[left])-1: -1 to include v[right] in the subsequence
            res = std::max(res, right-left+1-(get_amount_bigger_inside(bigger_than_left, outside, v[left])-1));
            // increment left
            outside.insert(v[left]); 
            left ++;
        } else {
            int bigger_than_right = n - v[right];
            res = std::max(res, right-left+1-(get_amount_bigger_inside(bigger_than_right, outside, v[right])-1));
            // decrement right
            outside.insert(v[right]); 
            right --;
        }
    }
    return res;
}

int main() {
    vector<int> test1{ 7, 1, 2, 8, 5, 3, 6, 4 }; // 7 1 2 5 3 6 
    cout << longest_subsequence(test1) << endl;
    vector<int> test2{ 7, 9, 2, 8, 5, 3, 6, 4, 10, 1 }; // 9 2 8 5 3 6 4 10
    cout << longest_subsequence(test2) << endl;
    return 0;
}