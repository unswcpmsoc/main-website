---
title: 'Uneven Divide and Conquer'
date: Tue, 03 Oct 2023 07:10:48 +0000
draft: false
tags: ['Divide &amp; Conquer', 'Programming', 'Uncategorized']
author: 'Angus Ritossa'
summary: 'Consider the problem _Efficient City_ from the [2022 South Pacific ICPC Divisional Contest](https://sppcontests.org/wp-content/uploads/2024/07/2022_Problemset_Divisionals_A.pdf). In this problem, there are $N$ cities, numbered from 1 to $N.$ Each city $i$ has a range of influence $\[L_i, R_i\]$ (where $1 ≤ L_i ≤ i ≤ R_i ≤$ $N$). Two cities $x$ and $y$ ($x \le y$)  can trade if there exists a city $i$ between them (i.e. $x ≤ i \le y$) where both $x$ and $y$ lie within the range of influence of city $i$ (that is, $L_i \le x$ and $y \le R_i$). We must answer a yes/no question: can every pair of cities trade?'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/bad.png?w=1024'
---

_Disclaimer: this blog is aimed at a reader who has some familiarity with the divide and conquer algorithmic paradigm (e.g. from COMP3121)._

Consider the problem _Efficient City_ from the [2022 South Pacific ICPC Divisional Contest](https://sppcontests.org/wp-content/uploads/2024/07/2022_Problemset_Divisionals_A.pdf). In this problem, there are $N$ cities, numbered from 1 to $N.$ Each city $i$ has a range of influence $\[L_i, R_i\]$ (where $1 ≤ L_i ≤ i ≤ R_i ≤$ $N$). Two cities $x$ and $y$ ($x \le y$)  can trade if there exists a city $i$ between them (i.e. $x ≤ i \le y$) where both $x$ and $y$ lie within the range of influence of city $i$ (that is, $L_i \le x$ and $y \le R_i$). We must answer a yes/no question: can every pair of cities trade?

### Example 1

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/bad.png?w=1024)

Example 1: The ranges of influence are listed on the left, and drawn on the right. Many cities can trade, for example:  
\- Cities 1 and 6 can trade due to city 5  
\- Cities 1 and 3 can trade due to city 3  
\- Cities 3 and 5 can trade due to city 4 or city 5  
However, the answer is no because cities 1 and 4 cannot trade.

### Example 2

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/good.png?w=1024)

Example 2: The ranges of influence are listed on the left, and drawn on the right. Cities 1 and 4 can now trade due to city 3. In fact, every pair of cities can trade and so the answer is yes.

We will now discuss a solution to this problem, so stop reading if you want to think about it first!

One initial observation is that, if the answer is yes, then there must exist a city whose range of influence is $\[1, N\]$: otherwise, cities 1 and $N$ cannot trade. Now, assume there exists some city $i$ that has a range of influence $\[1, N\]$. Then, any pair of cities $x$ and $y$ with $x ≤ i \le y$ can also trade. Thus, we now only need to check pairs of cities $x, y$ where $x \le y < i$  or $i < x \le y$. This motivates the following divide and conquer solution, which uses the above idea to recursively check whether every pair of cities can trade. In particular, `check(1, N)` will return true if and only if the answer is yes.

```
# check(l, r) returns true if every pair of cities (x, y) with l ≤ x ≤ y ≤ r can trade
check(l, r):
    # Base case: range is empty or has 1 city
    if r ≤ l:
        return true

    # Recursive case
    Check if there exists some i (with l ≤ i ≤ r) that covers the entire range (i.e. L_i ≤ l and r ≤ R_i):
    - If yes, return check(l, i-1) && check(i+1, r)
    - If no, return false 
```
{{< details "Click here to see the algorithm applied to Example 1" >}}
![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/bad-eg.png)
{{< /details >}}

{{< details "Click here to see the algorithm applied to Example 2" >}}
![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/good-eg.png)
{{< /details >}}

Let's analyse the worst-case time complexity of this algorithm. In divide and conquer, it is often useful to write the time complexity as a recurrence relation. Let $T(N)$ be the time complexity of a subproblem, where $N = r-l+1$. Additionally, assume that index $i$ exists, because we care about the $worst-case$ time complexity, and the runtime will be worse if $i$ exists due to the recursion. Define $k$ such that $i =$ $l+k$ and note that we do $O(N)$ work to find index $i$. Hence, we can write the relation as $T(N) = T(k) + T(N-k-1) + O(N)$.

We can't use the standard divide and conquer analysis, since the algorithm does not necessarily recurse into two equally-sized ranges. If we did, then $k$ would be $N/2$, and we would have $T(N) = 2T(N/2) + O(N)$. This would give an overall time complexity of $O(N$ log $N)$ - this can be proven directly, or using the Master theorem. Unfortunately, $k$ is not always $N/2$ and so this analysis is invalid.

In fact, the worst-case time complexity is $O(N^2)$. To see this, consider a case where each city $c$ has a range of influence $\[c, N\]$. Then, our recursive algorithm will consider the subproblems: $\[1, N\], \[2, N\], \[3, N\], ..., \[N, N\]$, with an overall running time of $O(N + (N-1) + (N-2) + ... + 1) = O(N^2)$.

Let's try to improve the time complexity. We assume that finding index $i$ takes $O(N)$ time. However, this is just the worst-case: we can early-exit as soon as we find an index that covers the entire range, meaning that we do not always need to do $O(N)$ work. For instance, assume that we check the indices in order $l, l+1, l+2, ..., r$ and stop as soon as we find a valid index $i$. Then the "worst-case" example from before will find the index $i$ in O(1) each time, resulting in a much better runtime of $O(N)$. Unfortunately, the case where each city $c$ has a range of influence $\[1, c\]$ will still take $O(N^2)$ time.

However, consider a different order: $l, r, l+1, r-1, l+2, r-2, l+3, r-3, ...$, that is, we work from the outside of the range, towards the middle. Then, using our notation of $i =$ $l+k$, it will take $O(\min(k, N-k))$ time to find this index. Our recurrence relation then becomes $T(N) = T(K) + T(N-k-1) + \min(K, N-k)$. I claim that this gives a worst-case time complexity of $O(N$ log $N)$, which is fast enough to fully solve the problem!

{{< details "Proof of $O(N \log N)$" >}}
We can prove it in a similar way to small merge (see the first part of [this blog](https://unswcpmsoc.blog/2023/07/04/small-merge-in-reverse-small-divide/) if you are not familiar). In particular, consider the recursive call tree (shown in the above diagrams). Each node in this tree is either a leaf, or has 2 children. The work done at a non-leaf node is the minimum of the size of its children. However, we can think of this like small merge: pretend that a recursive call is "merging" the results of its two children, taking time proportional to the size of the smaller child. Hence, we can use the same time complexity analysis as small-merge to prove that our modified algorithm runs in $O(N \log N)$.
{{< /details >}}

Since my blogs aren't complete without at least one gif, you can see the modified algorithm applied to each example.

{{< details "Click here to see the $O(N \log N)$ algorithm applied to example 1" >}}
![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/example1-gif.gif)
{{< /details >}}

{{< details "Click here to see the $O(N \log N)$ algorithm applied to example 2" >}}
![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/10/example2-gif.gif)
{{< /details >}}

Exercise
--------

Now it's your turn to solve a problem! You are given an array of integers and must answer a yes/no question: does every subarray contain a unique element (that is, an element that only occurs once in the subarray)? Try to solve this in $O(N$ log $N)$.

Example 1: \[3, 7, 3, 4, 9, 5, 9\]. Answer: yes

Example 2: \[3, 7, 3, 4, 9, 4, 9\]. Answer: no - the subarray \[4, 9, 4, 9\] does not contain a unique element.

The solution is left as an exercise to the reader.