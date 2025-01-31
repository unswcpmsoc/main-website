---
title: 'Last but not least'
date: Mon, 16 Oct 2023 07:00:00 +0000
draft: false
tags: ['Infinite Descent', 'Mathematics', 'Number Theory', 'Proof Methods', 'Uncategorized']
author: 'George Kwong'
---

Suppose you have a balance scale with an infinite supply of 63 gram and 91 gram weights. What amount of mass can you measure? <!--more--> Let $M$ grams be the mass of the object you want to measure. To do this, you need to have $63 p + 91q + M = 63 r + 91s$ to balance both sides, where $p,q,r,s$ are numbers of weights. It implies we must have $63x +91y = M$ for some integers $x,y$. So what is the set $\\{63x + 91y \mid x,y \\in \\mathbb{Z}\\}$?

Clearly, $63x + 91y = 7 (9x + 13y)$, so the set must only contain multiples of 7. But does it include all multiples of 7? You must try to find all of them. Here, we introduce a fact from Number Theory - [Bézout's identity](https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity#:~:text=In%20mathematics%2C%20B%C3%A9zout's%20identity%20(also,that%20ax%20%2B%20by%20%3D%20d.)). This fact is simple but powerful.

Bézout's identity states that for all non-zero integers $a, b$ with $\\gcd (a,b) = d$, there exist integers $x,y $ such that $ax + by = d$. Moreover, $\\{ax + by \mid x,y \\in \\mathbb{Z}\\} = \\{dz \mid z \\in \\mathbb{Z}\\}$.

The proof involves a technique of using Infinite Descent.

Without loss of generality, we assume $a,b > 0$. Consider positive integers $a, b$ with $\\gcd (a,b) = d$. Now, as we know $a(1) + b(1) = a + b > 0$, the set $\\{ax + by \mid x,y \\in \\mathbb{Z}\\}$ must contain some positive integers. Assume the least of such positive integer is $e$. Applying the [division theorem](https://unswcpmsoc.blog/2023/09/11/naive-number-theory/) on $a$ using the divisor $e$, we have $a = eq + r$, with integers $q,r $ and $0 \\leq r < e$. However, $r = a - eq = a - (ax + by)q = (1 - xq)a - (qy)b$. So we construct a smaller non-negative integer $r$ with some integer $x',y'$ that makes $ax' + by' = r$. But we already assume $e$ is the smallest of such integers, which leads to $r = 0$. Then $a = eq + 0 = eq$, so $a$ is divisible by $e$. Similarly, we can show that $b$ is divisible by $e$. Thus, $e$ is a common divisor of $a,b$. So $d$ is divisible by $e$.

However, following a similar process of $63x + 91y = 7 (9x + 13y)$, we can see $ax + by$ must be divisible by the greatest common divisor $d$ of $a,b$. So $e$ is divisible by $d$. But $d$ is also divisible by $e$, so $d = e$.

Once we get $ax + by = d$, we can have $akx + bky = dk$. Therefore, indeed $\\{ax + by \mid x,y \\in \\mathbb{Z}\\} = \\{dz \mid z \\in \\mathbb{Z}\\}$.

_Note: But how to find such integers $x,y$ so that $ax + by = d$? You need to use [the extended Euclidean algorithm](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example). You can also look at [this page](https://brilliant.org/wiki/bezouts-identity/)._

You can see the usefulness of Proof by Infinite Descent. It is a trick to tackle Number Theory problems. Let's try to view two classic Number Theory problems through the lens of Infinite Descent.

**Problem 1**

Prove that there are infinitely many primes.

Following the essence of the Infinite Descent, we use infinite "ascent" here. First, assume $P$ is the maximum prime. There are only finitely many integers between $2$ and $P$, so there are only finitely many primes. Write all such primes as $p\_1, p\_2, p\_3, \\ldots, p\_n = P$.

But if we consider $M = p\_1p\_2p\_3\\cdots p\_n + 1$, we can see when we try to divide $M$ by all primes $p\_i$, the remainder is always 1. It means there is no prime dividing $M$. Therefore, $M$ is also a prime. So the assumption of having the largest prime is wrong. Thus, we have infinitely many primes.

**Problem 2**

Solve $x^2 + 2y^2 = 5z^2$ for integers $x,y,z$.

First, you may try to find a solution, but you cannot find any but $x=y=z=0$. So we try to prove it by an infinite descent.

Suppose we have some integral solution for $x^2 + 2y^2 = 5z^2$. Consider module 5 (i.e. using the [division theorem](https://unswcpmsoc.blog/2023/09/11/naive-number-theory/) with divisor 5), the RHS is divisible by 5. However, using the division theorem, we know $x \\equiv 0,1, 2, 3, 4 \\pmod{5}$. Then $x^2 \\equiv 0, 1, 4, 4, 1 \\pmod{5}$. Similarly, $y^2 \\equiv 0, 1, 4, 4, 1 \\pmod{5}$. You can try all possible cases, but in the end, you see $x^2 + 2y^2 \\equiv 0 \\pmod{5}$ (as the RHS forces the LHS to) only if $x \\equiv y \\equiv 0 \\pmod{5}$.

Then we can write $x = 5X, y = 5Y$ and have $25X^2 + 50Y^2 = 5z^2 \\Leftrightarrow 5X^2 + 10Y^2 = z^2$. The LHS is divisible by 5, and so is the RHS. Thus, $z$ can only be divisible by 5. But then all $x,y,z$ are divisible by 5. Write $x = 5X, y = 5Y, z= 5Z$ and have $25X^2 + 50Y^2 = 125z^2 \\Leftrightarrow X^2 + 2Y^2 = 5z^2$. Following a similar argument, $X, Y, Z$ are all divisible by 5. You find out $x,y,z$ are "infinitely" divisible by 5. The only such number is 0.

**Problem 3 (Putnam 1973)**

Let $a\_1, a\_2, \\ldots, a\_{2n+1}$ be a set of integers such that, if any one of them is removed, the remaining ones can be divided into two sets of $n$ integers with equal sums. Prove $a\_1= a\_2= \\cdots = a\_{2n+1}$.

Hint 0

Without loss of generality, we subtract all numbers by their minimum.

Hint 1

The parity of the sum of any $2n$ number is ...

Hint 2

As if any one of them is removed, the remaining ones can be divided into two sets of $n$ integers with equal sums, half of the sum of any $2n$ number is an integer. So the sum of any $2n$ number is even. So all numbers are ...

Hint 3

So all numbers are even.

Hint 4

But if we divide all numbers by 2, we get the set of integers $a'\_1, a'\_2, \\ldots, a'\_{2n+1}$ with the same property.

Hint 5

So all numbers are divisible by 2 again.

Hint 6

So all numbers $a\_1, a\_2, \\ldots, a\_{2n+1}$ are divisible by $2^n$ for all positive integers $n$.

Hint 7

So $a\_1= a\_2= \\cdots= a\_{2n+1}=0$. Adding the minimum back, the result follows.

Infinite Descent is an absurd tool. Last but not least, a similar technique [Vieta Jumping](https://en.wikipedia.org/wiki/Vieta_jumping) is also worthwhile to be understood for Competition Mathematics. It helps to tackle a famous IMO 1988 problem.

> Let $a$ and $b$ be positive integers such that $ab + 1 $ divides $a^2 + b^2 $.
> 
> Show that $\\frac {a^2 + b^2 }{ab+ 1}$ is the square of an integer.

But how to do it? It is again left to readers as an exercise.