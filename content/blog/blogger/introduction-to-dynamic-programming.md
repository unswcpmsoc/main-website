---
title: 'Introduction to Dynamic Programming'
date: 2022-06-26T02:36:00.090-07:00
draft: false
url: /2022/06/httpslevelup.gitconnected.comhow-to-think-recursively-solving-recursion-problems-in-4-steps-95a6d07aa866.html
tags: 
- beginner
author: 'Arushi Mittal'
image: 'https://lh3.googleusercontent.com/vqkXKz06tRz2P3HPxPJYaMk23839Zh4sLCMeI8GrDNouzcCz1A9CXwYRoPz2O8Ap56CXZO-2MZXXCYvDA7mAJ9frkQCEhjqw_UQ-hNGtr86HtuMLEehz0PL8NgHbNPDXzFhs1s9N0xW1qQxSYw'
summary: 'So you wanna see c some new programming, or some new epic pro-gamer moves to up your competitive programming skills.

Well, look no further with this CPMsoc blog on dynamic programming!'
---

_This is a quick 5 minute easy-to-read programme, for even the least experienced programmers._

  

So you wanna see c some new programming, or some new epic pro-gamer moves to up your competitive programming skills.

Well, look no further with this CPMsoc blog on dynamic programming!

  

Well, the obvious question is what is dynamic programming?

  

Dynamic programming is programming that is dynamic.

  

A quick google search would reveal (or at least according to Programiz), " _technique in computer programming that helps to efficiently solve a class of problems that have overlapping subproblems and optimal substructure property_."

  

What does this _actually_ mean though?

  

The paramount idea regarding dynamic programming circulates around the idea of sub-programs; essentially taking a large problem and breaking it down into smaller problems. Then, the values of the smaller-problems are saved to be used later to solve the initial, larger problem.

  

Accordingly, the key benefit of dynamic programming in comparison to other modes of problem-solving, is by _saving_ the result, is has the ability to optimize the solution by decreasing the repetition, thus increasing the overall-run time.

  

But before, we uncover more into dynamic programming, let's review recursion and memoization.

  

### RECURSION

![](https://lh3.googleusercontent.com/YGtOemhagb-61GvB-_ZvdQ4FN5urs02gQ42rlgnPnORcncE4tGbcesnwdXxVBWYhBW73oDqEiTx0Veg2LGNUOahoGO6AcQ7Zvg30KoE8ZncyON9PdZR0v8Lcc89_i0JTwNDQ6ocnHs-RFAoc0w)

  

  

Welp, we find ourselves asking ourselves, what is meant by recursion.

  

Once again, a quick, frantic google search uncovers that recursion can be defined as _"the determination of a succession of elements(such as numbers or functions) by operation on one or more preceding elements according to a rule or formula involving a finite number of steps"._

  

We can reconceptualise recursion with the aid of an example.

  

Let’s imagine that we need to calculate how many stairs are in total for the UNSW Stair of Dooms

Main Walkway. But since our programming overlords directors are busy the task falls on me. Now, due to let’s say my very limited mathematics skills and oversight fail in MATH1131, I lack the ability to count them incrementally. 

  

So, collectively, the members of CPMSoc came up with a solution.

  

Starting with me standing at the top of the staircase, on each step below me stands one CPMSoc member. So I ask the person in front of me how many steps there are, knowing that if the person in front of me says there is an "x" amount of stairs, there is in total and "x+1" amount of stairs. This is a _subproblem;_ I solve for "x + 1" amount of steps, instead of the initial total. Then, the person in front of me asks the same question who asks the person in front, and this goes on and on, until there is no one in front to ask. Once, we reach the bottom of the staircase, where no one is standing, that is the base-case, of zero individuals standing

  

Now, we know that eventually, as each, person asks the person in-front, we will reach the bottom where no person is standing. This principle is referred to as "_bottoming-out"_ in the context of recursion programming; a condition (in our case, the fact that at the bottom of the staircase there are ZERO people), that stops further calculation.

  

Below, enclosed are fragments of code that respectively use iteration and recursion. 

  

**Recursion vs Iteration**

#include  <stdio.h>

  

#define NUMBER\_VALUE\_OF\_STAIRS 1000

  

int main (void){

    int counter = 0;

    int actual\_number\_of\_steps = NUMBER\_VALUE\_OF\_STAIRS;

  

    while(counter < actual\_number\_of\_steps){

        counter++;

    }

  

    printf("There is a total of %d steps", counter);

}

  

  

  

int recursive\_function(n){

    if (n == 0){

        return 0;

    } else {

        return n + recurive\_function(n-1)

    }

}

  

  

  

_Technical Corner: If you are interested in Fibonacci Code and the difference in memory allocation for recursion and iteration a great resource to check alongside some practice question check out a great resource __[here](https://www.geeksforgeeks.org/recursion/). For more, information about the context, check out [there](https://levelup.gitconnected.com/how-to-think-recursively-solving-recursion-problems-in-4-steps-95a6d07aa866)._

  

Hopefully you learnt something so far other than a lot of pain could be saved if UNSW chose to install elevators. 

  

But, with a dramatic drumroll, we move on to the next section of our blog to....

  

  

### MEMOIZATION

Well memoization relays on key, principles of memory, specifically, _cache. _

Keeping in pattern of frantic-google-searches, an input of "What is a Cache" in Google prompts a swift response of "hardware or software that is used to store something, usually data, temporarily in a computing environment."

  

Cache is used often in our day-to-day lives; from deleting internet browser histories on how to arson UNSW to its benefits to programming optimization(a fun read on non-programming benefits can be found [here](https://auth0.com/blog/what-is-caching-and-how-it-works/)). 

  

Memoization is a subset of cache, where specifically the _return_ value in functions can be saved. In doing so, if a function is later called with the same input, the output can be generated, without need for calculation. 

  

This offers the key benefit of memoization: the optimisation benefits relaying to time-complexity as implementing memoization significantly reduces time of recalculating results. 

  

Whilst, this specific blog isn't going to focus as much as on the implementation of memoization, for those interested a great resource, I would recommend is [here](https://www.interviewcake.com/concept/java/memoization).

  

Now, as we move forward, we are going to look more closely at memoization in the context of dynamic programming.

### DYNAMIC PROGRAMMING

The benefits of dynamic programming are exhibited through the steps of calculating the Fibonacci problem. 

  

NOTE: As an exercise, after reading the explanation below, try yourself writing a programme to solve for Fibonacci sequences. See, how many different ways and methods can be used to conjure a result.

![](https://lh3.googleusercontent.com/vqkXKz06tRz2P3HPxPJYaMk23839Zh4sLCMeI8GrDNouzcCz1A9CXwYRoPz2O8Ap56CXZO-2MZXXCYvDA7mAJ9frkQCEhjqw_UQ-hNGtr86HtuMLEehz0PL8NgHbNPDXzFhs1s9N0xW1qQxSYw)

  

  

It is calculated, recursively, where the sub-problem is established by calculating incrementally smaller numbers. From the diagram above, it evidences how it "bottoms-out", until it reaches base cases of fib(1) and fib(0).

  

Next, memoization is implemented to, save the values of fib(1) and fib(0), so when recursively called upon, the results are already stored. The specific, type of dynamic programming we talked about this week is top-down which utilises memoization and recursion. If you are curious, into the implementations of various programmes to solve the Fibonacci sequence and the difference in implementations, a good exercise would be to peruse [this](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/), 

  

The next blog on Dynamic Programming will answer your remaining the burning questions: is bottom up dynamic programming or top down dynamic programming the most elite, which has better time complexity. 

  
That's all from us, folks!