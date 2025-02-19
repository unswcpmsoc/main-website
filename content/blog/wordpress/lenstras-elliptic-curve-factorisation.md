---
title: 'Lenstra''s elliptic curve factorisation'
date: Sun, 05 Mar 2023 03:58:58 +0000
draft: false
tags: ['Mathematics', 'Number Theory', 'Uncategorized']
author: 'Cyril Subramanian'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/image-1.png?w=300'
---

A factor of a positive integer $n$ is another positive integer which divides $n$. A relatively simple concept, yet one that has fascinated and tormented mathematicians for centuries. How can we quickly factorise a number?

<!--more-->

One practical method is trial division: given an integer $n$ we want to factorise, we loop from $2$ to $n$ and repeatedly check if its a factor: if so, we divide $n$ by the number as many times as possible, add it to our list of factors and continue. In the worst case, we must search every number up to $n$ (if $n$ is prime): this can be improved by only checking numbers up to $\sqrt n$ (an exercise for the reader!).

There are other deterministic methods for factorising integers (i.e. ones which will definitely return all factors within a finite amount of time). However, there are also probabilistic methods for computing factors which, although do not guarantee factors, generally fare much better than deterministic ones as they are much likelier to return factors.

Let's take a look at Fermat's little theorem for a moment: it states that for any prime $p$ and integer $a$ which is not a multiple of $p$, $a^{p-1} \equiv 1 \pmod p$ (check out CPMSoc's [number theory workshop slides](https://www.unswcpmsoc.com/assets/workshops/mathematics/2023/Number_Theory_workshop.pdf) to see a proof of this!). Further note that for any integer $K$, $a^{K(p-1)} = (a^{p-1})^K \equiv 1^K = 1 \pmod p$.

Our goal now is to somehow generate an integer $v$ which is a multiple of $p - 1$ for some prime factor $p$, so that we can guarantee $a^v - 1 \equiv 0 \pmod p$. We can then use the Euclidean algorithm to find a common divisor between $a^v - 1$ and $n$ (this was also covered in CPMSoc's number theory workshop), and thus generate a factor! One important requirement is that $a^v - 1$ should not be divisible by _all_ of the prime factors, otherwise $\gcd(a^v - 1, n) = n,$ which is not new information. Something to be aware of is that some integers $a$ can result in $a^v - 1$ being a multiple of a prime $p$ even though $v$ is _not_ a multiple of $p - 1$. This is OK, and in fact means we can return a factor even earlier if we find such a $v$! A practical implementation of this is shown below in Python:

```
from math import gcd
import random
import sympy

# WLOG we want factorise to return a nontrivial
# factor of n (we then recursively call factorise
# on this number)
def factorise(n):
    if n == 1 or sympy.isprime(n):
        return \[n\]
    while True:
        a = random.randint(2, n - 1)
        g = gcd(a, n)
        if g != 1: # we've already found a factor of n
            return factorise(g) + factorise(n // g)

        x = a
        # our v is generated with a factorial
        # i.e. we check gcd(a\*\*(b!) - 1, n)
        for b in range(2, n):
            a = pow(a, b, n) # exponentiation to factorial (mod n)
            common\_divisor = gcd(a - 1, n)
            if common\_divisor == n: # bad value of a, or another issue...
                break
            elif common\_divisor != 1: # found factor of n
                return factorise(common\_divisor) + factorise(n // common\_divisor)
        else:
            return \[n\]
    
n = int(input("Enter your number: "))
print(f"Factors of {n}: {factorise(n)}")
```

This is Pollard's p - 1 algorithm (most implementations, however, limit the factorial up to a certain integer, called the "smoothness bound"). There are some issues, however. For one, because we generate $v$ with a factorial, there are some annoyances: for integers $n$ where, for each prime factor $p$, all $p - 1$ have the same largest prime factor, call this $b$, then when $v = b!$, $\gcd(a^v - 1, n) = n$, making it a lot less likely for a $\gcd$ not equal to $n$ to be achieved earlier. A more prominent issue concerns time complexity: for integers $n$ where the largest prime factor of $p - 1$ is not easily attainable via a factorial, this algorithm takes too long to generate an appropriate $v$. Perhaps we can find a structure different to exponentiation?

Well it turns out considering finite elliptic curves helps us! Elliptic curves are equations of the form $y^2 = x^3 + ax + b$, and finite elliptic curves are such equations but studied under a modulus.

Before we get into the maths, I'll explain why using elliptic curves is better than traditional exponentiation: we are about to define a notion of addition in the elliptic curve's space of solutions, which will cyclically generate new elements. Importantly, while the size of the cycle for exponentiation was, at most, $p - 1$, the maximum size of this cycle on an elliptic curve varies seemingly randomly between $p + 1 - 2\sqrt p$ and $p + 1 + 2\sqrt p$ (this is known as the Hasse-Weil bound). This means that its running time is _not tied down by the largest prime factor of a single number_ (Pollard's algorithm was tied down by ${p-1}$'s largest prime factor).

Elliptic curve addition of two points (in the continuous case) is defined by forming a line between the two, finding the third point of intersection and reflecting the point across the x-axis (the new point is the result of the addition, and will always be on the elliptic curve). If the same point is added to itself, then we consider the tangent line. Note that if a vertical line is generated, then the resulting point is defined as "infinity". An example of this is shown below:

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/image-1.png?w=300)

Finite elliptic curve point addition involves the same numerical calculations, but calculated under $\pmod n$, with division defined as multiplication by the divisor's inverse. Now we are ready. We pick a random elliptic curve under $\pmod n$ and a point on it by picking random integers $x\_0, y\_0$ and $a$, and setting $b = y\_0^2 - x\_0^3 - a$. Then, for increasing values of $b$, we calculate the point addition of $(x\_0, y\_0)$ with itself $b!$ times (this can be done efficiently by adding the previously calculated value $b$ times). In this process, if we ever get an infinity point, we must've performed modular division with a value $d$ where $\gcd(d, n) \ne 1$, as this is the only scenario where a unique inverse does not exist, in which case we can stop early since we've already found a factor of $n$.

In fact, we _must_ eventually pass an infinity point! If we repeatedly point-add $(x\_0, y\_0)$, then, for some prime factor $p$, under $\pmod p$ there are only a finite number of values, so we will form a cycle and eventually loop back to our starting point. Note that the last value in this cycle (before it loops around) must be the identity element of the elliptic curve, which is the infinity point, since this is the only one which results in $(x\_0, y\_0)$ when point-added to $(x\_0, y\_0)$. Thus, if the $b!$ we generate becomes a multiple of some of the $\pmod p$ point-addition cycle lengths, then the repeated addition of $(x\_0, y\_0)$ $b!$ times must be the infinity point! Realise that this algorithm is essentially just an improved version of Pollard's $p - 1$ algorithm, using a different structure (elliptic curves) but the same principle (systematically trying to create multiples of only some of the prime factors of $n$).

Note that instead of calculating factorials all the way up to $n - 1$, we calculate them up to a smaller "smoothness" bound $B$, and randomly choose another curve and point on it if we don't get to an infinity point. This is so we can actually exploit the seemingly random variance of elliptic curves' cycle lengths.

Congratulations, you've discovered Lenstra's Elliptic Curve Method for factorisation, the third fastest in the world! Only required a bit of number theory, right?