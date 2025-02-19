---
title: 'Search the Constant'
date: Mon, 18 Sep 2023 05:10:37 +0000
draft: false
tags: ['Invariant', 'Mathematics', 'Problem Solving', 'Proof Methods', 'Uncategorized']
author: 'George Kwong'
---

Spotting a pattern is the key to problem-solving. Have you heard of [Seven Bridges of Königsberg](https://en.wikipedia.org/wiki/Seven_Bridges_of_K%C3%B6nigsberg)? <!--more--> It is a problem of finding a path so that we can cross each of the 7 bridges once and only once. Euler found that when you walk onto an island, you need to leave the island by another bridge to continue the path, except for the start and the end. It means that each of the islands must be connected by an even number of bridges, so the problem is impossible.

The number of bridges is the same as the [degree](https://en.wikipedia.org/wiki/Degree_(graph_theory)) of a graph. This number is an example of an invariant.

You can think of an invariant as a way of using another simpler mathematical object, usually numbers, to represent the problem, while keeping the main characteristics of the problem. Let's do the classic chessboard example.

Consider an $8 \\times 8$ chessboard with two opposite corners removed. Is it possible to cover the remaining board with only $2 \\times 1$ non-overlapping tiles?

It seems that you can do so as $62 = 31 (2)$. However, no matter how you try to tile it, you still cannot cover the board completely. How can we construct an invariant to prove the impossibility?

We can label each cell on the board with alternating As and Bs. Namely, the first row is ABABABAB, the second row is BABABABA and the third row is ABABABAB, etc. Then it is obvious that each $2 \\times 1$ tile must cover an A and a B. However, as the two removed opposite corners must be both labelled as either A or B, we have 32 As and 30 Bs (or reverse) only. We cannot cover 31 As and 31 Bs at the same time. Therefore, such tiling is impossible.

Now consider a $2^n \\times 2^n$ chessboard with the $(2^{n-1})$th cell (counting from the left) of the first row removed. Can we tile the board with only $3 \\times 1$ non-overlapping tiles?

Note that the number of remaining cells is $2^{2n} - 1 = 4^n - 1 \\equiv 1^n - 1 \\equiv 0 \\pmod{3}$. So we cannot disprove it by divisibility. However, we can still construct an invariant by abel each cell on the board with alternating As, Bs and Cs. The first row is ABCABC... If the last cell is A, then the second row is BCABCA...; If the last cell is B, then the second row is CABCAB... You can continue the pattern to label the whole board. There are 1 more As than Bs and Cs. We want to have the removed square labelled as B or C so that we have uneven As, Bs and Cs. Then we can follow the same argument as above. For an even $n = 2k$, $2^{n - 1} \\equiv (-1)^{2k + 1} \\equiv (1^k)(-1) \\equiv -1 \\equiv 2\\pmod{3}$, which corresponds to a B. However, for an odd $n$, we only have $2^{n - 1} \\equiv 1 \\pmod{3}$, which corresponds to an A. What can we do?

We can reflect the label on the board (i.e. going from the right to the left) so that the removed square is labelled as B. Hence, the result follows.

Now let's do some exercises.

**Problem 1**

Consider a row of 2023 face-down cards. You can only turn over any face-down card but turn over the immediate right card of your chosen card at the same time. If it is the rightest card, you do not need to turn over another card. You may do this action as long as your chosen card is face-down. Prove that the sequence of actions must terminate.

Hint 1

Label face-down cards as 1s and face-up cards as 0s.

Hint 2

Now the sequence of cards becomes a binary number. For the only available action, ...

Hint 3

the corresponding part of the binary number can only change in the following ways:

Hint 4

*   $11 \\rightarrow 00$,
*   $10 \\rightarrow 01$,
*   $1 \\rightarrow 0$.

Hint 5

All of them decrease the binary number.

Hint 6

As the binary number is finite, the maximum number of steps is finite. Thus, the sequence of actions must terminate.

Hint 7

See the following [video](https://youtu.be/mYAahN1G8Y8).

**Problem 2**

Consider the quadratic $x^2 - 9x + 20$. Each time, you may either:

*   Swap the constant term and the coefficient of $x^2$
*   Replace all $x$ by either $x-1$ or $x+1$ and simplify it.

Is there a sequence of steps to create the quadratic $x^2 + 4x + 2$?

Hint 1

Consider the roots of the quadratics.

Hint 2

$x^2 - 9x + 20 = 0$ has roots $4, 5$.  
$x^2 +4x + 2 = 0$ has roots $-2 \\pm \\sqrt{2}$.  
The actions makes the roots $\\alpha, \\beta$ become:

Hint 3

Swapping the constant term and the coefficient of $x^2$ makes $\\alpha, \\beta$ become $\\frac {1} {\\alpha}, \\frac {1} {\\beta}$.  
Replacing all $x$ by $x \\pm 1$ makes $\\alpha, \\beta$ become $\\alpha \\mp 1, \\beta\\mp 1$.

Hint 4

All actions keep rational roots as rationals.

Hint 5

But $4, 5$ are rational and $-2 \\pm \\sqrt{2}$ are not. So it is impossible.