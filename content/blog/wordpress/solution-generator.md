---
title: 'Solution Generator'
date: Wed, 26 Jul 2023 08:30:00 +0000
draft: false
tags: ['Generating Functions', 'Mathematics', 'Polynomials', 'Uncategorized']
author: 'George Kwong'
---

We start with our beloved binomial theorem again. Let's consider the expansion of $\\displaystyle (1+x)^n = \\sum\_{r=0}^n \\binom {n} {r} x^r$. But my question is that what is the sum of all binomial coefficients?

<!--more-->

If you have followed us for quite some time or have a solid mathematical background, you probably already know the answer hides behind the substitution $x = 1$. Then you get $\\displaystyle (1+1)^n = \\sum\_{r=0}^n \\binom {n} {r}$, so the answer is $2^n$. Why it works? You can say that putting $x = 1$ effectively eliminates all $x$es. However, if you see this problem the first time and I have not given you a hint, how can you realise the expansion of $(1+x)^n$ is useful?

In mathematics, a generating function is a powerful tool used to "summarise" patterns. Specifically, it provides a way to encode a sequence into a single (possibly polynomial) function, which can then be manipulated by Algebra or even Calculus.

A generating function is typically expressed as a power series, where each term corresponds to a term in a sequence. For example, if the sequence is $(a\_n)$ (i.e. $a\_0, a\_1, a\_2, \\ldots$), the power series would be $\\displaystyle \\sum\_{r=0}^{\\infty} a\_r x^r = a\_0 + a\_1 x + a\_2 x^2 + \\cdots$.

Generating functions are widely used in combinatorics, number theory, and other areas of mathematics. They can be used to solve recurrence relations, count objects, study asymptotic properties of sequences, and even prove theorems.

Overall, generating functions provide a robust and elegant framework for studying and manipulating sequences and sets of objects in mathematics.

Let's try the following exercise.

**Problem 1**

Consider the geometric series $\\displaystyle \\frac {1} {1 - x} = 1 + x + x^2 + x^3 + \\cdots = \\sum\_{r=0}^{\\infty} x^{r} $. Try to show that $\\displaystyle \\sum\_{r=0}^{\\infty} r x^{r} = \\frac {x}{(1-x)^2}$.

Here is a hint if you feel stuck.

Differentiation?

Here is another hint if you still feel stuck.

Differentiate both sides. You should have $\\displaystyle \\frac {1} {(1 - x)^2} = 0 + 1 + 2x^1 + 3x^2 + \\cdots = \\sum\_{r=0}^{\\infty} rx^{r-1} = \\sum\_{r=0}^{\\infty} (r+1)x^{r} $.

Having good intuition is vital for effectively using generating functions. Let's keep this rolling and go through the next example.

**Problem 2**

Consider the sequence that $a\_{n+2}=3a\_{n+1}-2 a\_n + 2n$ and $a\_0 = a\_1 = 0$. Find a closed form for $a\_n$.

Let $\\displaystyle f(x) = \\sum\_{r=0}^{\\infty} a\_r x^r$, which seems to be close enough to encode the sequence in a function.

Then $\\displaystyle f(x) = \\sum\_{r=0}^{\\infty} a\_r x^{r} = \\sum\_{r=2}^{\\infty} a\_{r} x^{r} = \\sum\_{r=0}^{\\infty} a\_{r+2} x^{r+2}$, which gives $\\displaystyle f(x) = \\sum\_{r=0}^{\\infty} (3a\_{r+1}-2 a\_r + 2r) x^{r+2} = 3x\\sum\_{r=0}^{\\infty} a\_{r+1}x^{r+1} - 2x^2 \\sum\_{r=0}^{\\infty} a\_{r}x^{r} + 2x^2 \\sum\_{r=0}^{\\infty} r x^{r}$. Using the result from the last example, we have $\\displaystyle f(x) = 3xf(x)- 2x^2 f(x) + \\frac {2x^3}{(1-x)^2}$. Rearranging and making $f(x)$ as the subject of the formula, we have $\\displaystyle f(x) = \\frac {2x^3}{(x - 1)^3 (2 x - 1)}$.

Then we can employ the [partial fraction](https://en.wikipedia.org/wiki/Partial_fraction_decomposition#Illustration) trick and have $\\displaystyle f(x) = \\frac {-2} {(1 - x)^3} + \\frac {2} {(1 - x)^2} + \\frac {-2} {1 - x} + \\frac {2} {1 - 2x}$.

We also know that (try to prove it using the trick from the previous example) $\\displaystyle \\frac {1} {1 - x} = \\sum\_{r=0}^{\\infty} x^{r} $, $\\displaystyle \\frac {1} {(1 - x)^2} = \\sum\_{r=0}^{\\infty} (r+1)x^{r} $ and $\\displaystyle \\frac {1} {(1 - x)^3} = \\sum\_{r=0}^{\\infty} \\frac {(r+1)(r+2)}{2}x^{r} $. Also, $\\displaystyle \\frac {1} {1 - 2x} = \\sum\_{r=0}^{\\infty} (2x)^{r} $. Then we have

$\\displaystyle \\begin{aligned} f(x) &= \\frac {-2} {(1 - x)^3} + \\frac {2} {(1 - x)^2} + \\frac {-2} {1 - x} + \\frac {2} {1 - 2x} \\\\ &= \\sum\_{r=0}^{\\infty} (-(r+1)(r+2) + 2(r+1) -2 +2 (2^r) )x^{r} \\\\ &= \\sum\_{r=0}^{\\infty} (2^{r+1} -r^2 - r - 2 )x^{r} \\end{aligned}$

So we have $a\_r = 2^{r+1} -r^2 - r - 2$.

**Problem 3**

Find the number of ways you can pay $30 using only $2, $5 and $10 coins without any changes.

We cannot get only 1 number of combinations from a generating function, so we try to get all the numbers of combinations for $ $n$, for any non-negative integers $n$. So we have a sequence of combinations for each $n$. Then we can use the technique from the last question.

Let $a\_n$ be the number of ways you can pay $ $n$ using only $2, $5 and $10 coins without any changes and $\\displaystyle f(x) = \\sum\_{r=0}^{\\infty} a\_r x^r$.

Now think of the degree of $x$ as the total amount of the coins, as if $a\_r$ is the combination, the $r$ must be the amount. Then we can see $f(x) = (1 + x^2 + x^4 + \\cdots)(1 + x^5 + x^{10} + \\cdots)(1 + x^{10} + x^{20} + \\cdots)$. Why? If we only use $2 coins, we have only 1 way to pay all even numbers of dollars. Similarly for $5 coins and $10 coins. The next step is to do a "multiplication" as we multiply the numbers of possible ways when counting.

Using the geometric series again, we have $\\displaystyle f(x) =\\frac {1} {(1-x^2)(1-x^5)(1-x^{10})}$. Now we are doing something crazy.

Write $\\displaystyle g(x) = \\frac 1 {(1 - x^{10})^3}$. It helps us to express $f(x)$ in a way so that we can use the [generalised binomial theorem](https://en.wikipedia.org/wiki/Binomial_theorem#Generalizations), or the power series $\\displaystyle \\frac {1} {(1 - x)^3} = \\sum\_{r=0}^{\\infty} \\frac {(r+1)(r+2)}{2}x^{r} $. Observe that

$\\displaystyle f(x) = g(x) (1 + x^2 + x^4 + x^6 + x^8) (1 + x^5)$.

Also, $(1 + x^2 + x^4 + x^6 + x^8) (1 + x^5) = 1 + x^2 + x^4 + x^5 + x^6 + x^8 + x^9 + x^{11} + x^{13}$ and $\\displaystyle g(x) = \\sum\_{r=0}^{\\infty} \\frac {-(r+1)(r+2)}{2}x^{10r} $. Observe that the only way to get $x^{30}$ in the multiplication of $g(x)$ and that long polynomial is to use $x^{30}$ in $g(x)$ and $1$ in the polynomial. Therefore, the number of ways required is $\\frac {(3+1)(3+2)} {2} = 10$. (You get 30 in $10r$ when $r = 3$).

**Problem 4** (Putnam 2000)

Let $S\_0$ be a finite set of positive integers. Define finite sets $S\_1,S\_2,\\ldots$ of positive integers as follows:

The integer $a$ is in $S\_{n+1}$ if and only if exactly one of $a-1$ or $a$ is in $S\_n$.

Show that there exist infinitely many integers $N$ for which $S\_N=S\_0\\cup \\{N+a: a\\in S\_0 \\}$.

You can try to do some toy examples, such as $S\_0 = \\{ 5, 10, 11\\}$. After few iterations, you should get the sense that $a$ is in $S\_{n+1}$ if and only if latex a-1$ [xor](https://en.wikipedia.org/wiki/XOR_gate) $a$ is in $S\_n$.

How to get an "XOR" in mathematics? The trick is to use mod 2. That is "odd + odd = even", "even + odd = odd", etc. Let $\\displaystyle f\_n(x) = \\sum\_{r \\in S\_n} x^r$ be the generating function. So for example, $f\_0(x) = x^5 + x^{10} + x^{11}$ for $S\_0 = \\{ 5, 10, 11\\}$. Then we can see that $f\_{n+1}(x) \\equiv (1+x)f\_{n}(x) \\pmod 2 $.

It is left as an exercise to show that $f\_{2^n}(x) \\equiv f\_{0}(x) \\pmod 2 $ for all $n$ that $2^n > \\max(S\_0)$. You can use induction.

**Problem 5** (From 102 Combinatorial Problems)

Find the number of subsets of ${1, 2, 3, 4, \\ldots, 2000}$ in which the sum of its elements is divisible by 5.

It is left as an exercise. You may watch this [video](https://youtu.be/bOXCLR3Wric) for reference, or using the following hints.

Hint 1.

For set $\\{1, 2\\}$, let $f(x) = (1 + x)(1+x^2) = x^0 + x^1 + x^2 + x^3$. So we know 1 subset each for sum equal to 0, 1, 2 and 3.

Hint 2.

$f(x) = (1 + x)(1+x^2)(1+x^3)\\cdots (1+x^{2000}) $.

Hint 3.

Example 2 in [this blog](https://unswcpmsoc.blog/2023/07/01/solve-real-problems-via-complex-routes/).

Hint 4.

Put $x = \\omega$, where $\\omega^5 = 1$ but $\\omega \\neq 1$.

Hint 5.

Such $\\omega$ makes $1 + a + a^2 + a^3 +a^4 = 0$ for $a = \\omega, \\omega^2, \\omega^3, \\omega^4$, but not $a = 1, \\omega^5, \\omega^{10}, \\ldots$