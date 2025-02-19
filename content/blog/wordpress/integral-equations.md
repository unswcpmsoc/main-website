---
title: 'Integral equations'
author: 'Your mother'
date: Mon, 13 Nov 2023 07:00:00 +0000
draft: false
tags: ['Diophantine Equations', 'Mathematics', 'Number Theory', 'Uncategorized']
author: 'George Kwong'
---

<!--more-->

Calculus is not a very popular topic (at least if we talk about the techniques) in Competition Mathematics. Therefore, solving a differential equation is a topic closer to solving a functional equation in Competition. Today, we are talking about [Diophantine equations](https://en.wikipedia.org/wiki/Diophantine_equation).

So it is clickbait again.😏Integral Integers. But first, please go through the [last post](https://unswcpmsoc.blog/?p=783) first.

In the last blog, we discussed how to solve the following equations for integers. Usually, due to historical reasons, we call them Diophantine equations.

*   $63x + 91y = 7$
*   $x^2 + 2y^2 = 5z^2$

We already know the second equation has no non-trivial integral solutions. That is the only possible solution is $x = y = z = 0$.

How about the first one? On a side note from the [last post](https://unswcpmsoc.blog/?p=783), we mentioned [the extended Euclidean algorithm](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example) with a [reference page](https://brilliant.org/wiki/bezouts-identity/). We know that first, we can divide both sides by the greatest common divisor, and then we have $9x + 13y = 1$. Then by using the extended Euclidean algorithm (or you can do a trial and error, it works well for small numbers), we know one possible solution is $x = 3, y = -2$. How can we use this particular solution to produce the general solution?

The process is similar to the case of solving $tan x = 1$. As we know $x = \\frac {\\pi} 4$ (or 45 degrees) and the period of the tangent function is $\\pi$ (or 180 degrees), the general solution is $x = \\pi n + \\frac {\\pi} 4$ for integers $n$.

Now, as we have $x = 3, y = -2$, to add something to $x$ so that the 13 is possible to deal with, we add 13 to $x$. Then we can minus 9 from $y$ to balance it out. As 9 and 13 are coprime, these 9 and 13 additions/subtractions are the smallest "move" so that it still gives a valid solution. So we have $x = 3 + 13m, y = -2 - 9n$ for integers $m,n$.

This is a standard technique for solving linear Diophantine equations. It is also able to solve [linear congruence equations](https://mathworld.wolfram.com/LinearCongruenceEquation.html). For example, if we want to know the solution to $23x \\equiv 20 \\pmod{100}$, we can rewrite the equation to $23x + 100y = 20$. (It is because $23x \\equiv 20 \\pmod{100}$ means $23x$ has a remainder of 20 when it is divided by 100. Then we can write $23x = 100(-y) + 20$ by the [division theorem](https://unswcpmsoc.blog/?p=787).) Using the extended Euclidean algorithm, we have $x = 40$. Hence, $x \\equiv 40 \\pmod{100}$. (Why the general solution is not very helpful here? Try to find the general solution and see why the result holds without the general solution.)

So we know the solution is all $x$ with the remainder 40 when it is divided by 100. As a side note, can you find the smallest positive integer $N$ such that $23N$ ends with 20 as the last 2 digits?

Solution

We can clearly see $23N \\equiv 20 \\pmod{100}$, so $N \\equiv 40 \\pmod{100}$. The smallest $N$ is 40.

Now we try to solve another Diophantine equation $x^2 - y^3 = x$.

Usually, this kind of question has only a very few solutions. You can find all of them by trial and error, and then prove there are no other solutions.

First, we rearrange the term and get $(x-1)x = y^3$. It is clear that $(x-1)$ and $x$ are coprime. (Why? It is because of the [Euclidean algorithm](https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclidean_algorithm) again!) Then using the [Fundamental Theorem of Arithmetic](https://unswcpmsoc.blog/?p=787), write $y = p\_1p\_2\\cdots p\_r$. Then $(x-1)x = y^3 = p\_1^3p\_2^3\\cdots p\_r^3$. Due to their coprime-ness (using [Euclid's lemma](https://unswcpmsoc.blog/?p=787)), each of $p\_i^3$ can only distribute to either $x-1$ or $x$. That is we cannot have something like $x-1$ has the factor $p\_i$, but with $x$ has the factor $p\_i^2$.

Then both $x$ and $x-1$ are perfect cubes. Is it possible? Kind of impossible. As we know the difference between two consecutive cubes is $(k+1)^3 - k^3 = 3k^2 + 3k + 1 = 3(k + \\frac {1} {2})^2 + \\frac {1} {4}$. Such difference is smallest when $k = 0, -1$ as we have the term $(k + \\frac {1} {2})$. Otherwise, for $k > 0$ or $k <-1$, $3(k + \\frac {1} {2})^2 + \\frac {1} {4} \\geq 3(\\frac {3} {2})^2 + \\frac {1} {4} = 7 > 1$. So the only possible pairs of perfect cubes $(x-1, x)$ are $(0, 1)$ and $(-1, 0)$. Hence, $(x,y) = (0, 0), (1, 0)$.

Now let's try to solve Problem A5 in Putnam 2001.

Find all solutions to $x^{n+1} - (x+1)^{n} = 2001$ for positive integers $x,n$.

Hint 1

Take mod $x$.

Hint 2

We have $0 - 1 \\equiv 2001 \\pmod {x} \\Leftrightarrow 2002 \\equiv 0 \\pmod {x}$.

Hint 3

2002 is divisible by $x$.

Hint 4

$2002 = (2)(7)(11)(13)$.

Hint 5

$x = 1, 2, 7, 11, 13, 14, 22, 26, 77, 91, 143, 154, 182, 286, 1001, 2002$.

Hint 6

Take mod $x + 1$.

Hint 7

Similar to the above argument, 2002 is divisible by $(x + 1)$ if $n$ is even and 2000 is divisible by $(x + 1)$ if $n$ is odd. But taking mod 3 to the original equation, ...

Hint 8

Taking mod 3 to the original equation, as $x$ is not a multiple of 3, $x \\equiv 1, 2 \\pmod {3}$.

Hint 9

For $x \\equiv 1 \\pmod {3}$, $(1)^{n+1} - (2)^{n} \\equiv 2001 \\pmod {3}$ gives $1 - (-1)^{n} \\equiv 0 \\pmod {3}$. So $n$ is even.

Hint 10

If $x \\equiv 2 \\pmod {3}$, $(2)^{n+1} - (0)^{n} \\equiv 0 \\pmod {3}$ which is impossible. For $n$ is even, similar to the above argument, $x + 1 = 1, 2, 7, 11, 13, 14, 22, 26, 77, 91, 143, 154, 182, 286, 1001, 2002$.

Hint 11

For $n$ is even, similar to the above argument, $x + 1 = 1, 2, 7, 11, 13, 14, 22, 26, 77, 91, 143, 154, 182, 286, 1001, 2002$.

Hint 12

$x = 1 $ or $x = 13$.

Hint 13

$x = 1 $ is impossible as $1^{n+1} - 2^{n} \\leq 0$.

Hint 14

Take mod 8 to $13^{n+1} - 14^{n} = 2001$.

Hint 15

For even $n \\geq 4$, $5^{n+1} - 0 \\equiv 1 \\pmod {8}$. But $5^{n+1} \\equiv 5 \\pmod {8}$.

Hint 16

So $n = 2$, $x = 13$.

To end the topic, you may explore more how 1 particular solution for $x^2 + y^2 = z^2$, namely $(x,y,z) = (1,0,1)$, can extend to the general solutions of [Pythagorean triples](https://en.wikipedia.org/wiki/Pythagorean_triple#Rational_points_on_a_unit_circle) and how to even ["find" a particular "solution"](https://youtu.be/tRaq4aYPzCc) of $x^2 + x^4 + x^8 = y^2$ in the first place.