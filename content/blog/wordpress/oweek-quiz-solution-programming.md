---
title: 'O-Week Quiz 2023 Solutions (Programming)'
date: Sat, 11 Feb 2023 06:40:50 +0000
draft: false
tags: ['Dynamic Programming', 'Greedy algorithms', 'O-Week', 'Programming', 'Uncategorized']
author: 'David Zhou'
---

Thank you for participating in the O-Week quiz - we hope you had fun! We look forward to hosting more quizzes and articles throughout the year.

<!--more-->

### Question 1

Bob and Alice are looking for the cheapest way to purchase tickets for a cross-country train ride that they have planned. They are considering a 1-day, 7-day, or 30-day pass, each with a different price.

We can use simple **recursion** to write a program to solve this problem. **Recursion** is a programming technique that refers to a process in which a function calls itself repeatedly, for this problem we can define a function takes current days and it returns the minimum cost for travel rest of days.

```
# - travel stores days of travel
# - cost stores the cost of each ticket
def mincostHelper(travel, costs, currDate, endDate):
    # Base case: 
    # As current date great than endDate, there is no need to travel anymore, it took 0 to complete the journey
    if currDate > endDate:
        return 0
    
    # Recursive case
    # Always return the minimum cost for travel the rest of days
    if currDate not in travel:
        # Skip this date
        return mincostHelper(travel, costs, currDate + 1, endDate)
    else:
        return min(
mincostHelper(travel, costs, currDate + 1, endDate) + costs.oneDay, 
mincostHelper(travel, costs, currDate + 7, endDate) + costs.sevenDays,
mincostHelper(travel, costs, currDate + 30, endDate) + costs.thirtyDays
       ) 
```

We can use **Dynamic Programming (DP)** to optimize our solution. **DP** is a technique that involves breaking down a problem into smaller sub-problems and storing the results of those sub-problems. It is primarily used to optimize problems where the solution can be decomposed into independent subproblems.

For this problem, we will make an array **dp\[i\]** that stores the cost of fulfilling a travel plan from day i to the end of the plan. If we have to travel on the ith day, we have three options: we can buy a 1-day pass (**dp\[i+1\]**), a 7-day pass (**dp\[i+7\]**), or a 30-day pass (**dp\[i+30\]**). We will choose the option that gives us the minimum cost, that is, the minimum of **dp\[i+1\]**, **dp\[i+7**\] and **dp\[i+30\]**. If we don't have to travel on the ith day, then we will not buy any pass and the cost is zero.

We only need to do a slight change to the above code, it then will save us a lot of repetitive computation,

```
# - travel stores days of travel
# - cost stores the cost of each ticket
# - dp[i] = minimum cost to travel rest of days from day i
def mincostHelper(travel, costs, dp, currDate, endDate):
    # Base case: 
    # As current date great than endDate, there is no need to travel anymore, it took 0 to complete the journey
    if currDate > endDate:
        return 0

    # Check if result is stored 
    if currDate in dp:
        return dp[currDate]

    # Recursive case
    # Always return the minimum cost for travel the rest of days
    if currDate not in travel:
        # Skip this date
        dp[currDate] = min(dp[currDate], dp[currDate - 1])
        return mincostHelper(travel, costs, currDate + 1, endDate)
    else:
        dp[currDate] = min(
mincostHelper(travel, costs, currDate + 1, endDate) + costs.oneDay, 
mincostHelper(travel, costs, currDate + 7, endDate) + costs.sevenDays,
mincostHelper(travel, costs, currDate + 30, endDate) + costs.thirtyDays
       )
        return dp[currDate] 
```

**Time Complexity**: O(T) where T = maximum numbered day in travel plan. In our DP solution, we ask maximuly T questions, and each question can be answered in O(1) time knowing answer from other questions.

**Space Complexity**: O(T)

### Question 2

Bob and Alice is looking for an optimized solution to store suicase into warehouse.

We can make several observations towards this question. Firstly, the goal is to get as many boxes inside the warehouse and the size of the box does not matter. Secondly, if there is a narrow section of the warehouse, even if it becomes wide afterwards, the boxes will still get stuck right before it. This is due to the fact that the boxes will not be able to fit through the narrow section, thus resulting in a bottleneck situation. Thirdly, it is common sense to assume that if a small box gets stuck, then bigger boxes will also get stuck.

From above observation, we seems able to construct a **Greedy Solution** toward this problem. **Greedy algorithms** are a type of algorithm that makes localized decisions in order to optimize a global goal, it make optimal decisions at each step, according to a specific set of rules, and always aim to make the best decision at that moment in time. **Greedy algorithms** may not exist in some cases, and if we want to use it to solve a certain question, we would need to prove it. On the otherhand, the technical **Dynamic programming** we used in first question examine all possible situation, thus give the optinmal solution.

We propose, by insert the boxes in acending order, we can always reach most optimized solution. To show our proposal is correct, we prove by **contradiction** (a high school maths technique!??).

We propose, at a certain step where we insert the boxes, we can get an optimzied solution if we choose to insert a larger box than the smallest box we have. There are two situation we have

*   If the larger box we choose stuck eariler in the "bottleneck" situation we described earlier. Than it's always worse than we insert the smallest one first and the largest box.
*   If the larger box stuck at the same place as the smaller box, it means the warehouse's height before that place are greater than larger box, and thus greater than smallest box. In this case, it does not matter if we put smallest first, or the larger one.