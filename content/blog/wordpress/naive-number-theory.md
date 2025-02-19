---
title: 'Naive Number Theory'
date: Sun, 10 Sep 2023 23:00:00 +0000
draft: false
tags: ['Mathematics', 'Number Theory', 'O-Week', 'Uncategorized']
author: 'George Kwong'
summary: 'Number Theory is a field of mathematics concerning integers in general.'
---

_Disclaimer: This post aims to give a very naive and basic overview of Number Theory. Some statements in this post are not entirely rigorous. Please read a standard introductory Number Theory textbook at the undergraduate level to get a solid understanding of this area._ _For example, Euclid's lemma implies the Fundamental Theorem of Arithmetic, not the other way around. Here, we introduce the latter first only due to intuition._

Number Theory is a field of mathematics concerning integers in general. Although technically it also includes rational numbers (or fractions) or even irrational numbers (see [Algebraic Number Theory](https://en.wikipedia.org/wiki/Algebraic_number_theory#Failure_of_unique_factorization) and [Unique factorization domain](https://en.wikipedia.org/wiki/Unique_factorization_domain)), it is more than enough for most of Competition Mathematics.

In most competitions, there is an unwritten rule that you cite any known results (preferably with their names) without proof and do not need to worry about circular argument if you only do this for deriving a weaker result from a strong theorem. So we introduce the theorem in the order for an easy memorisation.

**[Division Theorem](https://en.wikipedia.org/wiki/Division_algorithm)**

When $n$ is divided by $d$, you can find a unique pair of integers $(q,r)$ such that $n = dq + r$, where $0 \\leq r < d$.

It means the procedure of long division you learnt in primary school always teminates no matter what are the dividend and divisor.

When the remainder is zero, we say $d$ divides $n$, or $n$ is divisible by $d$.

The consequence is all integers can be grouped into groups, no matter what divisor you choose. For example, we can group all integers as odd or even; or as remainders 0, 1 or 2 when divided by 3. It makes the [congruence](https://mathworld.wolfram.com/Congruence.html) of integers useful.

**[Primes](https://en.wikipedia.org/wiki/Prime_number)**

For positive integers at least 2, it is a prime if it is not a product of 2 other positive integers. Otherwise, it is composite.

Note that 1 is a unit, not a prime nor a composite.

In other words, a primes is a number with exactly 2 positive factors.

**[Fundamental Theorem of Arithmetic](https://en.wikipedia.org/wiki/Fundamental_theorem_of_arithmetic)**

The theorem states that for any positive integers at least 2, there is a prime factoriation of the number. Such factorisation is unique when the primes are in ascending order.

For example, $100 = 2 \\times 2 \\times 5 \\times 5$. Of course you also write $100 = 5 \\times 2 \\times 2 \\times 5$, but you cannot find another factorisation for $100$ if you sort the primes.

You can think as when you have a number, it is either prime of composite. If it is a prime, you cannot decomposite it as a product of two integers by definition. While it is composite, you can find two smaller numbers as its decomposition. As the numbers always get smaller, eventually you cannot decomposite further.

**[Euclid's lemma](https://en.wikipedia.org/wiki/Euclid%27s_lemma)**

The lemma states that if a prime $p$ divides $ab$, then $p$ divides at least one of $a$ and $b$.

The same name can mean a strong corollary that if an integer $n$ divides $ab$, where $a$ is coprime with $n$ (i.e. they do not have any common factor), then $n$ divides $b$.

You can think about their prime factorisations. We say $a = p\_1 p\_2 \\cdots p\_r$ and $b = q\_1 q\_2 \\cdots q\_s$, where $p\_i$s and $q\_i$s are all primes. Then $ab = p\_1 p\_2 \\cdots p\_rq\_1 q\_2 \\cdots q\_s$. As $n$ divides $ab$, some of $p\_i$s and $q\_i$s must contribute to the factorisation of $n$. But if $a$ is coprime with $n$, they have no common factor, all contributions must be given by $b$, so $n$ divides $b$.

**Exercise**

**Problem 1**

Find a prime $p$ such that $p$, $550 - p$ and $550 + p$ are all primes.

Hint 1

Since we have 3 numbers, we use [mod](https://en.wikipedia.org/wiki/Modular_arithmetic) 3.

Hint 2

$p \\equiv p \\pmod{3}$, $550 - p \\equiv 1 - p \\pmod{3}$ and $550 + p \\equiv 1 + p \\pmod{3}$.

Hint 3

By division theorem on $p$, consider cases when $p \\equiv 0,1,2 \\pmod{3}$ respectively.

Hint 4

We can see no matter what is the remainder when $p$ is divided by $3$, exactly one of $p$, $550 - p$ and $550 + p$ is divisible by $3$.

Hint 5

So one of $p$, $550 - p$ and $550 + p$ is $3$.

Hint 6

Trying all possible cases, $p = 547$, $550 - p = 3$ and $550 + p = 997$.

**Problem 2**

Solve $6161 + a^2 = b^4$ for positive integers $a,b$.

Hint 1

$b^4 - a^2 = 6161$. We can factorise them.

Hint 2

$(b^2 - a)(b^2 + a) = 61(101)$. Note that 61 and 101 are primes.

Hint 3

They are factors of 6161, so one of the following must hold.

*   $b^2 - a = 1$ and $b^2 + a = 6161$
*   $b^2 - a = 61$ and $b^2 + a = 101$

Hint 4

Trying all cases, $(a,b) = (20,9)$.