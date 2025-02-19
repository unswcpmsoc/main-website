---
title: 'Taylor Polynomials of Degree 1 and Degree 2'
date: Mon, 24 Apr 2023 12:16:12 +0000
draft: false
tags: ['Calculus', 'Mathematics', 'Polynomials', 'Uncategorized']
author: 'Ilha Jung'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/deg-1-2.png?w=565'
---

Throughout our first-year ventures as science, actuarial or engineering students we often come across the concept of the Taylor Series. <!--more--> As mathematicians and statisticians, we can use Taylor Series to approximate complicated or at times 'ugly' functions at any point, given that the starting function is differentiable at every point (technically they are called [analytic functions](https://en.wikipedia.org/wiki/Analytic_function), but usually we use this term only in Complex Analysis).

Contrary to the Fourier Series which approximates periodic functions using the sum of more simple periodic functions, the Taylor Series is able to approximate functions using polynomials.

First, let's have a look at Taylor polynomials in the one-dimensional space starting with Taylor's Theorem:

Suppose that $f$ is a continuous and $(k+1)$ times differentiable at a point centred at a real number '$a$'. Then,

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/taylor-theorem-3.png?w=850)

Note that the centred point '$a$' is selected from the domain so that the Taylor Series will converge and that the $k$th\-order Taylor polynomial of $f$ centred at '$a$' is the polynomial of degree $k$.

For example, the Taylor polynomial of 'degree 1' and of 'degree 2' are respectively:

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/deg-1-2.png?w=565)

Now we will look at some problems where we find an approximation of suitable functions to Taylor polynomials of degree 1 or 2 centred at a point.

**PROBLEM 1**

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/taylor-problem-1-2.png?w=601)

Using Taylor Theorem and the 'degree 1' formula as demonstrated above, we find that

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/taylor-problem-1-4.png?w=349)

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/answer-taylor-1.png?w=532)

Sometimes the 'degree 1' Taylor polynomial is referred to as the linear approximation of f for x centred at 'a'. Likewise, the 'degree 2' Taylor polynomial is a quadratic approximation.

Now we have an understanding of how Taylor polynomials are constructed from the Taylor Series, let's see how we can apply the same principles to a multidimensional set of real numbers. For this stage, we will require knowledge of partial derivatives.

Suppose that the function $f: \\mathrm{R}^2 \\rightarrow \\mathrm{R}$ is of class $C^2$. Or in plain words, we are considering a suitably continuous, twice-differentiable function with two real numbers as its input. Then the quadratic Taylor polynomial can be expressed as the following.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/multivar-poly-2-deg.png?w=822)

Now we will apply the above to solve the following problem.

**PROBLEM 2 (from 2023 T1 MATH2111 Online Quiz 2)**

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/taylor-problem-2.png?w=934)

We first want to evaluate all the partial derivatives. To allow a cohesive working space, we will use a table for the starting function and its partial derivatives up to order 2, then find their corresponding value at the centred point.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/table-of-partial-der.png?w=735)

Now, by substituting we resolve to the following answer.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/04/answer-taylor-2.png?w=772)

But can we use it in more exciting problems? Yes! Let's see problem A1 from Putnam 2002.

**PROBLEM 3 (**from Putnam 2002**** -**Problem A1)**

Let $k$ be a fixed positive integer. The $n$th derivative of $\\displaystyle \\frac {1} {x^k - 1}$ has the form $\\displaystyle \\frac{P\_n(x)}{(x^k - 1)^{n+1}}$, where $P\_n(x)$ is a polynomial. Find $P\_n(1)$.

I think it is quite easy to just differentiate it $n$ times and see the pattern. However, I would like to use Taylor polynomials. Do you have any ideas? Do you remember you also learnt some series in high school?

$\\displaystyle \\frac {1}{1-r} = 1 + r + r^2 + \\cdots \\text{ for } |r| < 1$

$\\displaystyle (1 + x)^n = 1 + nx + \\frac{n(n-1)}{2}x^2 + \\cdots$

The first one is the geometric sum. The second one is the binomial theorem.

But why can't we use a geometric sum? It is because the question is asking you $P\_n(1)$, but 1 is not less than 1. (It is due to the fact that a geometric series only converge for values near 0.) So we can use the binomial theorem. To fit it into the form of a Taylor polynomial, we need terms like $(x-1)$ and $(x-1)^2$. Also, as we are finding $P\_n(1)$, terms like $(x-1)$ at the end will become 0 at the end, we just need the most significant terms. i.e. constant term and linear term.

Observe that $\\displaystyle x^k - 1 = -1 + (1 + (x - 1))^k = -1 + 1 + k(x-1) + \\cdots = k(x-1) + \\cdots $, so $\\displaystyle \\frac{1}{x^k - 1} = \\frac{1} {k(x-1) + \\cdots} \\approx \\frac{1} {k(x-1)} = \\frac{1}{k} (x-1)^{-1}$. Then we can easily differentiate it now and get $\\displaystyle \\frac{\\text{d}^n}{\\text{d}x^n}\\frac{1}{x^k - 1} \\approx \\frac{(-1)(-2)\\cdots(-n)}{k} (x-1)^{-(n+1)} = \\frac{(-1)^n n!}{k} (x-1)^{-(n+1)}$.

Using the hint that the $n$th derivative of $\\displaystyle \\frac {1} {x^k - 1}$ has the form $\\displaystyle \\frac{P\_n(x)}{(x^k - 1)^{n+1}}$, we now have $\\displaystyle P\_n(x) \\approx (x^k - 1)^{n+1}\\frac{(-1)^n n!}{k} (x-1)^{-(n+1)}$. Using the binomial theorem again, $\\displaystyle P\_n(x) \\approx (-1 + (1 + (x - 1))^k)^{n+1}\\frac{(-1)^n n!}{k} (x-1)^{-(n+1)}$. Simplifing, $\\displaystyle P\_n(x) \\approx (k(x-1))^{n+1} \\frac{(-1)^n n!}{k} (x-1)^{-(n+1)} = (-k)^nn!$.

Therefore, $P\_n(1) = (-k)^nn!$.  

This concludes the article on Taylor polynomials. Further research can be undertaken for those who are interested in proofs and general formulas involving multivariable calculus as well as complex analysis. Some enriching topics include the Hessian Matrix and the Jacobian Matrix. Also, Taylor polynomials are related to power series, which is another powerful tool for many applications. This is a future topic to be discussed.