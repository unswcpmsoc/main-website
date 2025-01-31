---
title: 'Distributions: Probability and Beyond'
date: Tue, 04 Apr 2023 02:01:00 +0000
draft: false
tags: ['Mathematics', 'Probability', 'Uncategorized']
author: 'Zac Petersen'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/example-1.png?w=814'
---

Often in introductions to probability and statistics, we deal with random variables, which take on random values according to some specific "probability distribution". <!--more--> When we do this, it is common to differentiate between discrete random variables, which can take on a countable (#1, see below) or even just a finite number of values, and a continuous random variable, which may take on an uncountable (#1, see below) number of values.

For example, flipping a coin has a finite number of outcomes, so it is discrete, whereas the distance travelled when I throw a ball can take on a continuum of real values, which are uncountable. If we measure the exact distance travelled, any particular distance, say 10 m has a 0 probability of occurring, as the ball could always be slightly off from this value. Naively, as the probability of getting exactly 10 m is infinitely small, we write the probability as 0. But of course, the ball must land somewhere, so how do we quantify probabilities usefully here? We instead must consider a range of values. For example, we may have that the probability of landing between 10 m and 20 m is 50%, even if any particular value in that range has zero probability. Basically, for continuous variables, as there must be some (measurement) error, we can only have a positive probability for a range of values. Let's abstract these concepts.

We construct cumulative distribution functions (CDFs), which tell us $P(X\\le z)$, the probability of $X$ less than $z$. Notice that the sum of probabilities is still 1 and every bit of probability is non-negative.Mathematically, $P(X\\le \\infty)=1$, $P(X\\le -\\infty)=0$, $P(X\\le z)\\ge0$, and $z<w \\implies P(X\\le z) < P(X\\le w)$. i.e. the CDF is a non-negative increasing function, where the output value starts from 0 and goes to 1.

**Example 1.** The CDF for flipping a fair coin, calling tails 0 and heads 1. (plotted using Desmos)

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/example-1.png?w=814)

**Example 2.** A potential CDF for a continuous random variable.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/example-2.png?w=844)

**Example 3.** A more complicated CDF, where there is a 50% chance of getting 1.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/03/example-3.png?w=821)

For discrete variables, we have the probability function $P(X=z)$. A similar function, the probability density function, applies to continuous variables. This is a function $f:\\mathbb{R}\\rightarrow \\mathbb{R}$ such that $\\int\_{a}^{b}f(x)dx=P(a<X<b)$. This is a nice function to discuss, as $f(x)$ describes roughly the probability of being "near" some value rather than exactly at that value, which was the issue we had before. With some manipulation, we find that $\\int\_{-\\infty}^{z}f(x)dx=P(X\\le z)$, so $f(z)=\\frac{d}{dz}P(X\\le z)$. But here there is a problem, as the properties of $P(X\\le z)$ in no way guarantee differentiability! Notice in example 2 above there are 2 non-differentiable points at 0 and 1. Because the function is continuous here, we can deduce that there is a zero probability of getting a 0 or 1, so in fact we can ignore these points completely (as an integral is unaffected by changing a value at a single point). Difficulties arise in examples 1 and 3 where we have discontinuities, because on the one hand, these points are non-differentiable, but there is definitely significant probability density here, as in example 1 each non-differentiable point makes up a 50% probability in total, so what should seem like an infinite probability density. We notice this 50% is given by the size of the discontinuous jump from 0 to 0.5 at $x=0$ and then 0.5 to 1 at $x=1$. We want in this case some kind of $f(z)$ so that $\\int\_{-\\infty}^{x}f(z)dz$ gives the curve from example 1. Using these properties of differentiation, we find that there is no such function. But, as in many beginnings of mathematical concepts, non-existence need not stop us! Engineers and physicists find application for a "function" $\\delta$ called the Dirac-delta function, named after Paul Dirac, defined such that $\\int\_{-\\infty}^{\\infty}\\delta(z)dz = 1$, and is zero everywhere but at $z=0$. Of course, no such function exists, as there is no nice output at zero to define this integral over, but the algebra works nicely regardless. Rearranging as before, we see that this delta gives us an effective derivative for discontinuous jumps, and we find that the density function for example 1, which we may now more accurately term a "distribution", as it is not really a function as we know it, may be given by $\\delta(x)/2+\\delta(x-1)/2$. If this seems confusing (which it probably should), it might be worthwhile to get out pencil and paper and integrate $\\delta(x)/2+\\delta(x-1)/2$ to see that we do indeed get out the CDF from example 1. A key property, which the reader should justify, is shown below.

  
$\\int\_{-\\infty}^{\\infty}\\delta(t-a)f(t)dt=f(a)$

This form is called the "sifting property".  
This property turns out to be incredibly useful beyond just statistics and probability, for example in signal processing, where theoretical signals can be constructed from any nice function, combined with both delta distributions, and derivatives of delta distributions, to represent the limiting behaviour of large spikes or "impulses" in signals. Derivatives of the delta distribution give the property

  
$f(x)\\frac{d}{dx}\\delta(x)=-f'(x)\\delta(x).$

A very suspect, but somewhat intuitive explanation for why this property is practically acceptable is described below. (Assume you are familiar with the properties of differentiation and delta function. You can take a look at those.)

$\\displaystyle\\begin{aligned} & f(x)\\frac{d}{dx}\\delta(x) \\\\ = & f(x) \\lim\_{h\\to0} \\frac{\\delta(x+h)-\\delta(x)}{h} \\\\ = & \\lim\_{h\\to0} \\frac{f(x)\\delta(x+h)-f(x)\\delta(x)}{h} \\\\ = & \\lim\_{h\\to0} \\frac{f(x)\\delta(x+h)-f(x+h)\\delta(x+h)}{h} \\\\ = &\\lim\_{h\\to0} \\frac{-f(x+h)\\delta(x)+f(x)\\delta(x)}{h} \\\\ =& -\\delta(x) \\lim\_{h\\to0} \\frac{f(x+h)-f(x)}{h} \\\\ = &-f'(x)\\delta(x). \\end{aligned}$

It should feel somewhat strange that these objects appear so well-behaved, but they only do when used appropriately, and issues arise when treating them as regular functions quite often. Their nice behaviour arises from the fact that when taking products of functions and integrating, as in $\\int\_{-\\infty}^{\\infty}f(x)g(x)dx$, this operation is linear with the respect to $g(x)$. That is to say, the following properties hold:

  
$\\int\_{-\\infty}^{\\infty}f(x)(ag(x))dx=a\\int\_{-\\infty}^{\\infty}f(x)g(x)dx$  
$\\int\_{-\\infty}^{\\infty}f(x)(h(x) + g(x))dx=\\int\_{-\\infty}^{\\infty}f(x)h(x)dx + \\int\_{-\\infty}^{\\infty}f(x)g(x)dx$

And these properties also hold when simply selecting (sifting) values of a function, or its derivatives. Both these processes (integration and selection) are then called linear functionals, as they are linear, and take in functions to give out real values. The delta distribution is a nice way to represent other linear functionals as if they fell under the same roof as linear functionals that can be represented through this integration process.  
**Problem 1.** Represent $f(x)\\frac{d^n}{dx^n}\\delta(x)$ in terms of $\\delta(x)$ and derivatives of $f(x)$.  
**Problem 2.** Practically, what is an example of a random process which results in a cumulative distribution function like that in example 3? For the process you choose, find its probability distribution in terms of real functions and delta distributions.  
**Explore.** Can an object similar to $\\delta(x)$ be used to make multivariate function discontinuities act differentiable?

Note:

#1: Countable vs Uncountable: Here we are doing Mathematics. We say a set (or a "list" of things) is countable if it is finite or has a bijection to the set of natural numbers. Naively, it means the set has a "size" at most the size of the set of natural numbers/integers/rational numbers. Otherwise, we call them uncountable. Why the set of real numbers is uncountable relates to the famous diagonal argument.