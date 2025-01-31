---
title: 'When to use Induction?'
date: Tue, 30 May 2023 08:30:00 +0000
draft: false
tags: ['Induction', 'Mathematics', 'Proof Methods', 'Uncategorized']
author: 'George Kwong'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/picture4.png?w=1024'
---

How many regions are there if we pick $n$ points on a circle and connect the line segments between every pair of points?

<!--more-->

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/picture4.png?w=1024)

Modified from Wikimedia Commons (https://commons.wikimedia.org/wiki/File:Circle\_division\_by\_chords.svg)

You can see for $n = 1, 2, 3, 4$, we get $2^0, 2^1, 2^2, 2^3$. You may probably guess for the case of $n$, the number of regions is $2^{n-1}$. However, you can try to count the number of regions for $n = 6$, you have only 31 regions.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/image-3.png?w=743)

Cropped from Wikimedia Commons (https://commons.wikimedia.org/wiki/File:Circle\_division\_by\_chords.svg)

The actual answer is $\\displaystyle 1 + \\binom{n}{2} +\\binom{n}{4}$, where $\\binom{n}{r} $ is the binomial coefficient. The proof is out of the scope here. You can find more information on [Wikipedia](https://en.wikipedia.org/wiki/Dividing_a_circle_into_areas).

But you can see sometimes the pattern for small integers does not hold for larger numbers. You can try to show that the number of regions is $2^n$ by Mathematical Induction. But it will be stuck in the inductive step as the statement is not true. In other words, if you want to use induction, you know already the result is true.

Let's explore a simplified version of problem A4 in Putnam 2019.

Suppose a real-valued function $f(x)$ satisfies $\\displaystyle \\int\_a^{a + 1} f(x) \\mathrm{d}x = 0$ for all real $a$. Must $f(x) = 0$? Justify your answer.

Maybe you are hypnotised by the 1 and thinking $\\displaystyle \\int\_a^{a + 1} f(x) \\mathrm{d}x = 0$ implying $\\displaystyle \\int\_0^{\\infty} f(x) \\mathrm{d}x = \\int\_0^{1} f(x) \\mathrm{d}x + \\int\_1^{2} f(x) \\mathrm{d}x + \\int\_2^{3} f(x) \\mathrm{d}x + \\cdots = 0 + 0 + 0 + \\cdots = 0$. Then you hope it will give a zero constant function in the end. But even if the value obtained by integrating a function is zero, the function itself may not be zero. You are adding and subtracting areas to get zero, but the areas themselves may be non-zero. For example, if $h + k = 0$, $h$ can be $1$ and $k$ can be $-1$. They may not be zero.

But you may have the endurance to use Induction as you can see that for example, if you can show that $f(a) = f(a+1) $ for all real $a$ (i.e. the function is $a$-periodic.), then if you have a constant $c$ which $f(c) = 0$, you have hopes to show the function is indeed a zero-function. To extract a value for an input value from an integral, you may use the ideas from the Fundamental Theorem of Calculus or Mean-value Theorem. Here we can consider a small positive number $\\epsilon > 0$. As we have $\\displaystyle \\int\_a^{a + 1} f(x) \\mathrm{d}x = \\int\_{a + \\epsilon}^{a + 1 + \\epsilon} f(x) \\mathrm{d}x = 0$, so $\\displaystyle \\int\_{a + \\epsilon}^{a + 1 + \\epsilon} f(x) \\mathrm{d}x - \\int\_a^{a + 1} f(x) \\mathrm{d}x = \\int\_{a + 1}^{a + 1 + \\epsilon} f(x) \\mathrm{d}x - \\int\_{a}^{a + \\epsilon} f(x) \\mathrm{d}x$ is zero. (as the overlapped intervals cancel out). It means that $\\displaystyle \\int\_{a + 1}^{a + 1 + \\epsilon} f(x) \\mathrm{d}x = \\int\_{a}^{a + \\epsilon} f(x) \\mathrm{d}x$. Informally, we indeed get $f(a) = f(a+1)$. (You may try to show that by Mean-value Theorem.) However, can we find a constant $c$ which $f(c) = 0$?

Actually, you can do so by the intermediate value theorem, but the original statement is false and $f(x)$ can be a non-zero function. We can consider a counter-example $f(x) = \\sin (2\\pi x)$. It is clearly non-zero and you can show that $\\displaystyle \\int\_a^{a + 1} f(x) \\mathrm{d}x = 0$ for all real $a$. Here, I just want to convince you that Induction sometimes pulls you onto a wrong train of thought. We need to be careful when we intend to use induction.

Back to the question of when we can use Induction. In short, if you know the result is true, you may try to use Induction, but there may be a better way to do so.

For example, we want to show that $\\displaystyle \\sum\_{r = 1}^{n} r\\binom {n}{r} = 1\\binom {n}{1} + 2\\binom {n}{2} + 3\\binom {n}{3} + \\cdots + n\\binom {n}{n} = n 2^{n-1}$ for positive integers $n$. Induction works for this problem. You can try it by yourself. However, the solution is very tedious. The rough steps are:

1.  Show that $\\displaystyle \\binom {n}{r} + \\binom {n}{r + 1} = \\binom {n + 1}{r + 1}$.
2.  Show that $\\displaystyle \\sum\_{r = 1}^{n} \\binom {n}{r} = \\binom {n}{1} + \\binom {n}{2} + \\binom {n}{3} + \\cdots + \\binom {n}{n} = 2^{n} - 1$ by induction.
3.  Show that $\\displaystyle \\sum\_{r = 1}^{n} r\\binom {n}{r} = 1\\binom {n}{1} + 2\\binom {n}{2} + 3\\binom {n}{3} + \\cdots + n\\binom {n}{n} = n 2^{n-1}$ by induction.

Basically, you need to do two Inductions. But the solution is much shorter using a combinatorial argument. Consider the number of elements in the form of $(k, A\_r)$ where $r$ is an integer between 1 and n, inclusively and $A\_r$ is a subset of $\\{1, 2, 3, \\ldots, n\\}$ with exactly $r$ elements and $k \\in A\_r$. For the LHS, for a fixed $r$, we have $\\binom n r$ ways to choose the subset as we need exactly $r$ elements. Then for this subset, we have $r$ ways to choose which one is $k$. Summing up all possible combinations, we have $\\displaystyle \\sum\_{r = 1}^{n} r\\binom {n}{r}$. For the RHS, we can choose $k$ first, where we have $n$ choices from $k = 1, 2, 3, \\ldots, n$. Then we have 2 choices (in or out of the subset) for all remaining numbers, which gives $2^{n-1}$ choices. So you can see the proof of $\\displaystyle \\sum\_{r = 1}^{n} r\\binom {n}{r} = n 2^{n-1}$ in just a few lines.

Try the problems below to grasp the way to decide whether to use Induction or not.

**Problem 1(a)**

Find all continuous real-valued $f(x)$ such that $f(x) + f(y) = f(x+y)$ for all real $x,y$.

This question is a standard functional equation. You can Google the answer for details. It is Cauchy’s method for functional equations. You can try to solve it by yourself using the following steps.

1.  Put $x = y = 0$ to find the value of $f(0)$.
2.  Prove by induction that $f(n) = nf(1)$ for all positive integers $n$.
3.  Prove that $f(n) = nf(1)$ for all integers $n$ (by a substitution mentioned in the last blog). $n$ can be negative.
4.  Prove that $\\displaystyle f \\left( \\frac {n} {m} \\right) = \\frac {n} {m} f(1)$ for all integers $n, m$, where $m \\neq 0$ (by a substitution mentioned in the last blog).
5.  Using continuity, argue if $f(q) = qf(1)$ for rational $q$, then it is true that $f(r) = rf(1)$ for real $r$.
6.  Conclude $f(x) = cx$ for some real number $c$.

**Problem 1(b)**

Find all continuous real-valued $f(x)$ such that $f(x) + f(y) + 1 = f(x+y)$ for all real $x,y$.

Will you want to do all those steps again? No! Mathematics is about recycling previous results. We guess the answer is similar to the above, but how can we get rid of the 1? We can do a substitution $f(x) = g(x) - 1$. Then we have $g(x) - 1 + f(y) - 1 + 1 = g(x+y) - 1$, so $g(x) + g(y) = g(x+y)$. Therefore, $g(x) = cx$ and $f(x) = cx - 1$ for some real number $c$. The takeaway is Induction is useful, but you can try to employ other techniques too.

**Problem 2**

Find all real functions $f : \\mathbf{R}\\setminus\\{1\\} \\rightarrow \\mathbf{R}$ such that $\\displaystyle f(x^2) = \\frac {f(x)}{1+x}$ for all real $x \\neq 1$.

This is a good problem. I would like you to try. The hint is using $\\displaystyle f(x) = \\frac {g(x)} {1 - x}$ for $x \\neq \\pm 1$. If you cannot get it, I recommend this [YouTube video](https://youtu.be/lUmXJl01pKU).