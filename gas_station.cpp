#include <iostream>
#include <vector>

using namespace std;

/* 
    Let len = gas.size();
    Obviously, we need to find i, so that: 
    for (int m = 0; m < len; ++m):

    gas[ (i+m) % len] - cost[ (i+m) % len] >= 0 holds for all m

    So, it's clear that 
        1. when sum(gas) >= sum(cost), the i exists
        proof: for any i in [0, len), 

        gas[(i+0)%len] + gas[(i+1)%len]... + gas[(i+len-1)%len] = sum(gas)
        >= sum(cost) = cost[(i+0)%len] + cost[(i+1)%len]... + cost[(i+len-1)%len]

        which means

        (gas[(i+0)%len] - cost[(i+0)%len]) + (gas[(i+1)%len] - cost[(i+1)%len]) + ...... 
        + (gas[(i+len-1)%len] - cost[(i+len-1)%len]) >= 0


 */

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost ) {
            int n = gas.size();
            int total_gas = 0, total_cost = 0, current_gas = 0;
            int res = 0;
            
            for (int i =0; i <n; ++i) {

                total_gas += gas[i];
                total_cost += cost[i];

                current_gas += gas[i];
                current_gas -= cost[i];

                if (current_gas < 0) {
                    res = i+1;
                    current_gas = 0;
                }
                
            }

            if (total_cost > total_gas) {
                return -1;
            }

            return res;
        }
};