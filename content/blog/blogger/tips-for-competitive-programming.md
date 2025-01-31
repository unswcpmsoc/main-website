---
title: 'Tips for Competitive Programming'
date: 2022-07-22T00:12:00.017-07:00
draft: false
url: /2022/07/tips-for-competitive-programming.html
tags: 
- beginner
- advanced
author: 'Ryan Ong'
image: 'https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiyu7Hkzw3GnpGD-ZlfRpC82-veCXt7gdOyHLJIn29ugNcEa29VCK8tcw1gC_71YHNM1FTMMrWMQRzldbpTx5zTUQkcA4QI6k2f3z1nL0xk9VieeTFu23TntPTA8sGp6WvUFDoAYsPMD9DGzGX_q8icNiUiu3U6ON9bCxhhmjr9VsKjhoqthMt_ZykC/s320/Konohata_Mira_Reads_Introduction_to_Algorithms.jpeg'
---

Competitive programming is by no means easy, I struggled with it for a long time. In this post I want to provide some helpful tips, which will hopefully be helpful to you at any stage in your competitive programming journey.

<!--more-->

[![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiyu7Hkzw3GnpGD-ZlfRpC82-veCXt7gdOyHLJIn29ugNcEa29VCK8tcw1gC_71YHNM1FTMMrWMQRzldbpTx5zTUQkcA4QI6k2f3z1nL0xk9VieeTFu23TntPTA8sGp6WvUFDoAYsPMD9DGzGX_q8icNiUiu3U6ON9bCxhhmjr9VsKjhoqthMt_ZykC/s320/Konohata_Mira_Reads_Introduction_to_Algorithms.jpeg)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiyu7Hkzw3GnpGD-ZlfRpC82-veCXt7gdOyHLJIn29ugNcEa29VCK8tcw1gC_71YHNM1FTMMrWMQRzldbpTx5zTUQkcA4QI6k2f3z1nL0xk9VieeTFu23TntPTA8sGp6WvUFDoAYsPMD9DGzGX_q8icNiUiu3U6ON9bCxhhmjr9VsKjhoqthMt_ZykC/s512/Konohata_Mira_Reads_Introduction_to_Algorithms.jpeg)

  
  
  

How do I read problems?
-----------------------

*   Read all the problems

*   It is not always the case that the first problem is the easiest, because it cannot be assumed that problems are in difficulty order. Even if it was in "difficulty order", what the tutors think is difficult may be different from what you think is difficult.

*   Read all the subtasks (this doesn't apply for contests such as ICPC)

*   Subtasks help guide you towards observations and partial solution by presenting helpful subproblems. Note that this isn’t always to case, don’t get hung up trying to find the link between subtasks and the complete solutions.

*   Read the sample cases and explanation

*   The sample cases are there to solidify your understanding of the problem. Read them and make sure your understanding of the problem matches the sample case explanations.

How do I solve problems?
------------------------

*   Does the problem remind you of a problem you’ve seen before?

*   What does your program need to output? Have you been asked to output similar things before?
*   What are the systems being described in the problem? Have you seen similar or the same systems described in other problems? Do observations from those problems carry over to this problem?
*   What category(s) does the problem look like it falls into? Run through every technique you know and see if it is applicable. (e.g. dynamic programming, graph theory, data structures, …)
*   You will be able to relate new problems to ones you’ve seen before. Of course, the solution to similar problems might look nothing like each other, but some of the time you spent thinking about any given problem can be transferred to similar problems. Once you’ve done some problems in this space, you’ll develop intuitions and observations about it that you can apply later. For example, Manhattan distance is a common element in a lot of problems, after doing some problem you may realise that “the x and y components can be computed independently” is a useful observation.

*   Look at it from a different perspective

*   Can you break the problem into simpler parts? For example, a problem may require you to interpret an array as a graph, then perform some graph algorithm on it.
*   Perhaps you can reframe the problem in a different way. For example, sorting can be done in many different ways, and some paths of thinking will lead to more efficient solutions.

*   Consider subtasks

*   Create your own subtasks! Add/remove constraints to make the problem simpler. Why is this simplified problem easier, but the full problem not? This can give you an idea for what part of the problem to tackle.

*   What are the bounds?

*   Knowing the bounds informs the type of solution you are looking for. Knowing the approximate time complexity can inform you on the type of solution you are looking for. For example, a problem gives you an array A of size N, and wants you to find a contiguous subarray that maximises {insert some scoring function here}. If ![N <= 1000](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=N\le 1000), you could look for an ![O(N^2](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(N^2)) solution. Then some things to consider are:

*   There’s time to evaluate every interval ![O(N^2)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(N^2)), but you need to compute the scoring function quickly.
*   Perhaps you could try each of the ![O(N)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(N)) start points, and expanding out?
*   Perhaps you could try each of the ![O(N)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(N)) possible sizes of the subarray?

I take so long to code! How do I improve my implementation?
-----------------------------------------------------------

*   Time spent on paper is better than time spent on the keyboard – this also helps for scrutinising your algorithm when debugging logic errors. A "keyboard curfew" is a good idea, this is when you prohibit yourself from using the keyboard for the first 30 minutes.

*   Pseudocode

*   You often type faster than your brain can think, working on paper often means more well thought out code. Usually, time spent writing things down and thinking about your solution is worth it for the time spent coding and debugging.
*   Writing code out in full is probably a bit overkill for informatics, I think pseudocode is a good middle ground.

*   Correctness

*   Are you sure your solutions even correct? A formal proof is probably not necessary, but going through the process of trying to convince a somewhat sceptical [rubber duck](https://en.wikipedia.org/wiki/Rubber_duck_debugging) will help you think through the various details of your algorithm.

*   Correctness - Invariants

*   Invariants are rules that are always true. For prefix sums, the invariant is: ![prefix[i]=arr[1]+arr[2]+...+arr[i]](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=prefix[i]=arr[1]%2Barr[2]%2B\ldots%2Barr[i]). These allow you to make safe assumptions and figure out which conditions need to be satisfied. For example, a trivial [Rubik's Cube invariant](https://deepblue.lib.umich.edu/bitstream/handle/2027.42/143508/Online%20Appendix%202.pdf) is that each face has 9 coloured squares. If this invariant is satisfied after every move, you don't have a "malfunctioning" cube. 
*   Correct code is much easier to write if you know your invariants. This means you can work towards the solution more easily. Pick good ones and the code more or less writes itself. Bugs are much easier to spot if you have invariants to check your code against.

*   Reworking - Often the first solution you come up with won’t be the most elegant one.

*   Extra time thinking about the algorithm can help simplify implementation
*   Maybe there’s a way you can structure your algorithm to reduce the number of cases? Is one special case just a special case of another, more general special case?
*   If two cases are mirrors (or duals) of each other, can you implement them both with the same code?
*   Have you solved a more general problem than what you needed? Maybe the specific problem you’re solving has particular restrictions that simplify implementation?
*   Run through the algorithm in your head on a few interesting cases. This might help you spot cases that you’ve missed, or details you haven’t thought through fully.

*   Verify each line of code after you write it. This is probably the one time you’ll have the best understanding of that line of code, so this is when you should check it.
*   Good Style

*   Informatics code really only needs to work once, then you’re done. This means you often end up writing pretty hacky code (which is fine, gotta go fast after all). That being said, there are a few things that I’ve found useful:

*   Coherent variable names. Don’t give everything one letter names. The more places it gets used, the more descriptive the name should be.
*   Invariants! Put them in a comment to remind yourself.
*   Don’t repeat code! If you find yourself copy-pasting code, you’re gonna have a bad time. Instead, use functions.
*   Separate each algorithm into a function, don't write everything in main, this helps when debugging. I also find it is more readable and less overwhelming. 

*   Muscle memory & Conventions

*   Once you’ve done enough problems, you get kind of a feel for how your code should be. Your first few dynamic programming implementations are likely to be a bit all over the place, hopefully by your 10th, you’ll have worked out a consistent structure that makes sense to you. Same applies for basically every other area.
*   Be consistent in how you write your code. If you do, then mistakes and typos will stick out like a sore thumb - If you always write loops from 1 to N, then always do it that way. If your intervals are always inclusive exclusive, keep it that way. If your arrays always start at 1, keep it that way.

*   Subtasks

*   Most problems will have a subtask for small inputs. You can use this to test your code partway through writing it (_and you get free points_). For example, if a problem needs RMQ, first implement a naïve ![O(N)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(N)) loop over the array. If you solve a subtask with this, you know you have a correct solution. Note that this isn't completely fool proof  , in rare cases the test data is not thorough, or the smaller bounds on the subtask mean that certain edge cases don’t crop up.

*   Learn from others

*   Discuss your solution with other people who have solved the problem, especially what motivated their thoughts and solution. Maybe they have a more elegant solution than you did.
*   Once you’ve solved a problem, go and look at other people’s code. Is it simpler? You might learn some implementation tricks from them, or you might find an entirely different approach.

I’m getting incorrects! How do I debug my code?
-----------------------------------------------

*   Find a breaking case

*   It’s much much easier to debug if you have a case which shows your code produces the wrong answer, or crashes.
*   The main purpose of the Sample Cases is to make sure you understand the problem. This often means they are quite poor for actually testing a solution. Create your own instead.
*   Try to make different cases that test out all the parts of your program (test coverage) Try to ask yourself questions like:

*   Can I create a test case that will make this loop never run?
*   Can I create a test case that makes this branch of the if-statement run?
*   A test case where the start is the end? Where left = right in this part of the code? Where size = 0 in this part of the code?
*   A test case where the answer is 0? Where the answer is negative?
*   What are the bounds? Can ![N=0](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=N=0), or ![N=1](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=N=1), or something along those lines? It is true that ![INT_MIN < value < INT_MAX](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=INTMIN\le value\le INTMAX) for every value? 
*   Are you printing floating point numbers with enough precision?

*   Debugging:

*   Print debugging: Once you have a breaking case (or even in the dire situation when you _don’t_), stick in print statements to show the values of various variables throughout execution.

*   Your code is printing the wrong answer, so assuming your algorithm is correct, your code does something wrong _at some point_. By printing out the variables, you can pinpoint exactly where it starts to go wrong.

*   Interactive debugging: Using the step over, step in, step out and breakpoints to follow execution, you can follow the path of execution and find where something unexpected happens. This is built into every C++ IDE, or you can use gdb if you like being a leet Linux hanker.

*   Are you sure your algorithm is even correct?

*   Recheck your writings on paper.

*   Have you misread the problem?

*   Re-read the problem statement, check your understanding using the sample cases.

I’m getting timeouts! How do I make my code faster?
---------------------------------------------------

*   **Firstly, be sure that your algorithm is of the right time complexity**. No matter how hard you optimise, an ![O(N^2)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(N^2)) is not going to be fast enough for N = 100,000 

*   Rule of thumb: Take your time complexity and substitute in the maximum bounds given by the problem to get an estimate on the number of “operations” your program will perform.
*   For example if N = 1000, K = 1,000,000,000

*   an ![O(NK](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(NK)) solution will need about 1000\*1,000,000,000 = 1 trillion steps 
*   An O(N^2) solution will need about 1000\*1000 = 1 million steps

*   Judging platforms have around 100 million “operations” a second, as a rule of thumb.
*   Once you familiarise yourself with different types of informatics questions, you should know a [table similar to this](https://usaco.guide/bronze/time-comp?lang=cpp#common-complexities-and-constraints).

*   Common methods for optimisations

*   Often is it useful to look for computations which are repeated, or which can be simplified by some observation.
*   This may include sorting your data to begin with, or using segtrees to make an ![O(N)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(n)) operation into an ![O(logn)](https://chart.apis.google.com/chart?cht=tx&chf=bg,s,111111&chco=9ba2a8&chl=\mathcal O(\log n)) operation.

*   Input/Output optimisations (if you're using `cin` and `cout`):

*   Use [fastio](https://www.geeksforgeeks.org/fast-io-for-competitive-programming/) - `cin.tie(NULL); sync_with_stdio(false);`
*   Do not use `endl`, instead use `'\n'`

*   Remove debugging print statements

*   Micro Optimisations (only try this after you have tried everything else, because this should often be unnecessary)

*   Avoid using new & malloc, avoid declaring arrays and vectors inside functions, declare them globally.
*   Change the order of indices in a 2D array to decrease cache misses. For example, using `grid[col][row]` instead of `grid[row][col]`.
*   Early exit may help

I'm getting runtime errors! Its REally annoying!
------------------------------------------------

*   Undefined behaviour can cause seemingly correct code to crash/wrong answer when you submit

*   Recheck your array bounds, could you possibly be accessing outside the bounds of your array?
*   Are you making sure you initialise all your variables before you use them?
*   Compiling with `-Wall` (all warnings) can help catch some of these errors.

*   Also `-Wextra` and `-Wshadow`, and a host of others.

*   Use the same compilation command that the judge is using. Compilation commands can usually be found in the rules of the contest.

I don’t know what to do next! Where should I focus my training?
---------------------------------------------------------------

*   Get a handle on the basics first. As a quick checklist:

*   Graph theory: (DFS, BFS, Dijkstra, Kruskal's)
*   Data Structures: Do you understand the purpose and time complexities of std data structures? (e.g. vectors, sets, map, queues, priority\_queues) Optionally, are you able able to implement range trees? (point update range query, range update point query, range update range query, lazy propagation)
*   Dynamic Programming: Can you implement Knapsack and longest increasing subsequence?

*   Do more problems. I use [ORAC](https://orac2.info/hub/)

*   Have a look at the public sets, there are lots good problems there. Ask me for recommendations if you’re feeling lost :D

*   Practice sitting contests. I use [DMOJ](https://dmoj.ca/contests/)

*   You can find past contests for almost any contest.

*   Keep working up till the last second!

*   If you give up in the last ten minutes, that’s 5% of your contest time wasted (in a 3hr contest).
*   In a real contest, there is also a chance the contest will be extended, due to technical issues.

*   Keep calm

*   Contests are a marathon, make sure you keep your emotions in check. Thinking/coding/debugging while stressed or angry or frustrated will go poorly. If you notice you’re not feeling good, get up and go to the toilet/get a drink.
*   Drink plenty of water :)

*   Write good notes and references (this applies especially to ICPC)

*   If the contest allows you to bring in notes, make sure you write good notes. When training out-of-contest, use your notes so you get used to them.