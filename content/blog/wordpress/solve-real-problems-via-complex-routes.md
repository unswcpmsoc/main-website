---
title: 'Solve Real Problems via Complex Routes'
date: Sat, 01 Jul 2023 04:13:40 +0000
draft: false
tags: ['Complex Number', 'Mathematics', 'Plane Geometry', 'Uncategorized']
author: 'George Kwong'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture8.png?w=1024'
---

What I mean is to add an extra dimension. But why make the problem in real numbers more complex? One way to solve a problem is by changing your perspective. <!--more--> Before we go into the details, let's consider the Launch Week Problem for term 2, 2023.

> 2 balls are placed on a flat ground. A boy observes them in the front and sees two intersecting circles,which give 2 intersecting points in his view. He now imagines a line passing through those 2 points. Where does the line intersect with the ground in his view?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture8.png?w=1024)

Can you see that this question is nothing related to 3D space? It is only about projection. The projection (the view from the boy) is shown below.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture9.png?w=717)

Then by the [Tangent-secant theorem](https://en.wikipedia.org/wiki/Tangent%E2%80%93secant_theorem), $CE^2 = (AE)(BE) = DE^2$. So $E$ is the midpoint of $CD$.

Sometimes solving a problem in a reverse direction of the above may also work, i.e. adding another dimension. A neat example would be [Monge's Circle Theorem](https://mathworld.wolfram.com/MongesCircleTheorem.html).

![](https://upload.wikimedia.org/wikipedia/commons/b/b0/Monge_theorem.svg)

Monge theorem.svg from [Wikimedia Commons](https://commons.wikimedia.org/wiki/File:Monge_theorem.svg)

Monge's Circle Theorem states the following. For three circles of different sizes, each circle pair induces two outer tangents. The 3 corresponding intersection points of the 3 pairs of tangents are colinear. To prove it, we can consider 3 spheres of different sizes on the ground. Easy to imagine there is a unique plane tangent to all 3 spheres. This tangent plane cuts the ground in a straight line. Call it $L$. Also, it is easy to imagine that there is a unique cone circumscribing each pair of 2 spheres. Note that all 3 cones lie on the ground and are tangent to the tangent plane of those 3 spheres. It means the tips of all 3 cones lie on $L$ too. The result follows. Here is a visual aid.

https://www.youtube.com/watch?v=LE3gQKeIyLM

The case of real numbers is the same. Sometimes it is better to introduce complex numbers to solve the problem.

**Example 1**

Given integers $a,b,c,d$. Find integers $x,y$ such that $x^2 + y^2 = (a^2 + b^2)(c^2 + d^2)$.

You can do it by expanding the right-handed side and factorising it, but it is tedious. Let's think about complex numbers. Can you see that $a^2 + b^2$ is the magnitude of $a + bi$?. So we let $z\_1 = a + bi, z\_2 = c + di$. Then $z\_1z\_2 = (ac - bd) + (ad + bc)i$. Note that magnitude of $z\_1z\_2$ is the product of the magnitudes of $z\_1$ and $z\_2$. So we have $x^2 + y^2$ equal the magnitude of $z\_1z\_2$. Hence, $x^2 + y^2 = (a^2 + b^2)(c^2 + d^2) = (ac - bd)^2 + (ad + bc)^2$.

**Example 2**

Find the following sums. (Sum of all binomial coefficients of "$mn$ choose $mk$" for $k = 0, \\ldots, n$. Find the sum of each of $m = 2, 3, 4$.)

1.  $\\displaystyle  \\binom {2n} {0} +  \\binom {2n} {2} +\\binom {2n} {4} + \\cdots +  \\binom {2n} {2n}$
2.  $\\displaystyle  \\binom {4n} {0} + \\binom {4n} {4} + \\binom {4n}{8} + \\cdots + \\binom {4n} {4n}$
3.  $\\displaystyle \\binom {3n} {0} + \\binom {3n} {3} + \\binom{3n}{6} + \\cdots + \\binom {3n} {3n}$

For the first one, the standard way is to consider the expansion of $(1 + x)^{2n}$, that is

$\\displaystyle (1 + x)^{2n} =  \\binom {2n} {0} +  \\binom{2n} {1} x+  \\binom{2n} {2} x^2+  \\binom{2n} {3} x^3 + \\binom {2n} {4} x^4+ \\cdots + \\binom{2n}{2n} x^{2n}$.

Then by putting $x = 1$ and $x = -1$ respectively, we have

$\\displaystyle (1 + 1)^{2n} =  \\binom{2n} {0} +  \\binom{2n} {1} +  \\binom{2n} {2}+  \\binom{2n} {3} + \\binom{2n} {4} + \\cdots + \\binom{2n}{2n}$,

$\\displaystyle (1 -1)^{2n} =  \\binom{2n} {0} -  \\binom{2n} {1}+  \\binom{2n} {2}-  \\binom{2n} {3} + \\binom{2n} {4} + \\cdots + \\binom{2n}{2n}$ .

Adding two equations, we get $\\displaystyle  \\binom{2n} {0} + \\binom{2n} {2} + \\binom{2n} {4} + \\cdots +  \\binom{2n}{2n} = 2^{2n-1}$ .

The second sum can be found by further substituting $x = \\pm i$ (but into the expansion of $(1+x)^{4n}$). But why? it is because $x^4 + 1 = 0$ has roots $\\pm 1, \\pm i$. You should get the sum $2^{4n-2}$.

So you may think the third sum is related to roots of $x^3 + 1 = 0$. Yes! You are right. Try to solve it by substituting $x = 1, e^{\\frac {2\\pi} {3} i}, e^{\\frac {4\\pi} {3} i}$ into the expansion of $(1+x)^{3n}$. You should get the sum $\\frac {2^{3n-1} - 1}{3}$. You may need the fact that $1 + e^{\\frac {2\\pi} {3} i} + e^{\\frac {4\\pi} {3} i} = 0$. (Why?)

You may ask why it works. How to find the remainder (as we only need every 2/3/4 terms) using geometry? Rotation! Turning 361 degrees is the same as turning 1 degree. And the polar form of complex numbers $e^{i \\theta}$ means a rotation.

**Example 3** (Putnam 1991, B2)

Suppose $f$ and $g$ are non-constant, differentiable, real-valued functions on $\\mathbf{R}$. Furthermore, suppose that for each pair of real numbers $x$ and $y$,

$\\displaystyle \\begin{aligned} f(x + y) &= f(x) f(y) - g(x) g(y) \\\\ g(x + y) &= f(x) g(y) + g(x) f(y) \\end{aligned}$

If $f'(0) = 0$, prove that $(f(x))^2 + (g(x))^2 = 1$ for all $x$.  
  
Observe $(a + bi)(c + di)= (ac - bd) + (ad + bc)i$. We let $h(x) = f(x) + g(x) i$. Then $h(x) = f(x +y ) + g(x +y) i = (f(x) f(y) - g(x) g(y)) + (f(x) g(y) + g(x) f(y))i$. So using the observation in the first sentence, we have $h(x +y ) = (f(x) + g(x)i)(f(y) + g(y)i) = h(x)h(y)$.

This famous functional equation $h(x +y ) = h(x)h(y)$ has the solution $h(x) = Ae^{Cx}$ for constant $A, C$. One way to see this is by taking the logarithm for the original equation and using the result of **Problem 1(a)** from [here](https://unswcpmsoc.blog/2023/05/30/when-to-use-induction/). Putting $x = y = 0$ into $h(x +y ) = h(x)h(y)$, we have $h(0) = 1$. Putting $x = 0$ into $h(x) = Ae^{Cx}$, we get $A = 1$. So $(f(x))^2 + (g(x))^2 = |h(x)| = 1$.

You may think that Complex Numbers are more complete than Real Numbers, so sometimes it is necessary to include them to solve a problem. One example is the [Fundamental Theorem of Algebra](https://en.wikipedia.org/wiki/Fundamental_theorem_of_algebra). You can only guarantee $n$ roots for a degree $n$ polynomial (also consider the multiplicity) for complex numbers but not real numbers. There are many more examples. For example, calculate $\\displaystyle \\int\_0^{\\infty} \\frac {\\text{d}x} {x^4 + 1}$ by [Residue theorem](https://en.wikipedia.org/wiki/Residue_theorem) and [contour integration](https://en.wikipedia.org/wiki/Contour_integration). However, it is rather a question of Complex Analysis than Competition Mathematics. Readers can explore these techniques by themselves.