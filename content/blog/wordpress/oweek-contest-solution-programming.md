---
title: 'O-Week Contest 2023 Solutions (Programming)'
date: Sat, 25 Feb 2023 13:42:09 +0000
draft: false
tags: ['O-Week', 'Programming', 'Uncategorized']
author: 'David Zhou'
---

### Question 1: Binary Help

_Your computer_ has forgotten binary and it needs your help to do a calculation! <!--more--> Luckily, _the computer_ only needs help with calculating integers, and you won't have to worry about any decimals.

To help _the computer_, you need to find the next largest power of 2 after _the computer's number_.

**Solution**

To find the next largest power of 2 after N, one can check every ascending power of 2 until a power of 2 is found that is larger than N. This algorithm has a time complexity of O(log N), as N is up to a maximum of 10^18, which is approximately equal to 2^60.

### Question 2: Counting Rectangles

While doodling in your maths grid book, a friend comes up to you and draws a large rectangle on your page. The rectangle follows the lines of the page, so that it bounds a _a_ **W** by _**H**_ grid of squares. Your friend challenges you to count the number of different grid-aligned rectangles you could draw inside theirs. For example, these rectangles are valid:

**Solution**

**Brute force** - count every possible top, left, bottom, right edge of rectangle. An idea of implementation is to iterate through each coordinate as 4 points and count if it's a valid rectangle. There would be optimization can be made however it does the job.

```
def count_rectangles(a, b):
    count = 0
    for top in range(a):
        for left in range(b):
            for bottom in range(top + 1, a + 1):
                for right in range(left + 1, b + 1):
                    count += 1
    return count
```

**Maths** approach -

For the left and right edges, there are W + 1 possible choices for the left edge and W possible choices for the right edge (since the right edge can be to the right of the rightmost square). To avoid duplicate count, we divide it by 2.

Similarly, there are (H + 1) H choices for picking an edge for height. Result then be WH(W+1)(H+1))/4.

### Question 3: Burger

Since becoming the best chef in all of Melbourne, he's faced tough competition from others vying for his place. One challenger has been gaining popularity with a sort of circular sandwich, made with buns instead of bread. Not to be outdone, Michael has decided to make the perfect circular sandwich.

To achieve this goal, Michael starts with a rectangular slice bread measuring **W** mm by **H** mm. From this slice, he must cut out two identical circles to form the top and bottom of his sandwich. Since integers are the most perfect numbers, **the circles must have an integer diameter**.

Write a program to help Michael find the diameter of the largest pair of circles he can cut out of the slice of bread.

**Solution**

The solution involve bit knowledge of geometry, and some of common sense. First of all, by drawing the situation out, we can observe a relationship between radius and **H**, **W**. Follow this equation, there will be a method to derive a mathsmatical formula for the solution.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/image.png?w=873)

The programming approach would uses binary search to find the largest value of d such that the rectangle can fit inside the grid.

```
def can_fit(d, W, H):
    if d > W or d > H:
        return False
    elif d**2 > ((W-d)//2)**2 + ((H-d)//2)**2:
        return False
    else:
        return True

def find_largest_circle(W, H):
    l, r = 1, max(W, H) + 1
    while r - l > 1:
        m = (l + r) // 2
        if can_fit(m, W, H):
            l = m
        else:
            r = m
    return l

W = int(input("Enter the width of the grid: "))
H = int(input("Enter the height of the grid: "))

largest_radius = find_largest_circle(W, H)

print("The largest circles that can fit in the grid has a side length of", largest_radius)
```

### Question 4 Gerrymending

For this question I do not include description, click this [link](https://contest.unswcpmsoc.com/task/gerrymandering/) to view.

**Motivation**

This question is referring to a scenario where there are two candidates and we need to find the segment where one of them is leading the other. By mentioning the term "segment", it hints towards the possibility of multiple ways to solve the problem.

*   One possible approach is the "**divide and conquer**" method where we divide the problem into smaller subproblems and then solve them.
*   Another approach is the "**prefix array**" method, which is useful when the situation is static. It help us to find interval's info more efficiently.
*   Lastly, the "**binary search**" method may be used to find the start and end of the segment or to find the maximum difference and verify between the two candidates.

**Prefix array** is the most straightforward and plus this question doesn't looks complicate. The reason being, it allows us to compute the number of votes for each candidate in any segment of the line in constant time, i.e., O(1) time complexity.

If we define A's weight to be 1, and B's weight to be -1 so that they cancel each other, then our task is to find a contiguous subarray with the largest sum (represent A\*1 + B \* -1 = A - B!!!).

We use the prefix minima to find the smallest value seen so far in the prefix sum array, which represents the minimum value of any sub-array that **within index i**. By subtracting this value from the current prefix sum, we can get the **maximum value** of any sub-array that ends at index i. The **maximum sub-array** interval occurs when the prefix sum is at its highest and the prefix minima is at its lowest. So, we use the formula "max(prefix sum - prefix min)" to find the maximum sub-array interval.

```
def max_subarray_interval(line):
    prefix_sum = 0
    prefix_min = 0
    max_diff   = 0
    curr_diff  = 0

    # iterate over line
    for i, c in enumerate(line):
        # update vote counts
        counts[c] += 1

        # update prefix sum and prefix minima
        prefix_sum += (1 if c == 'A' else -1)
        prefix_min = min(prefix_min, prefix_sum)

        # calculate current difference and update max difference
        curr_diff = prefix_sum - prefix_min
        if curr_diff > max_diff:
            max_diff = curr_diff

    # determine winner
    winner = 'A' if counts['A'] > counts['B'] else 'B' if counts['B'] > counts['A'] else 'BOTH' 
```

### Question 5 Shape

Find the number of "convex" shape in a R x C grid, in which the shape is symmetric vertically and horizontally and cannot be contained in a smaller grid. A shape $P$ is convex if for all cells $c\_1, c\_2$ in $P$, if the line segment joining the centres of $c\_1$ and $c\_2$ passes the centre of a cell $c$, $c$ is also in $P$.

**Motivation**

This question is about making observations, according to the constraint.

*   The shape is symmetric, so we only need to focus on one quadrant (top right for example)
*   At least one square along the top row needs to be filled to make the shape the correct height, and everything between them must be filled as well
*   The top left corner of the quadrant must also be filled, as well as the bottom right corner
*   The entire left column and bottom row must be filled as well (so it's convex)

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/image-1.png?w=628)

*   Then precede, we would like to find valid ways to build the empty hole at the top right as shown in above image.
*   The problem becomes: find a **path** from the top left to the bottom right of the  
    grid, moving only right and down
*   At here, suppose that we pick a cell at the middle, suddenly we see that there are additionally square need to be filled.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/image-2.png?w=628)

*   Beside that, to satisfy diagonal constraint, we will see more square needs to be filled

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/image-3.png?w=628)

*   Another observation would be, after moving two steps down in a row, we can no longer move two steps right.

The solution uses dynamic programming to count the number of valid and convex shapes in a grid. The algorithm iterates over every cell in the grid using two nested loops, and for each cell, it computes the number of valid and convex shapes that can be formed with that cell as the top left and bottom right as shown above.

```
a_right[0][0] = 1

for i in range(R+1):
  for j in range(C+1):
    if j > 0:
      a_right[i][j] = (a_right[i][j-1] + a_down[i][j-1]) % mod
      b_right[i][j] = (b_down[i][j-1]) % mod
    if i > 0:
      a_down[i][j] = (a_right[i-1][j]) % mod
      b_down[i][j] = (a_down[i-1][j] + b_right[i-1][j] + b_down[i-1][j]) % mod
        
def solve(r, c):
  return (a_right[r][c] + a_down[r][c] + b_right[r][c] + b_down[r][c]) % mod

print(solve(R, C))
```