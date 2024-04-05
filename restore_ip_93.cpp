#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        int l = s.size();
        if (l > 12 || l < 4) {
            return {};
        } 

        vector<string> curDiv;
        helper(curDiv, 0, s);
        return res;
    }

    bool valid(string &tmp) {
        if (tmp.size() > 3 || tmp.size() == 0) {
            return false; 
        }

        if (tmp.size() > 1 && tmp[0]  == '0') {
            return false;
        }

        if (stoi(tmp) > 255) {
            return false;
        }

        return true;
    }

    // idx is the last of current division!!!!
    void helper(vector<string> &cur, int idx, string & s) {
        if (cur.size() == 3) {
            string ip = "";
            // check all 4 parts, if eligible, push the string to res
            for (int i = 0; i < 3; ++i) {
                auto tmp = cur[i];
                if (! valid(tmp)) {
                    return;
                }
                ip += tmp;
                ip += ".";
            }

            // check the last
            string last = s.substr(idx, s.size() - idx);
            if (!valid(last)) {
                return ;
            }

            ip += last;
            res.push_back(ip);
            
            return;
        }

        // if s .size = 12: 3 3 3 3

        int start = 1; // sub size must <= 3
        if (s.size() == 12) {
            start = 3; 
        }

        // idx = 9, start = 3: 9 10 11

        for (; start <= 3 && idx + start <= s.size(); ++start) {
            // start = 1:
            // idx = 0: ss= '2'
            // idx = 1

            // idx = 3; start = 3;
            //  0 1 2 [3 4 5] 6 
            
            string ss = s.substr(idx, start);
            cur.push_back(ss);

            helper(cur, start+idx, s);
            cur.pop_back();
        }
    }
};