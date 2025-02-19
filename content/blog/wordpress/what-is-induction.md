---
title: 'What is Induction?'
date: Tue, 21 Mar 2023 06:09:53 +0000
draft: false
tags: ['Induction', 'Mathematics', 'Proof Methods', 'Uncategorized']
author: 'George Kwong'
image: https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/early_induction_hob_cooker_rankin_kennedy_electrical_installations_vol_ii_1909-2.jpg?w=359'
---

First of all, we are talking about Mathematics. Not Induction in Physics and Logic, although the latter is related to Mathematical Induction to some extent.

<!--more-->

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/early_induction_hob_cooker_rankin_kennedy_electrical_installations_vol_ii_1909-2.jpg?w=359)

Induction Cooker _From Wikimedia Commons_ [link](https://upload.wikimedia.org/wikipedia/commons/6/68/Early\_induction\_hob\_cooker\_%28Rankin\_Kennedy%2C\_Electrical\_Installations%2C\_Vol\_II%2C\_1909%29.jpg)

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/what_is_the_unifomity_of_nature-2.png?w=561)

Uniformity of nature and Induction _From Wikimedia Commons_ [link](https://commons.wikimedia.org/wiki/File:What_is_the_Unifomity_of_nature.png)

So what is Mathematical Induction? Induction here means to argue the proposition for a small case and then reuse it for a more complex case. To be precise an "Induction" proof must be done in a specific format. But in a very vague sense, you are proving by using simple cases inductively (in literal meaning) to argue the final goal statement. Let's explore the example below.

> Consider a ${2 \times 2}$ chessboard and an L-shaped domino. How can you place some dominos onto the chessboard so that there is 1 specific uncovered cell (i.e. others fix one random cell which you cannot cover it)?

It is trivial as you can place the domino in whatever position and it automatically leaves only 1 empty cell.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/picture1-1.png?w=1024)

Then how about a ${4 \\times 4}$ chessboard? Can you place some dominos onto the chessboard so that there is only 1 uncovered cell too? You can try to do this in your own way. But here we want to do it in a more systematic way so that we can "reuse" the logic in the latter part. We can divide the board into 4 equal parts, that is 4 ${2 \\times 2}$ boards. As we know whenever we have a ${2 \\times 2}$ chessboard with 1 specific empty cell, we can still cover the remaining 3 cells with an L-shaped domino. Therefore, we can cover the middle with an L-shaped domino, then we have 3 ${2 \\times 2}$ chessboards with 1 blocked cell near the centre (blue crosses) and 1 ${2 \\times 2}$ chessboard with 1 preassigned empty cell (red cross).

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/picture2.png?w=1024)

Then how about a ${2^n \\times 2^n}$ chessboard? We can reuse the logic as above. If we can do so for a ${2^{n-1} \\times 2^{n-1}}$ chessboard, then for a ${2^n \\times 2^n}$ chessboard, we can divide the board into 4 ${2^{n-1} \\times 2^{n-1}}$ chessboards. Then we cover the centre with an L-shaped domino. It leaves us 3 ${2^{n-1} \\times 2^{n-1}}$ chessboards with 1 blocked cell near the centre and 1 ${2^{n-1} \\times 2^{n-1}}$ chessboard with 1 preassigned blocked cell, which all of them can be covered by some combinations of L-shaped dominos, as we can do it for any ${2^{n-1} \\times 2^{n-1}}$ board as we assumed.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/picture3.png?w=589)

Adopted from Proof Without Words II (Roger B. Nelsen)

So why the proof is already complete? It is because we have proved for the case of ${n = 1}$ (i.e. a ${2 \\times 2}$ chessboard), then by above, as whenever we can cover any ${2^{k-1} \\times 2^{k-1}}$ chessboard with 1 specific empty cell (i.e. the case for ${n = k - 1}$), we can cover a ${2^k \\times 2^k}$ chessboard with 1 specific empty cell (i.e. the case for ${n = k}$).

In other words, if we have the case for ${n = k} $, then we know the case for ${n = k + 1}$ is also true.

Therefore, we can do it for the case of ${n = 1 + 1 = 2}$, and hence the case of ${n = 3}$, and so on for ${n = 4, 5, 6, \\ldots}$.

Hopefully, you can see this method is powerful to prove any statements related to positive integers. Formally, the principle of Mathematical Induction is as follows.

A statement is true for all positive integers ${n}$ if

1.  that statement is true for ${n = 1}$ (base case) and,
2.  assuming that statement is true for ${n = k}$, then that statement is true for ${n = k + 1}$ (inductive step).

It is often described as the domino effect. To use only the base case and then repeat the inductive step, the statement is shown to be true for ${n = 1, 2, 3, \\ldots}$ and so on.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/induction_domino_effect.jpg?w=1024)

Induction Domino Effect _From Wikimedia Commons_ (https://upload.wikimedia.org/wikipedia/commons/2/29/Induction\_domino\_effect.jpg)

The standard example of using such a principle is to show $\\displaystyle \\sum\_{r = 1}^{n} r^2 = 1^2 + 2^2 + 3^2 + \\cdots + n^2 = \\frac {n(n+1)(2n+1)} 6$ for all positive integers ${n}$. If you are new to induction, you can try to follow the following steps.

1.  Show the statement is true for ${n = 1}$ (base case):  
    Verify $\\displaystyle 1^2 = \\frac {1(1+1)(2+1)} 6$
2.  Assuming that statement is true for ${n = k}$, Show that the statement is true for ${n = k + 1}$ (inductive step):  
    It is given $\\displaystyle 1^2 + 2^2 + 3^2 + \\cdots + k^2 = \\frac {k(k+1)(2k+1)} 6$. If we add $(k+1)^2 $ onto both sides, can we verify $\\displaystyle 1^2 + 2^2 + 3^2 + \\cdots + (k+1)^2 = \\frac {(k+1)(k+2)(2k+3)} 6$?

It is too standard that you can even Google the answer directly. But it is always good to try it yourself first.

Although Mathematical Induction often associates with natural numbers, you can use it for negative numbers (by replacing ${x}$ by ${-x}$) or even rational numbers in some cases (by using the base case ${x = \\frac 1 q}$ and the inductive step from ${x = \\frac k q}$ to ${x = \\frac {k+1}q}$).

There are also different versions of Mathematical Induction, such as "Strong Induction" and "Backward Induction". You can search these terms for more information.

It is very useful when you want to argue statements with discrete variables in Mathematics as well as Competitive Mathematics. Let's do 2 examples.

**Problem 1**

```
Find a function $f : \mathbf{N} \rightarrow \mathbf{N}$ which $f(n) = 2f(n-1)^2 - 1$ with  $f(1) = \sqrt 5$. 
```

(Note that $\\mathbf{N}$ represents the set of all natural numbers. For the context here, we assume it means all positive numbers.)

To use induction to prove a formula, we need to first guess a plausible formula for $f(n)$. For a valid formula, it must be able to produce a $+1$ after the squaring (and then multiplying by 2). One of such expression may be $c + \\frac 1 c$, which you may recognise similar technique in a question like "Find the value of $x^2 + \\frac 1 {x^2}$ if $x + \\frac 1 x = 2023$".

However, $\\displaystyle \\left( c + \\frac 1 c \\right)^2 = c^2 + 2 +\\frac 1 {c^2}$. To transform $+2$ to $+1$, we use $\\displaystyle g(c) = \\frac c 2 + \\frac 1 {2c}$ and get $\\displaystyle 2\\left( g(c) \\right)^2 - 1 = \\frac {c^2} 2 + \\frac 1 {2c^2} = g(c^2)$.

Now, to make the form $g(d)$ become $f(n)$ and $g(d^2)$ become $f(n+1)$, we employ the exponential function, namely substituting $f(n) = g(c^{2^n})$, we indeed get $f(n+1) = g\\left(c^{2^{n+1}}\\right) = g\\left( \\left( c^{2^n}\\right)^2\\right)$ with $d = c^{2^{n}}$.

To find $c$, by $f(1) = \\sqrt 5$, we need $\\displaystyle \\sqrt 5 = f(1) = g(c^{2^1}) = \\frac {c^2} 2 + \\frac 1 {2c^2}$. By solving, we get $c^2 = 2 + \\sqrt 5$. Hence, $\\displaystyle f(n) = g(c^{2^n}) = g((c^2)^{2^{n-1}}) = g((2 + \\sqrt 5)^{2^{n-1}})$.

Finally, we get $\\displaystyle f(n) = \\frac {(2 + \\sqrt 5)^{2^{n-1}}} 2 + \\frac 1 {2(2 + \\sqrt 5)^{2^{n-1}}}$.

You may wonder what is the role of Induction here. The answer is simple, after getting the formula, as we just guess the answer, we must show that the expression is really valid for the condition. Induction is the formal way to go, which is left as an exercise for readers.

**Problem 2** (Source: https://math.stackexchange.com/questions/850377/for-every-positive-number-n-there-exists-a-n-digit-number-having-all-odd-di)

> Prove that for every positive integer $n$, there exists an $n$-digit number which is divisible by $5^n$ and all digits are odd.

You can try it for some small numbers. You should get $5, 75, 375, 9375, \\ldots$, which all you need to get the next number is to add an extra digit in front of the previous number.

It is a strong signal that we can really use induction here. For $n = 1$, it is trivial as the number 5 is an (only) example. Now assume the statement is true for $n = k$, where $k$ is a positive integer. Namely, we have a $k$-digit number $a5^k$ where all digits are odd. To add an extra digit, we add $b (10^k)$, where $b$ = 1, 3, 5, 7 or 9. (Note: This is the $(k+1)$th digit, not $k$th) We want $b$ to make the number divisible $5^{k+1}$.

Therefore, we have $5^{k+1} | \\left( b (10^{k}) + a5^k\\right) =5^k \\left( b (2^k) + a\\right)$. As 5 is a prime, we have $5 | \\left( b (2^k) + a\\right)$. It is the same as solving the linear congruence equation in mod 5, $c b \\equiv d$ for known numbers of $c \\equiv 2^k, d \\equiv -a$. We know that such odd $b$ always exists by the Bézout's identity.

We have seen some examples showing that time Induction is useful. But do not abuse it. We will see why in a future blog.