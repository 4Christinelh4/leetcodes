'''
Leetcode 983:
This is a top-down DP problem. At any day in days list, we can choose 
among 1-day pass, 7-day pass or 30-day pass.

On day 0, for each choice, the total cost for the travelling would be 
(1): 1-day pass: costs[0] + all costs from the next day in the days list
(2): 7-day: costs[1] + all costs from the day after day 7 in the days list
(3): 30-day: costs[2] + all costs from the day after day 30 in the days list
We want to have the smallest of the 3 choices, so the result should be min((1), (2), (3))

There is a recursion relation, so we define
buy(current_day): the MIN costs for travelling [day i in list, last day in list]

To make it faster, we use memo. We have array dp, the length = length of days list.
It records the result of buy(current_day).
Therefore, when we in dat i in one recursive call (perhaps from another choice...),
if we already have calculated the min costs for travelling [day i in list, last day in list], 
we can directly take it from the dp, instead of calculating again. 

'''

def mincostTickets(days: list, costs: list) -> int:

    dp = {}
    for day in days:
        dp[day] = -1
    
    def buy(current_day, index):
        if dp[current_day] != -1:
            return dp[current_day]
        
        if index == len(days):
            return 0
        
        if current_day == days[-1]:
            opt1 = costs[0]
        else:
            opt1 = costs[0] + buy(days[index+1], index+1)
        
        last_day7 = current_day + 6
        last_day7_idx = -1

        for i in range(index, len(days)):
            if days[i] > last_day7:
                last_day7_idx = i
                break
        
        if last_day7_idx == -1:          
            opt2 = costs[1]
        else:
            opt2 = costs[1] + buy(days[last_day7_idx], last_day7_idx)

        last_day30 = current_day + 29
        last_day30_idx = -1

        for i in range(index, len(days)):
            if days[i] > last_day30:
                last_day30_idx = i
                break
        
        if last_day30_idx == -1:
            opt3 = costs[2]
        else:
            opt3 = costs[2] + buy(days[last_day30_idx], last_day30_idx)

        dp[current_day] = min(opt1, opt2, opt3)
        return dp[current_day]

    return buy(days[0], 0)


res = mincostTickets( [1,2,3,4,5,6,7,8,9,10,30,31], [2, 7, 15])
print(res)
