---
title: 'Competition Mathematics 102'
date: Wed, 01 Mar 2023 07:00:00 +0000
draft: false
tags: ['Basic', 'Mathematics', 'Plane Geometry', 'Problem Solving', 'Uncategorized']
author: 'George Kwong'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/picture1-1.png?w=869'
---

From "[Competition Mathematics 101](https://wp.me/pezaVv-1U)", you may see that Competition Mathematics has approachable academic content but with a peculiar question style. But everyone with sufficient training can become a semi-supernatural being able to tackle those problems.

<!--more-->

Here is an introductory question. It is question A1 in Simon Marais Mathematics Competition 2022.

> Let _ABCD_ be a unit square, and let _P_ be a point inside triangle _ABC_. Let E and F be the points on _AB_ and _AD_, respectively, such that _AEPF_ is a rectangle. Let _x_ and _y_ denote the lengths of  _AE_ and _AF_, respectively. Determine a two-variable polynomial f(_x_,_y_) with the property that the area of _AEPF_ is greater than the area of each of the quadrilaterals _EBCP_ and _FPCD_ if and only if f(_x_,_y_) > 0.

If you find the wording weird, you are perfectly normal, and so am I! It is often useful to represent a Geometry question with a diagram.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/picture1-1.png?w=869)

Then you can see the wording describes two properties:

1.  Quadrilaterals _EBCP_ and _FPCD_ are trapeziums. Their areas can be computed by the formula you learnt before.
2.  _P_ lying inside triangle _ABC_ makes the area of _EBCP_ less than that of _FPCD_.

The question remains

> What is a two-variable polynomial f(x,y) with the property if and only if f(x,y) > 0? 

Let’s look at a similar phasing.

> Find a polynomial that _k_ is greater than _h_ if and only if that polynomial > 0.

So we have _k_ > _h_. To make the right-hand side 0, we need to have _k_ – _h_ > 0. So _k_ – _h_ is the target as it is coincidentally a polynomial. Therefore, the technique of solving this problem is literally translating the weird question phasing to inequalities. Indeed, as the area of _EBCP_ is always less than that of _FPCD_, we have

$\\displaystyle \\begin{aligned} && \\text{The area of }AEPF &> \\text{The area of }FPCD \\\\ \\Leftrightarrow && xy &> \\frac {(1-y)(1+x)} 2 \\\\ \\Leftrightarrow && 2xy &> (1-y)(1+x) \\\\ \\Leftrightarrow && 2xy &> 1 + x - y - xy \\\\ \\Leftrightarrow && 3xy - x + y - 1 &> 0 \\\\ \\end{aligned}$

So we have $f(x,y) = 3xy - x + y - 1$.

You may still wonder the following. Let me explain them one by one.

1.  Two-variable:  
    You already have x and y, so you cannot introduce a third variable.
2.  Polynomial:  
    A polynomial means you can just have some real numbers and variables, and then add, subtract and multiply them together. Here, the term does not make the question more difficult. However, if you get something such as $\\sqrt {x + y} - \\sqrt z > 0$, then you need to make it becomes $\\sqrt {x + y} > \\sqrt z \\Leftrightarrow x + y > z \\Leftrightarrow x + y - z > 0$.
3.  Property:  
    It means some conditions. But you are solving a mathematics problem so you have some conditions. This term is conceptually useless here.
4.  If and only if:  
    It means you need to have a necessary and sufficient condition. You need to go through some chapters in logic and arguments in Mathematics courses in order to fully understand it. Now, you can treat “A if and only if B” as “if A then B” and “if B then A”. For example, water boils if and only if the water reaches its boiling point.

You may feel that sometimes the difficulty of Competition Mathematics is not the content. I am sure you can do this problem if it is phrased as “Find an inequality in _x_ and _y_ makes the area of _AEPF_ greater than the area of each of the quadrilaterals _EBCP_ and _FPCD_”.

To practice, please do this simple arithmetic problem. You may see similar questions in high-school Mathematics Competition, but it is helpful for beginners to understand the thinking process in competition.

Calculate the value of

$\\displaystyle \\sum\_{k = 1}^{2023} \\left\[ \\sqrt k \\right\] = \\left\[ \\sqrt 1 \\right\] + \\left\[ \\sqrt 2 \\right\] + \\left\[ \\sqrt 3 \\right\] + \\cdots + \\left\[ \\sqrt {2023} \\right\] $

where \[_x_\] is the floor function, i.e. the largest integer smaller or equal to _x_. For example, \[1\] = 1, \[3.2\] = 3, \[– 4\] = – 4 and \[– 4.3\] = – 5.

Here are some hints if you really need them.

1.  Prove by [induction](https://en.wikipedia.org/wiki/Mathematical_induction) (in most competitions, the result is too standard, so you do not need to prove it. However, for beginners, it is a good basic exercise.)
    
    $\\displaystyle \\sum\_{p = 1}^{s} p^2 = 1^2 + 2^2 + 3^2 + \\cdots + s^2 = \\frac {s(s+1)(2s+1)} 6$.
    
2.  For a given positive integer _p_, solve, for x,
    
    $p \\leq \\sqrt x < p +1$.
    
      
    Answer:
    
    It is
    
    $p^2 \\leq x \\leq p^2 + 2p$
    
3.  How many of k makes:
    
    $\\left\[ \\sqrt k \\right\] = p$?
    
4.  Expand p(2p+1).
    
5.  Note that:
    
    $\\sqrt{2025} = 45$
    
6.  The answer is:
    
    59686